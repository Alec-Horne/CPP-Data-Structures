#ifndef ASTACK_HPP
#define ASTACK_HPP

#include <cassert>
#include "Stack.hpp"

// we need a default size in case one is not given
const int DEFAULT_SIZE = 10;

template <class T>
class AStack : public Stack<T> {
private:
  // the max size the array can be
  int max_size;

  // the index of the current top of the stack
  int top = 0;

  // the actual list in memory of our items
  T* list; // the actual list of elements

public:
  // construct with the default size if one is not given
  AStack(int size=DEFAULT_SIZE);
  ~AStack();
  
  void push(const T&);
  T pop();
  const T& peek() const;
  void clear() { top = 0; }
  int size() { return top; }
};

template <class T>
AStack<T>::AStack(int size) {
  // set the max size
  max_size = size;

  // create the list in memory
  list = new T[size];
}


template <class T>
AStack<T>::~AStack() {
  // delete the list from memory
  delete [] list;
}  

template <class T>
void AStack<T>::push(const T& t) {
  //check if stack is full
  assert(top < max_size);

  //insert the item into the array and move the top index
  list[top++] = t;
}

template <class T>
T AStack<T>::pop() {
  // make sure the list is not empty
  assert(top > 0);

  // move the top pointer and return the item from the list
  return list[--top];
}

template <class T>
const T& AStack<T>::peek() const {
  // make sure the list is not empty
  assert(top > 0);

  // return the top item data without remove it
  return list[top - 1];
}

#endif
