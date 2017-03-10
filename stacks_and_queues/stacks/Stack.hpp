#ifndef STACK_HPP
#define STACK_HPP

/*
  The base class for the Stack ADT
  This will be inherited for both array and linked list versions
 */

template <class T>
class Stack
{
private:
  
public:
  Stack() {}
  // always virtualize destructors when inheritance will occur
  virtual ~Stack() {}

  // used to push a new item on that stack
  virtual void push(const T&)=0;

  // pop an item off the stack and return its data
  virtual T pop()=0;

  // look at the data from the item at the top of the stack without removing it
  virtual const T& peek() const =0;

  // remove all items from the stack
  virtual void clear()=0;

  // the number of items on the stack
  virtual int size()=0;
};

#endif
