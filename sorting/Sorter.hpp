#ifndef SORTER_HPP
#define SORTER_HPP

#include <vector>
#include <queue>

// A class for sorting!
// You will finish this for project 4
// Yay
// All of the sorts will take a std::vector<int> and return a sorted std::vector<int>
struct Sorter {

    // sort a vector using bubble sort
    static std::vector<int> bubblesort(const std::vector<int>&);

    // sort a vector using insertion sort
    static std::vector<int> insertionsort(const std::vector<int>&);

    // sort a vector using radix sort
    static std::vector<int> radixsort(const std::vector<int>&);

    // sort a vector using quicksort
    static std::vector<int> quicksort(const std::vector<int>&);

    // sort a vector using mergesort
    static std::vector<int> mergesort(const std::vector<int>&);

    // helper function for merge sort(merges two sorted vectors)
    static std::vector<int> merger(std::vector<int>&, std::vector<int>&);

    // swap two elements location in a vector
    static void swap(int[], int, int);

    // partition an array for quicksort
    static int partition(int[], int, int);

    // recursive quicksort function
    static void quicksort_recursive(int[], int, int);
};

std::vector<int> Sorter::bubblesort(const std::vector<int>& vec) {
    //return vector
    std::vector<int> ret;

    //if vector sent is empty, nothing needs sorted, return the empty vector
    if(vec.size() <= 1){
        return vec;

    }else{
        //declare an array of integers and store the sent vectors contents to sort with
        int numbers[vec.size()];
        for(int x = 0; x < vec.size(); x++)
            numbers[x] = vec[x];

        //for each element in the array start at that position and
        //move further, checking each element against it and making swaps if needed.
        for(int j = 0; j < vec.size(); j++){
            for(int i = 0; i < vec.size() - 1; i++){
                if(numbers[i] > numbers[i+1]){
                    int temp = numbers[i+1];
                    numbers[i+1] = numbers[i];
                    numbers[i] = temp;
                }
            }
        }

        //Put the contents of the sorted array into the return vector
        for(int z = 0; z < vec.size(); z++){
            ret.push_back(numbers[z]);
        }

        //return the new sorted vector
        return ret;
    }
}

std::vector<int> Sorter::insertionsort(const std::vector<int>& vec) {
    //return vector
    std::vector<int> ret;

    //if vector sent is empty, nothing needs sorted, return the empty vector
    if(vec.size() <= 1){
        return vec;

    }else{
        //declare an array of integers and store the sent vectors contents to sort with
        int numbers[vec.size()];
        for(int x = 0; x < vec.size(); x++)
            numbers[x] = vec[x];

        //for each element in the array, start at the beginning and check
        //that number against each other number, swapping when needed and then start again
        //at the next element in the array.
        for(int i = 0; i < vec.size(); i++){
            for(int j = i; j > 0 && numbers[j] < numbers[j-1]; j--){
                int temp = numbers[j-1];
                numbers[j-1] = numbers[j];
                numbers[j] = temp;
            }
        }
        //put the contents of the sorted array into the return vector
        for(int z = 0; z < vec.size(); z++){
            ret.push_back(numbers[z]);
        }

        //return the new sorted vector
        return ret;
    }
}

