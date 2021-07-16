#ifndef _MY_DYNAMIC_ARRAY_CLASS
#define _MY_DYNAMIC_ARRAY_CLASS

#include<iostream>
using std::cin; using std::cout; using std::endl;

template <class T>
class DynamicArray {
private:
	T* arr;
	int index;
	int size;
public:
	DynamicArray();
	DynamicArray(int);
	DynamicArray(const DynamicArray&);
	~DynamicArray();
	bool isFull() const;
	bool isEmpty() const;
	void insertElement(T);
	void sortArray();
	void searchElement(T)const;
	void deleteElement(T);

	void displayArray() const;
	int getSize() const;
	int getNbElements() const;

};


#endif