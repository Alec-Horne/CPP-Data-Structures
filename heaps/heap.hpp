// making a heap

#ifndef HEAP_HPP
#define HEAP_HPP

#include <cassert>
#include <iostream>
#include <vector>

class Heap {
protected:
  // holds the tree
  std::vector<int> tree;
  
  // index of the last element added
  int position = 0;
public:
  Heap() { tree.resize(2); }
  virtual ~Heap() {}
  
  // add an element to the tree
  void enqueue(const int&);
  // fix the heap from a specific index up
  virtual void fix_up(const int&) = 0;

  // remove the smallest element
  int dequeue();
  // fix the tree after replacing the smallest element
  virtual void fix_down(const int&) = 0;

  void swap(const int&, const int&);
  void display();

  void create_heap(std::vector<int>&);
};

void Heap::enqueue(const int& t) {
  // check to see if we need to expand the vector
  if (position == tree.size() - 1)
    tree.resize(tree.size() * 2);

  // insert at the next position
  tree[++position] = t;

  // fix up to the root (or until we dont need to swap)
  fix_up(position);
  // done
}

int Heap::dequeue() {
  assert(position);

  int ret = tree[1];
  swap(1, position--);
  fix_down(1);
  return ret;
}
 
void Heap::swap(const int& a, const int& b) {
  int temp = tree[a];
  tree[a] = tree[b];
  tree[b] = temp;
}

void Heap::display() {
  for (int i = 1; i <= position; ++i)
    std::cout << "[" << tree[i] << "]";
  std::cout << std::endl;
}

void Heap::create_heap(std::vector<int>& v) {
  // set the tree to the correct size
  if (v.size() > tree.size() - 1)
    tree.resize(v.size() + 1);
  
  for(int i = 0; i < v.size(); ++i)
    tree[i + 1] = v[i];

  position = v.size();

  for (int i = (position - (position / 2)); i > 0; --i)
    fix_down(i);
}

#endif
 