std::vector<int> Sorter::radixsort(const std::vector<int>& vec) {

  // our main queue that will be turned into a vector at the end
  // also temporary storage as we move along the digits
  std::queue<int> main_queue;

  // see if the vector is empty
  if (vec.size() > 0) {

    // fill our main queue with the numbers in the vector
    // also find the largest value in the vector
    int largest = vec[0];
    for (int i = 0; i < vec.size(); ++i) {
      main_queue.push(vec[i]);
      largest = largest < vec[i] ? vec[i] : largest;
    }

    // compute the number of digits in the largest value
    int digits = 0;
    do {
      largest /= 10;
      ++digits;
    } while (largest != 0);

    // we need an array of queues for our buckets
    std::queue<int> buckets[10];

    //set a variable to hold the denominator
    int den = 1;

    // evaluate each digit for each number in the main_queue and put them
    // in the correct bucket for that digit's value
    for (int i = 0; i < digits; ++i) {
      // while the main queue has elements in it
      while(main_queue.size() > 0) {
	// store the number for storage later
	int temp = main_queue.front();
	main_queue.pop();
	// store the temp in the correct bucket
	buckets[(temp / den) % 10].push(temp);
      }

      // for each bucket
      for (int j = 0; j < 10; ++j) {
	// while there is something in the bucket
	while (buckets[j].size() > 0) {
	  // enqueue the value into our main queue
	  main_queue.push(buckets[j].front());
	  buckets[j].pop();
	}
      }

      // adjust the denominator for digit lookup later
      den *= 10;
    }
  }

  // move the sorted main queue into the return vector
  std::vector<int> ret;
  while(main_queue.size() > 0) {
    ret.push_back(main_queue.front());
    main_queue.pop();
  }
  return ret;
}


//helper function for recursive quicksort function
std::vector<int> Sorter::quicksort(const std::vector<int>& vec) {
    //return vector
    std::vector<int> ret;

    //if vector is size 0 or 1 it is sorted already
    if(vec.size() <= 1)
        return vec;

    //otherwise sort
    else{
        //int array for sorting
        int numbers[vec.size()];

        //fill integer array with contents of vector
        for(int x = 0; x <= vec.size() - 1; x++)
            numbers[x] = vec[x];

        //call to recursive function
        quicksort_recursive(numbers, 0, vec.size() - 1);

        //fill return vector with sorted array
        for(int x = 0; x <= vec.size() - 1; x++)
            ret.push_back(numbers[x]);

        //return sorted vector
        return ret;
    }
}

//recursive function to quicksort an array
void Sorter::quicksort_recursive(int numbers[], int start, int end) {
    //base case and recursive case
    if(start < end){
        int p = partition(numbers, start, end);
        quicksort_recursive(numbers, start, p-1);
        quicksort_recursive(numbers, p+1, end);
    }
}

//function to swap two elements in an array
void Sorter::swap(int numbers[], int a, int b) {
    int t;
    t = numbers[a];
    numbers[a] = numbers[b];
    numbers[b] = t;
}

//partition the array
int Sorter::partition(int numbers[], int start, int end) {
    //piv and partition index
    int piv = numbers[end];
    int p = start;

    //for each element between start and end index
    for(int x = start; x < end; x++){
        //if element is less than the pivot element
        if(numbers[x] <= piv){
            //and if not swapping with self
            if(p != x)
                //swap
                swap(numbers, x, p);
            p++;
        }
    }
    //if partition index didn't loop to end index
    if(p != end)
        //swap end with partition index
        swap(numbers, p, end);

    //return new partition index
    return p;
}

std::vector<int> Sorter::mergesort(const std::vector<int>& vec) {
    //base case - if size = 1 its sorted already
    if (vec.size() <= 1)
        return vec;

    //vectors for each side and the return vector
    std::vector<int> right_side, left_side, ret;
    int mid = (vec.size()+ 1) / 2;

    //fill each vector with half
    for (int i = 0; i < mid; i++){
        left_side.push_back(vec[i]);
    }
    for (int i = mid; i < vec.size(); i++){
        right_side.push_back(vec[i]);
    }

    //Recursive calls for splitting left and right sides
    left_side = mergesort(left_side);
    right_side = mergesort(right_side);
    ret = merger(left_side, right_side);

    //return the sorted vector
    return ret;
}


std::vector<int> Sorter::merger(std::vector<int>& left_side, std::vector<int>& right_side){
    //vector to return
    std::vector<int> ret;

        //fill vector with values from each of the sides
        if(left_side.size() > 0) {
            for (int i = 0; i < left_side.size(); i++)
                ret.push_back(left_side[i]);
        }
        else if(right_side.size() > 0) {
            for(int i = 0; i < right_side.size(); i++)
                ret.push_back(right_side[i]);
        }
    return ret;
}

#endif
