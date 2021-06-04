#include "DynamicArrayClass.h"

//default constructor ;
template <class T>
DynamicArray <T> ::DynamicArray() {
	size = 5;   //Default size
	arr = new int[size];
	index = -1;
}
//constructor with arguments
template <class T>
DynamicArray <T> ::DynamicArray(int element) {
	size = element;
	arr = new int[size];
	index = -1;
}
// copy constructor :
template <class T>
DynamicArray <T> ::DynamicArray(const DynamicArray& A) {
	size = A.size;
	index = A.index;
	arr = new int[size];
	for (int i = 0; i <= index; i++) {
		arr[i] = A.arr[i];
	}

}
template <class T>
DynamicArray <T>:: ~DynamicArray() {
	delete[] arr;
}
//isFull() function
template <class T>
bool DynamicArray <T> ::isFull() const {
	if (index == size - 1)
		return true;
	return false;
}
//isEmpty() function
template <class T>
bool DynamicArray <T> ::isEmpty() const {
	if (index == -1)
		return true;
	return false;
}

//insert() function :
template <class T>
void DynamicArray <T> ::insertElement(T element) {
	if (index < size - 1) {
		arr[++index] = element;
	}
	else {
		int oldSize = size;
		size *= 2; // the new array's will be twice larger than the old one 
					//to prevent repeating this process everytime we append an element
		int* arr2 = new int[size];
		for (int i = 0; i < oldSize; i++) {
			arr2[i] = arr[i];
		}
		arr2[++index] = element;
		delete[] arr;
		arr = arr2;
		arr2 = nullptr;
		delete[] arr2;
	}
}
//display all the elements of the array:
template <class T>
void DynamicArray <T> ::displayArray() const {
	if (isEmpty())
		cout << "the array is completely empty." << endl;
	else {
		cout << "The Element of the Array are : " << endl;
		for (int i = 0; i <= index; i++) {
			cout << arr[i] << "  ";
		}
		cout << endl;
	}


}
// getSize() function;
template <class T>
int DynamicArray <T> ::getSize() const {
	return size;
}
// get number of elements in the array function;
template <class T>
int DynamicArray <T> ::getNbElements() const {
	return index + 1;
}

// sortArray() Function:
//we are going to use bubble sort algorithm.
template <class T>
void DynamicArray <T> ::sortArray() {
	for (int pass = 0; pass < index; pass++) {
		int check = 0;
		for (int i = 0; i < (index - pass); i++) {
			int temp = 0;
			if (arr[i] > arr[i + 1]) {
				temp = arr[i + 1];
				arr[i + 1] = arr[i];
				arr[i] = temp;
				check = 1;
			}
		}
		if (check == 0) break;
	}
}
template <class T>
void DynamicArray <T> ::searchElement(T element) const {
	if (isEmpty()) cout << "the Array is empty" << endl;
	else {
		int position = -1;
		for (int i = 0; i <= index; i++) {
			if (arr[i] == element) {
				position = i;
				break;
			}
		}
		if (position != -1)
			cout << "the element exist in the position : " << position + 1 << endl;
		else cout << "the Element is not found." << endl;
	}
}
template <class T>
void DynamicArray <T>::deleteElement(T element) {
	if (isEmpty()) cout << "the Array is empty" << endl;
	else {
		bool found = false;
		for (int i = 0; i <= index; i++) {
			if (arr[i] == element) {
				for (int j = i; j <= index; j++)
					arr[j] = arr[j + 1];
				index--;
				found = true;
				break;
			}
		}
		if (found) cout << element << " ----> is deleted" << endl;
		else cout << element << "----> is not found" << endl;
	}
}
/*
int main() {
	DynamicArray<int> D;
	char again;
	int choice;
	int element;
	do {
		cout << "\t\t1)insert an element	   : " << endl;
		cout << "\t\t2)search for an element   : " << endl;
		cout << "\t\t3)delete an element	   : " << endl;
		cout << "\t\t4)display all the elements: " << endl;
		cout << "\t\t5)sort the array          : " << endl;
		cout << "\t\t6)The Number of elements  : " << endl;
		cout << "\t\t7)The size of the Array   : " << endl;
		cout << "\t\t8)Quit					   : " << endl;
		cout << "Enter your task : ";
		cin >> choice;
		switch (choice) {
		case 1: {cout << "Insert the element : "; cin >> element;
			D.insertElement(element); } break;
		case 2: {cout << "Insert the element : "; cin >> element;
			D.searchElement(element); } break;
		case 3: {cout << "Insert the element : "; cin >> element;
			D.deleteElement(element); } break;
		case 4: D.displayArray(); break;
		case 5: D.sortArray(); break;
		case 6: cout << "the Number of elements is : " << D.getNbElements() << endl; break;
		case 7: cout << "the size of the array is : " << D.getSize() << endl; break;
		case 8: {cout << "thank you for your visiting."; exit(EXIT_SUCCESS); } break;
		default: cout << "The number entered does not exist";
		}


		cout << "Do you want another task ? : "; cin >> again;
	} while (again == 'y' || again == 'Y');

	cin.get();
}*/