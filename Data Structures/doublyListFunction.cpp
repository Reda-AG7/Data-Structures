#include "doublyList.h"

dList::dList() :head(NULL) {}
bool dList::isEmpty() const {
	if (head == nullptr)
		return true;
	else return false;
}
dList::~dList() {
	if (isEmpty())
		std::cout << "the list is empty" << std::endl;
	else {
		node* ptr = head;
		while (ptr->next != nullptr) {
			delete ptr->prev;
			ptr = ptr->next;
		}
		delete ptr;
	}
	std::cout << "Distructor is called" << std::endl;
}
void dList::addNode(int x) {
	node* newNode = new node;
	newNode->data = x;
	newNode->next = newNode->prev = nullptr;
	if (isEmpty())
		head = newNode;
	else {
		node* ptr = head;
		while (ptr->next != nullptr)
			ptr = ptr->next;
		newNode->prev = ptr;
		ptr->next = newNode;
	}
}

void dList::displayList() const {
	if (isEmpty())
		std::cout << "The List is Empty" << std::endl;
	else {
		node* ptr = head;
		while (ptr != nullptr) {
			std::cout << ptr->data << " ";
			ptr = ptr->next;
		}
	}
	std::cout << std::endl;
}
void dList::deleteNode(int x) {
	if (isEmpty())
		std::cout << "The List is Empty" << std::endl;
	else {
		bool flag = false;
		if (head->data == x) {
			head = head->next;
			head->prev = nullptr;
		}
		else {
			node* ptr = head->next;
			while (ptr != nullptr && !flag) {
				if (ptr->data == x) {
					if (ptr->next == nullptr)
						ptr->prev->next = nullptr;
					else {
						ptr->prev->next = ptr->next;
						ptr->next->prev = ptr->prev;
						ptr = nullptr;
					}
					flag = true;
				}
				else {
					ptr = ptr->next;
				}
			}
		}
		if (flag)
			std::cout << "Node is deleted\n";
		else std::cout << "Node is not found\n";
	}
}
void dList::sortList() {
	if (isEmpty())
		std::cout << "The list is empty" << std::endl;
	else {
		node* ptr = head;
		node* movingPtr = ptr->next;
		while (ptr != nullptr) {
			while (movingPtr != nullptr) {
				int temp = 0;
				if (movingPtr->data < ptr->data) {
					temp = movingPtr->data;
					movingPtr->data = ptr->data;
					ptr->data = temp;
					movingPtr = movingPtr->next;
				}
				else {
					movingPtr = movingPtr->next;
				}
			}
			ptr = ptr->next;
			if (ptr != nullptr)
				movingPtr = ptr->next;
		}
	}
}
//int main() {
//	{dList d;
//	d.addNode(-10);
//	d.addNode(40);
//	d.addNode(-70);
//	d.addNode(7);
//	d.displayList();
//	//d.deleteNode(70);
//	d.sortList();
//	d.displayList();
//	}
//	std::cin.get();
//}