/*#include "bst.h"
#include<stack>
bst::bst() : root(nullptr) {}

void bst::addNode(int x) {
	node* newNode = new node;
	newNode->data = x;
	newNode->left = newNode->right = nullptr;
	if (root == nullptr)
		root = newNode;
	else {
		node* ptr = root;
		bool flag = false;
		while (ptr != nullptr && !flag) {
			if (ptr->data > x) {
				if (ptr->left == nullptr) {
					ptr->left = newNode;
					flag = true;
				}
					
				else ptr = ptr->left;
			}
			else {
				if (ptr->right == nullptr)
					ptr->right = newNode;
				else ptr = ptr->right;
			}
		}
	}
}

void bst::inOrderSort() {
	if (root == 0)
		std::cout << "The Tree is empty" << std::endl;
	else {
		node* ptr = root;
		std::stack<node*> s;
		s.push(ptr);
		while (ptr != nullptr && !s.empty()) {
			s.push(ptr);
			ptr = ptr->left;

		}
		
	}
}*/