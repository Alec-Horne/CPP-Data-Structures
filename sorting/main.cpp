#include <iostream>
#include <vector>

#include "Sorter.hpp"

int main(int argc, char* argv[]) {

  std::vector<int> numbers;
  numbers.push_back(10);
  numbers.push_back(5);
  numbers.push_back(9999);
  
  for (int i = 0; i < numbers.size(); ++i)
    std::cout << "[" << numbers[i] << "]";
  std::cout << std::endl;

  Sorter s;
  std::vector<int> sorted = s.radix_sort(numbers);

  for (int i = 0; i < sorted.size(); ++i)
    std::cout << "[" << sorted[i] << "]";
  std::cout << std::endl;
}
