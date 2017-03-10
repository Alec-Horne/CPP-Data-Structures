#include "BST.hpp"
#include <cstdlib>
#include <ctime>
int main() {
  srand(time(0));

  BST* bstbad = new BST();
  bstbad->in_order_print();

  BST* bst = new BST();
  bst->add(10);
  bst->in_order_print();

  bst->add(42);
  bst->add(1);
  bst->in_order_print();
  
  for(int i = 0; i < (rand() & 15); ++i)
    bst->add(rand() % 1000);

  bst->pre_order_print();
  bst->in_order_print();
  bst->post_order_print();

  bst->print_tree();
  std::cout << "Nodes: " << bst->count_nodes() << std::endl;
  std::cout << "Leaf Nodes: " << bst->count_leaf_nodes() << std::endl;
  std::cout << "Internal Nodes: " << bst->count_internal_nodes() << std::endl;
}
