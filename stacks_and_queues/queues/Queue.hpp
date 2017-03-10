#ifndef QUEUE_HPP
#define QUEUE_HPP

/*
  The base class for the Queue ADT
  This will be inherited for both array and linked list versions
 */

template <class T>
class Queue
{
private:
  
public:
  Queue() {}
  // always virtualize destructors when inheritance will occur
  virtual ~Queue() {}

  // used to enqueue a new item onto back of the queue
  virtual void enqueue(const T&)=0;

  // dequeue and item from the back of the queue and return its data
  virtual T dequeue()=0;

  // look at the data from the item at the back of the queue without removing it
  virtual const T& peek() const =0;

  // remove all items from the queue
  virtual void clear()=0;

  // the number of items in the queue
  virtual int size()=0;
};

#endif
