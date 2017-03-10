#include <iostream>
#include <cassert>
#include "LQueue.hpp"

int main() {

  //assert some stuff
  LQueue<int>* aq = new LQueue<int>();
  assert(aq->size() == 0);
  std::cout << "Test 1 passed" << std::endl;

  for (int i = 0; i < 10; ++i)
    aq->enqueue(i);

  assert(aq->size() == 10);
  assert(aq->peek() == 0);
  std::cout << "Test 2 passed" << std::endl;


  assert(aq->dequeue() == 0);
  assert(aq->dequeue() == 1);
  assert(aq->dequeue() == 2);
  assert(aq->size() == 7);
  std::cout << "Test 3 passed" << std::endl;

  aq->enqueue(100);
  assert(aq->size() == 8);
  assert(aq->peek() == 3);
  std::cout << "Test 4 passed" << std::endl;

  aq->clear();
  assert(aq->size() == 0);
  std::cout << "Test 5 passed" << std::endl;

  std::cout << "\nAll Tests Passed!" << std::endl;
}
