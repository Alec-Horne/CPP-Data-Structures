#ifndef AVL_HPP
#define AVL_HPP

#include <vector>
#include <sstream>
#include <string>

//AVL Node
template <class T>
struct AVLNode{
	T data;
	AVLNode* left;
	AVLNode* right;
	AVLNode* parent;
};

template <class T>
class AVL {
private:
	// put your private functions here (you will probably have quite a few)

	//a pointer to head
	AVLNode<T>* root;

	/*find and remove*/
	void find_and_remove(const T& t, AVLNode<T>* current_node);

	// Insert a node into the AVL recursive helper method
	void insert_helper(AVLNode<T>* rootNode, AVLNode<T>* newNode);

	// clear AVL
	void clear(AVLNode<T>* node);

	//preorder traversal
	void preorder(AVLNode<T>* node, std::vector<std::string>& vec);

	//balance tree
	void recursive_balance(AVLNode<T>* current_node);

	//height of node
	int height(AVLNode<T>* node);

	//get balance
	int balance(AVLNode<T>* node);

	// Left rotation node
	AVLNode<T>* rotate_left(AVLNode<T>* current_node);

	// Right rotation node
	AVLNode<T>* rotate_right(AVLNode<T>* current_node);

	//rotate left then right
	AVLNode<T>* double_rotate_left_right(AVLNode<T>* current_node);

	//rotate right then left
	AVLNode<T>* double_rotate_right_left(AVLNode<T>* current_node);

	//left most right or parent of a node
	AVLNode<T>* right_most_of_left_of_parent(AVLNode<T>* current_node);

	//remove specific node
	void remove_node(AVLNode<T>* current_node);

	//right most node
	AVLNode<T>* rightMost(AVLNode<T>* current_node);

	//right most node
	AVLNode<T>* parent_left_most(AVLNode<T>* current_node);

public:
  //constructor
  AVL();

  //destructor
  ~AVL();

  // Insert a node into the AVL with a given data value
  // The tree must be balanced after every insert
  void insert(const T&);

  // remove a node from the AVL with a specific data value
  // you MUST use the in order predecessor to replace the removed node
  void remove(const T& t) { find_and_remove(t, root); }

  // return a std::vector<std::string> of the serialized AVL tree
  // you WILL need to have template specialization for AVL<int> and AVL<std::string>
  // std::to_string(int) can be used to convert an integer to a string
  std::vector<std::string> serialize();
};

//constructor
template <class T>
AVL<T>::AVL(){
	root = NULL;
}

//destructor
template <class T>
AVL<T>::~AVL(){
	clear(root);
}

// clear AVL
template <class T>
void AVL<T>::clear(AVLNode<T>* node){
	if (node != NULL)
	{
		//clear left sub tree
		clear(node->left);
		//clear right sub tree
		clear(node->right);
		//delete current node
		delete node;
	}
}

//height of node
template <class T>
int AVL<T>::height(AVLNode<T>* node){
	if (node == NULL)
	{
		return -1;
	}
	//left height
	int leftHeight = height(node->left);
	//right height
	int rightHeight = height(node->right);

	//get max height and add by one
	if (leftHeight > rightHeight)
	{
		return leftHeight + 1;
	}else{
		return rightHeight + 1;
	}
}

//get balance
template <class T>
int AVL<T>::balance(AVLNode<T>* node){
	//subtract 2 heights of sub left and sub right tree
	return height(node->right) - height(node->left);
}

template <class T>
void AVL<T>::find_and_remove(const T& t, AVLNode<T>* current_node){
	if (current_node == NULL) {
		return;
	} else {
		if (current_node->data > t)
		{//remove left sub tree
			find_and_remove(t, current_node->left);
		} else if (current_node->data < t)
		{//remove right sub tree
			find_and_remove(t, current_node->right);
		} else if (current_node->data == t)
		{//remove this node
			remove_node(current_node);
		}
	}
}

//remove node
template <class T>
void AVL<T>::remove_node(AVLNode<T>* current_node) {
	AVLNode<T>* right_node;
	// remove child node
	if (current_node->left == NULL || current_node->right == NULL) {
		// the root is deleted
		if (current_node->parent == NULL) {
			this->root = NULL;
			delete (current_node);
			current_node = NULL;
			return;
		}
		right_node = current_node;
	} else {
		// current_node has 2 children
		right_node = right_most_of_left_of_parent(current_node);
		current_node->data = right_node->data;
	}

	//find parent node
	AVLNode<T>* parent_node;
	if (right_node->left != NULL) {
		parent_node = right_node->left;
	} else {
		parent_node = right_node->right;
	}

	if (parent_node != NULL) {
		parent_node->parent = right_node->parent;
	}

	if (right_node->parent == NULL) {
		//if parent if right is null, set parent to root node
		this->root = parent_node;
	} else {
		//if left of parent of right is right
		if (right_node == right_node->parent->left) {
			//set parent to left of parent of right
			right_node->parent->left = parent_node;
		} else {
			//set parent to right of parent of right node
			right_node->parent->right = parent_node;
		}
		//balance tree
		recursive_balance(right_node->parent);
	}

	delete (right_node);
	right_node = NULL;
}

//balance tree
template <class T>
void AVL<T>::recursive_balance(AVLNode<T>* current_node){

	int bal = balance(current_node);

	// rotate if balance is -2 or 2
	if (bal == -2) {
		//rotate right
		if (height(current_node->left->left) >= height(current_node->left->right)) {
			current_node = rotate_right(current_node);
		} else {
			//rotate left than right
			current_node = double_rotate_left_right(current_node);
		}
	} else if (bal == 2) {
		//rorate left
		if (height(current_node->right->right) >= height(current_node->right->left)) {
			current_node = rotate_left(current_node);
		} else {
			//rotate right then left
			current_node = double_rotate_right_left(current_node);
		}
	}

	if (current_node->parent != NULL) {
		recursive_balance(current_node->parent);
	} else {
		root = current_node;
	}
}

