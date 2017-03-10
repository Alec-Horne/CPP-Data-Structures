#include <iostream>
#include <cstdlib>
#include "AStack.hpp"
#include "LStack.hpp"
#include "EAStack.hpp"

const int DEFAULT_STACK_SIZE = 5;

int main(int argc, char* argv[]) {
  int size;
  if (argc != 2 || (size = atoi(argv[1])) < 1)
    size = DEFAULT_STACK_SIZE;
  
  AStack<int> *as = new AStack<int>(size);
  for (int i = 0; i < size; ++i)
    as->push(i);
  
  for (int i = 0; i < size; ++i)
    std::cout << "[" << as->pop() << "]";
  std::cout << std::endl;
  
  LStack<int>* ls = new LStack<int>();
  for (int i = 0; i < size; ++i)
    ls->push(i);
  
  for (int i = 0; i < size; ++i)
    std::cout << "[" << ls->pop() << "]";
  std::cout << std::endl;
  
  EAStack<int> *eas = new EAStack<int>(size);
  for (int i = 0; i < size * 200000; ++i)
    eas->push(i);
  
  for (int i = 0; i < size * 200000; ++i)
    std::cout << "[" << eas->pop() << "]";
  std::cout << std::endl;
  
}
