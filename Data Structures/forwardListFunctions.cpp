#include "forwardList.h"

fList::fList():head(0) {}
fList::fList(int x) {
	head->data = x;
	head->next = nullptr;
}
fList::~fList() {
	if (head == nullptr)
		return;
	else {
		node* ptr = head;
		node* nextPtr = ptr->next;
		while (nextPtr != nullptr) {
			delete ptr;
			ptr = nextPtr;
			nextPtr = nextPtr->next;
		}
		delete ptr;
	}
	std::cout << "List distroyed\n";
}
void fList::addNode(int x) {
	node* newNode = new node;
	newNode->data = x;
	newNode->next = NULL;
	if (head == nullptr)
		head = newNode;
	else {
		node* ptr = head;
		while (ptr->next != nullptr)
			ptr = ptr->next;
		ptr->next = newNode;
	}
}
void fList::displayList() const {
	node* ptr = head;
	while (ptr != NULL) {
		std::cout << ptr->data << " ";
		ptr = ptr->next;
	}
	std::cout << "\n";
}
void fList::deleteNode(int x) {
	bool flag = false;
	if (head == nullptr)
		std::cout << "List is empty" << std::endl;
	else {
		if (head->data == x) {
			head = head->next;
			flag = true;
		}		
		else {
			node* ptr = head;
			node* nextNode = ptr->next;
			
			while ((nextNode != nullptr) && !flag) {
				if (nextNode->data == x) {
					ptr->next = nextNode->next;
					flag = true;
				}
				else {
					ptr = nextNode;
					nextNode = nextNode->next;
				}
			}
		}
	}
	if (!flag)
		std::cout << "Node not found" << std::endl;
	else std::cout << "Node is deleted" << std::endl;
}

void fList::reverseList() {
	if (head == nullptr)
		std::cout << "List is empty\n";
	else {
		std::stack<node*> s;
		node* ptr = head;
		while (ptr != NULL) {
			s.push(ptr);
			ptr = ptr->next;
		}
		ptr = s.top();
		head = ptr;
		s.pop();
		while (!s.empty()) {
			ptr->next = s.top();
			ptr = ptr->next;
			s.pop();
		}
		ptr->next = nullptr;
	}
}
void fList::sortList() {
	if(head == nullptr)
		std::cout << "List is empty\n";
	else {
		node* ptr = head;
		node* movingPtr = ptr->next;
		while (ptr != nullptr) {
			while (movingPtr != NULL) {
				int temp = 0;
				if (ptr->data > movingPtr->data) {
					temp = ptr->data;
					ptr->data=movingPtr->data;
					movingPtr->data = temp;
					movingPtr = movingPtr->next;
				}
				else movingPtr = movingPtr->next;
			}
			ptr = ptr->next;
			if (ptr != nullptr) {
				movingPtr = ptr->next;
			}
			
		}
	}
}
void fList::insertNode(int position, int x) {
	bool flag = false;
	if (head == nullptr)
		std::cout << "the List is empty" << std::endl;
	else {
		node* newNode = new node;
		newNode->data = x;
		newNode->next = nullptr;
		if (head->data == position) {
			node* temp = head->next;
			head->next = newNode;
			newNode->next = temp;
			flag = true;
		}
		else {
			node* ptr = head;
			node* nextPtr = ptr->next;
			while (nextPtr != nullptr && !flag) {
				if (nextPtr->data == position) {
					node* temp = nextPtr->next;
					nextPtr->next = newNode;
					newNode->next = temp;
					flag = true;
				}
				else {
					ptr = nextPtr;
					nextPtr = nextPtr->next;
				}
			}
			if (flag)
				std::cout << "Node is added" << std::endl;
			else {
				while (ptr->next != nullptr) {
					ptr = ptr->next;
				}
				ptr->next = newNode;
			}
		}
		
	}
}
