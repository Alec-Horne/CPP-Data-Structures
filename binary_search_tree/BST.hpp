#ifndef BST_HPP
#define BST_HPP

#include <iostream>
#include <string>

struct BSTN {
  int data;
  BSTN* left = 0, * right = 0;
  BSTN(const int& n) { data = n; }
  ~BSTN();
};

BSTN::~BSTN() {
  if (left)
    delete left;
  if (right)
    delete right;
}

class BST {
private:
  BSTN* root = 0;

  // add a node to an existing node as a child
  void add(const int&, BSTN*);

  // recursive call to printing functions
  void in_order_print(BSTN*);
  void pre_order_print(BSTN*);
  void post_order_print(BSTN*);
  void print_tree(BSTN*, const std::string&);

  // recursive calls for counting functions
  int count_nodes(BSTN*);
  int count_leaf_nodes(BSTN*);
  int count_internal_nodes(BSTN*);
public:
  BST() {}
  ~BST();

  // add a node to the tree
  void add(const int&);

  // helper functions for printing
  void in_order_print();
  void pre_order_print();
  void post_order_print();
  void print_tree();

  // helper functions for counting
  int count_nodes() { return count_nodes(root); }
  int count_leaf_nodes() { return count_leaf_nodes(root); }
  int count_internal_nodes() { return count_internal_nodes(root); }
};

// deleting the root, the node destructor takes care of the rest
BST::~BST() {
  delete root;
}

// start the recursive calls
void BST::in_order_print() {
 if(!root) 
   return; 
 in_order_print(root); 
 std::cout << std::endl; 
}

// start the recursive calls
void BST::pre_order_print() { 
  if (!root)
    return;
  pre_order_print(root); 
  std::cout << std::endl; 
}

// start the recursive calls
void BST::post_order_print() { 
  if (!root)
    return;
  post_order_print(root); 
  std::cout << std::endl; 
}

// start the recursive calls
void BST::print_tree() {
 print_tree(root, ""); 
 std::cout << std::endl; 
}

// this functions checks to see if we have an empty tree
// if so we make a new root
// if not, we start the recursive adding
void BST::add(const int& n) {
  if (root)
    // check for the existence of a child where the node needs to go
    add(n, root);
  else
    root = new BSTN(n);
}

// if we need to add a node to a subtree
// we find out if its <= or > the root of the subtree
// if <=, we look to see if there is a left child
// if there is a left child we recursively add the new node to the left subtree
// if there is no child we make a new child 
// > is handled in the same fashion
void BST::add(const int& n, BSTN* node) {
  // should be a left child
  if (n <= node->data) {
    if(node->left)
      add(n, node->left);
    else
      node->left = new BSTN(n);
  } else {
    if(node->right)
      add(n, node->right);
    else
      node->right = new BSTN(n);
  }
}

// left, self, right
void BST::in_order_print(BSTN* node) {
  if (node->left)
    in_order_print(node->left);  
  std::cout << "[" << node->data << "]";
  if(node->right)
    in_order_print(node->right);
}

// self, left, right
void BST::pre_order_print(BSTN* node) {
  std::cout << "[" << node->data << "]";  
  if (node->left)
    pre_order_print(node->left);
  if (node->right)
    pre_order_print(node->right);
}

// left, right, self
void BST::post_order_print(BSTN* node) {
  if (node->left)
    post_order_print(node->left);
  if (node->right)
    post_order_print(node->right);
  std::cout << "[" << node->data << "]";  
}

// reverse, in-order, with adding spaces
void BST::print_tree(BSTN* node, const std::string& s) {
  if (!node) {
    std::cout << s << "NULL" << std::endl;
    return;
  }

  print_tree(node->right, s + "    ");  
  std::cout << s << node->data << std::endl;
  print_tree(node->left, s + "    ");
}

// self is a node, plus # of nodes in both chilc subtrees
int BST::count_nodes(BSTN* node)
{
  if (!node)
    return 0;

  return 1 + count_nodes(node->left) + count_nodes(node->right);
}


int BST::count_leaf_nodes(BSTN* node)
{
  if (!node)
    return 0;

  // no children means I am a leaf, return 1
  if (!node->left && !node->right)
    return 1;

  // 0 for self, add # of leaf nodes in child subtrees
  return count_leaf_nodes(node->left) + count_leaf_nodes(node->right);
}

int BST::count_internal_nodes(BSTN* node) 
{
  if (!node)
    return 0;

  // if no children, i am a leaf node, so nothing left to do
  if (!node->left && !node->right)
    return 0;

  // 1 for self, add # of internal nodes in child subtrees
  return count_internal_nodes(node->left) + count_internal_nodes(node->right) + 1;
}

#endif
