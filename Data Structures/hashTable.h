#ifndef HashTable_h
#define HashTable_h

#include "forwardSortedList.h"
#include<unordered_set>

class HT : public forwardList {
private:
    forwardList* myHashTable;
    int size;
    std::unordered_set<int> mySet;
public:
    HT();
    HT(const std::unordered_set<int>&);
    ~HT();
    void chaining();
    void displayHT() const;
    int getSize() const;
    void getMySet() const;
    void search(const int&) const;
    int hashFunction(const int&) const;
};

//Default constructor:
HT::HT() {
    std::cout << "Enter the number of keys you have : "; std::cin >> size;
    int x;
    int i = 1;
    do {
        std::cout << "enter value " << i << " : "; std::cin >> x;
        mySet.insert(x);
        i++;
    } while (i <= size);
    myHashTable = new forwardList[size];
    chaining();
}

// constructor with arguments:
HT::HT(const std::unordered_set<int>& s) :size(int(s.size())) {
    myHashTable = new forwardList[size];
    mySet = s;
    chaining();
}

//Destructor
HT::~HT() {
    if (!mySet.empty()) {
        mySet.clear();
        for (int i = 0; i < size; i++) {
            myHashTable[i].~forwardList();
        }
    }
}
//AddNode method
void HT::chaining() {
    if (mySet.empty())
        std::cout << "The set is empty" << std::endl;
    else {
        std::unordered_set<int>::iterator it = mySet.begin();
        for (; it != mySet.end(); it++) {
            int index = hashFunction(*it);
            myHashTable[index].addNode(*it);
        }
    }
}

//Hash fUNCTION
int HT::hashFunction(const int& value) const {
    return value % size;
}

//disply my Hash Table

void HT::displayHT() const {
    if (!mySet.empty()) {
        for (int i = 0; i < size; i++) {
            std::cout << "\nindex " << i << " :" << std::endl;
            if (myHashTable[i].getHead() != nullptr)
                myHashTable[i].displayList();
            else
                std::cout << "Empty" << std::endl;
        }
    }
}
void HT::getMySet() const {
    for (auto i : mySet)
        std::cout << i << " ";
}

int HT::getSize() const {
    return size;
}

//search fUNCTION
void HT::search(const int& value) const {
    if (myHashTable[hashFunction(value)].getHead() != nullptr) {
        if (myHashTable[hashFunction(value)].searchNode(value)) std::cout << value << " : exist in the hashTable" << std::endl;
        else std::cout << value << " : does not exist in the hashTable" << std::endl;
    }
    else std::cout << value << " : does not exist in the hashTable" << std::endl;
}

#endif /* HashTable_h */
