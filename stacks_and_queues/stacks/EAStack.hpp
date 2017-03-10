#ifndef EASTACK_HPP
#define EASTACK_HPP

#include <cassert>
#include "Stack.hpp"

const int INITIAL_SIZE = 0b10;

template <class T>
class EAStack : public Stack<T> {
private:
  // the current size the array can be
  int current_size;

  // the index of the current top of the stack
  int top = 0;

  // the actual list in memory of our items
  T* list; // the actual list of elements

public:
  // construct with the default size if one is not given
  EAStack(int size=INITIAL_SIZE);
  ~EAStack();
  
  void push(const T&);
  T pop();
  const T& peek() const;
  void clear() { top = 0; }
  int size() { return top; }
};

template <class T>
EAStack<T>::EAStack(int size) {
  // set the current size
  current_size = size;

  // create the list in memory
  list = new T[size];
}


template <class T>
EAStack<T>::~EAStack() {
  // delete the list from memory
  delete [] list;
}  

template <class T>
void EAStack<T>::push(const T& t) {
  //check if stack is full
  if (top >= current_size) { 

    // create a new list of twice the current size
    T* new_list = new T[current_size * 2];

    // copy elements from the old list into the new list
    for (int i = 0; i < current_size; ++i)
      new_list[i] = list[i];

    // delet the old list
    delete [] list;

    // point list at the new array
    list = new_list;

    // update the current size
    current_size *= 2;
  }
  
  //insert the item into the array and move the top index
  list[top++] = t;
}

template <class T>
T EAStack<T>::pop() {
  // make sure the list is not empty
  assert(top > 0);

  // move the top pointer and return the item from the list
  return list[--top];
}

template <class T>
const T& EAStack<T>::peek() const {
  // make sure the list is not empty
  assert(top > 0);

  // return the top item data without remove it
  return list[top - 1];
}

#endif
