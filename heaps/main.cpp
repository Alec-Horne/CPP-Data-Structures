#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include "min_heap.hpp"
#include "max_heap.hpp"

int main() {
  srand(time(0));
  MinHeap h;
  MaxHeap mh;
  MinHeap tmh;
  std::vector<int> v;
  for (int i = 0; i < 10; ++i) {
    int x = rand() % 1000;  
    v.push_back(x);
    h.enqueue(x);
    mh.enqueue(x); 
  }
    
  tmh.create_heap(v);

  for (int i = 0; i < 10; ++i) {
    std::cout << "[" << h.dequeue() << "]";
  }
  std::cout << std::endl;

  for (int i = 0; i < 10; ++i) {
    std::cout << "[" << tmh.dequeue() << "]";
  }
  std::cout << std::endl;

  for (int i = 0; i < 10; ++i) {
    std::cout << "[" << mh.dequeue() << "]";
  }
  std::cout << std::endl;
}
