#ifndef LQUEUE_HPP
#define LQUEUE_HPP

/*
  A linked list implementation of the Queue ADT
 */

#include <cassert>
#include "Queue.hpp"

// The node class
template <class T>
struct LQueue_Node {
  T data;
  LQueue_Node<T>* next;
  LQueue_Node(const T& t) { data = t; }
};

template <class T>
class LQueue : public Queue<T> {
private:
  // the front and back node pointers
  LQueue_Node<T>* front = 0, *back = 0;
  
  // the number of elements in the queue
  int count = 0;
public:
  LQueue() {}
  ~LQueue();

  void enqueue(const T&);
  T dequeue();
  const T& peek() const; 

  // while there are elements in the queue, dequeue them
  void clear() { while(count > 0) dequeue(); }

  // count is the number of elements
  int size() { return count; }
};

template <class T>
LQueue<T>::~LQueue() {
  // clear will delete all nodes using dequeue()
  clear();
}

template <class T>
void LQueue<T>::enqueue(const T& t) {
  // if there are nodes in the list
  if (front) {
    // set the last nodes next pointer to the new node
    back->next = new LQueue_Node<T>(t);
    
    // move the back pointer
    back = back->next;
  } else {
    // the list is empty, so set back and front to the new node
    back = front = new LQueue_Node<T>(t);
  }
  ++count;
}

template <class T>
T LQueue<T>::dequeue() {
  // make sure the queue int empty
  assert(count > 0);

  // point to the current front
  LQueue_Node<T>* temp = front;

  // move the front pointer to the next in line (null if there is only one element in the list)
  front = front->next;

  // store the data from the old front
  T ret = temp->data;

  // delete the old front node
  delete temp;

  // reduce the count
  --count;

  // return the value
  return ret;
}

template <class T>
const T& LQueue<T>::peek() const {

  // make sure the queue isnt empty
  assert(count > 0);

  // return the data from the front
  return front->data;
}

#endif
