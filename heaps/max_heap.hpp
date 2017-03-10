// making a min heap

#ifndef MAXHEAP_HPP
#define MAXHEAP_HPP

#include <cassert>
#include <iostream>
#include <vector>

#include "heap.hpp"

class MaxHeap : public Heap {
private:
public:
  MaxHeap() : Heap() {}
  ~MaxHeap() {}
  
  void fix_up(const int&);
  void fix_down(const int&);
};

void MaxHeap::fix_up(const int& t) {
  // at the top of the tree
  if (t == 1)
    return;

  // if current is > its parent
  if (tree[t] > tree[t/2]) {
    swap(t, t/2);
    fix_up(t/2);
  }
}

void MaxHeap::fix_down(const int& t) {
  int left_index = t * 2;
  int right_index = (t * 2) + 1;

  // if two children
  if (right_index <= position) {
    // check for the largest of the children and treat like one child but recurse
    if (tree[left_index] > tree[right_index]) {
      if (tree[left_index] > tree[t]) {
	swap(left_index, t);
	fix_down(left_index);
      }
    }
    else {
      if (tree[right_index] > tree[t]) {
	swap(right_index, t);
	fix_down(right_index);
      }
    }
  }
  // one  child
  else if (left_index <= position) {
    if (tree[left_index] > tree[t])
      swap(left_index, t);
  }
}

#endif
 