//right most left or parent of a node
template <class T>
AVLNode<T>* AVL<T>::right_most_of_left_of_parent(AVLNode<T>* current_node) {
	if (current_node->left != NULL) {
		AVLNode<T>* left_node = current_node->left;
		return rightMost(left_node);
	} else {
		return (parent_left_most(current_node));
	}
}

//right most node
template <class T>
AVLNode<T>* AVL<T>::rightMost(AVLNode<T>* current_node) {
	if (current_node->right != NULL)
	{
		return rightMost(current_node->right);
	}
	return current_node;
}

//most left node of parent
template <class T>
AVLNode<T>* AVL<T>::parent_left_most(AVLNode<T>* current_node) {
	AVLNode<T>* parent_node = current_node->parent;
	if (parent_node != NULL && current_node == parent_node->left)
	{
		return parent_left_most(parent_node);
	}
	return parent_node;
}

// Left rotation node
template <class T>
AVLNode<T>* AVL<T>::rotate_left(AVLNode<T>* current_node) {
	//left node
	AVLNode<T>* left_node = current_node->right;

	//set parent of current to parent of left
	left_node->parent = current_node->parent;

	//set left  of left node to right of current
	current_node->right = left_node->left;

	if (current_node->right != NULL) {
		//set current to parent of right of current
		current_node->right->parent = current_node;
	}

	//set current to left of left node
	left_node->left = current_node;
	//set left node to parent of current
	current_node->parent = left_node;

	if (left_node->parent != NULL) {
		//if right of parent of left is current
		if (left_node->parent->right == current_node) {
			//set left to right of parent of left
			left_node->parent->right = left_node;
		} else if (left_node->parent->left == current_node) {
			//set left to left of parent of left node
			left_node->parent->left = left_node;
		}
	}

	return left_node;
}

// Right rotation node
template <class T>
AVLNode<T>* AVL<T>::rotate_right(AVLNode<T>* current_node) {
	//left node
	AVLNode<T>* left_node = current_node->left;
	//parent node
	left_node->parent = current_node->parent;

	//set right of left to left of current
	current_node->left = left_node->right;

	if (current_node->left != NULL) {
		//set current to parent of left of current
		current_node->left->parent = current_node;
	}

	//set current to right of left
	left_node->right = current_node;
	//set left to parent of current
	current_node->parent = left_node;

	if (left_node->parent != NULL) {
		//if right of parent of left is current node
		if (left_node->parent->right == current_node) {
			//set left to right of parent of left
			left_node->parent->right = left_node;
		} else if (left_node->parent->left == current_node) {
			//set left to left of parent of left
			left_node->parent->left = left_node;
		}
	}

	return left_node;
}

//rotate left then right
template <class T>
AVLNode<T>* AVL<T>::double_rotate_left_right(AVLNode<T>* current_node) {
	current_node->left = rotate_left(current_node->left);
	return rotate_right(current_node);
}

//rotate right then left
template <class T>
AVLNode<T>* AVL<T>::double_rotate_right_left(AVLNode<T>* current_node) {
	current_node->right = rotate_right(current_node->right);
	return rotate_left(current_node);
}

// Insert a node into the AVL recursive helper method
template <class T>
void AVL<T>::insert_helper(AVLNode<T>* rootNode, AVLNode<T>* newNode){
	// insert as root if root node is NULL
	if (rootNode == NULL) {
		root = newNode;
	} else {
		// try with the left sub tree
		if (newNode->data < rootNode->data) {
			if (rootNode->left == NULL) {
				rootNode->left = newNode;
				newNode->parent = rootNode;
				// balance the tree
				recursive_balance(rootNode);
			} else { //call recursive to insert left
				insert_helper(rootNode->left, newNode);
			}
		} else if (newNode->data > rootNode->data)
		{// try with the right sub tree
			if (rootNode->right == NULL) {
				rootNode->right = newNode;
				newNode->parent = rootNode;

				// balance the tree
				recursive_balance(rootNode);
			} else {//call recursive to insert right
				insert_helper(rootNode->right, newNode);
			}
		} else {
			//duplicate
		}
	}
}

// Insert a node into the AVL with a given data value
// The tree must be balanced after every insert
template <class T>
void AVL<T>::insert(const T& t){
	//create new node
	AVLNode<T>* newNode = new AVLNode<T>;
	newNode->left = NULL;
	newNode->right = NULL;
	newNode->parent = NULL;
	newNode->data = t;

	insert_helper(root, newNode);
}

// return a std::vector<std::string> of the serialized AVL tree
// you WILL need to have template specialization for AVL<int> and AVL<std::string>
// std::to_string(int) can be used to convert an integer to a string
template <class T>
std::vector<std::string> AVL<T>::serialize(){
	std::vector<std::string> vec;
	preorder(root, vec);
	return vec;
}

//preorder traversal
template <class T>
void AVL<T>::preorder(AVLNode<T>* node, std::vector<std::string>& vec){
	if (node != NULL)
	{
		//convert to string and push to vector
		std::ostringstream  stream;
		stream << node->data;

		vec.push_back(stream.str());
		preorder(node->left, vec);
		preorder(node->right, vec);
	}else{
		vec.push_back("/");
	}
}

#endif
