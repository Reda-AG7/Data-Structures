#ifndef _forward_sorted_List
#define _forward_sorted_List

#include<iostream>
struct node {
    int data;
    node* next;
};

//this list will be sorted !!!!

class forwardList {
private:
    node* head;
public:
    forwardList();
    forwardList(const int&);
    ~forwardList();
    void addNode(const int&);
    void displayList() const;
    void deleteNode(const int&);
    const node* const getHead() { return head; }
    bool searchNode(const int&) const;
};

//constructor by default
forwardList::forwardList() : head(nullptr) {}

//constructor  with arguments
forwardList::forwardList(const int& value) {
    head = new node;
    head->data = value;
    head->next = nullptr;
}

//distructor
forwardList::~forwardList() {
    if (head != 0) {
        node* ptr = head;
        node* nextPtr = ptr->next;
        while (nextPtr != 0) {
            delete ptr;
            ptr = nextPtr;
            nextPtr = nextPtr->next;
        }
        delete ptr;
    }
}

//addNode method
void forwardList::addNode(const int& value) {
    node* newNode = new node;
    newNode->data = value;
    newNode->next = nullptr;
    if (head == 0) {
        head = newNode;
    }
    else {
        if (head->data > value) {
            newNode->next = head;
            head = newNode;
        }
        else {
            node* ptr = head;
            node* nextPtr = ptr->next;
            bool found = false;
            while (nextPtr != 0 && !found) {
                if (nextPtr->data < value) {
                    ptr = nextPtr;
                    nextPtr = nextPtr->next;
                }
                else {
                    ptr->next = newNode;
                    newNode->next = nextPtr;
                    found = true;
                }
            }
            if (!found)
                ptr->next = newNode;
        }
    }
}

// Display our list
void forwardList::displayList() const {
    if (head != nullptr) {
        node* ptr = head;
        while (ptr != nullptr) {
            if (ptr->next != nullptr) {
                std::cout << ptr->data << " --> ";
                ptr = ptr->next;
            }
            else {
                std::cout << ptr->data << std::endl;
                ptr = ptr->next;
            }
        }
        std::cout << std::endl;
    }
}

// Search in sorted list:
bool forwardList::searchNode(const int& value) const {
    if (head != nullptr) {
        node* ptr = head;
        while (ptr != nullptr && ptr->data < value) {
            ptr = ptr->next;
        }
        if (ptr == nullptr) return false;
        else {
            if (ptr->data == value) return true;
            else return false;
        }
    }
    return false;
}

#endif
