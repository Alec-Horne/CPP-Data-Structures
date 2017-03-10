#ifndef AQUEUE_HPP
#define AQUEUE_HPP

/*
  An array based implementation of the Queue ADT
 */

#include <cassert>
#include "Queue.hpp"

const int DEFAULT_QUEUE_SIZE = 10; 

template <class T>
class AQueue : public Queue<T> {
private:
  // the size of the array
  int max_size = 0;

  // the number of elements in the queue
  int count = 0;

  // the index of the front
  int front = 0;

  // the array itself
  T* list;
public:
  AQueue(const int size=DEFAULT_QUEUE_SIZE);
  ~AQueue();

  void enqueue(const T&);
  T dequeue();
  const T& peek() const; 
  void clear() { front = count = 0; }
  int size() { return count; }
};

template <class T>
AQueue<T>::AQueue(const int size) {
  // set the size of the array
  max_size = size;

  // create the array
  list = new T[size];
}

template <class T>
AQueue<T>::~AQueue() {
  // delete the array from memory
  delete [] list;
}

template <class T>
void AQueue<T>::enqueue(const T& t) {
  // make sure we arent full
  assert(count < max_size);

  // set the element at the correct position (with wrapping) and update count
  list[(front + count++) % max_size] = t;
}

template <class T>
T AQueue<T>::dequeue() {
  // make sure we arent empty
  assert(count > 0);
  
  // store the element at the front
  T ret = list[front];

  // adjust front
  // also adjusts count
  // set front to 0 if there are no more elements the in queue
  front = (--count == 0 ? 0 : ++front % max_size);
  
  // return the element
  return ret;
}

template <class T>
const T& AQueue<T>::peek() const {
  // make sure the array isnt empty
  assert(count > 0);
  
  // return the front elements data
  return list[front];
}

#endif
