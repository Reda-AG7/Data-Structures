#include "circularQueue.h"

//Default constructor
circularQueue::circularQueue() :size(5), front(0), rear(0), q(new int[size]) {}

// Constructor with arguments
circularQueue::circularQueue(int s) : size(s), rear(0), front(0), q(new int[size]) {}

// Copy Constructor
circularQueue::circularQueue(const circularQueue& oldQueue) {
	size = oldQueue.size;
	rear = oldQueue.rear;
	front = oldQueue.front;
	q = new int[size];
	for (int i = 0; i < size; i++) {
		q[i] = oldQueue.q[i];
	}
}
//Destructor
circularQueue::~circularQueue() {
	delete[] q;
}

bool circularQueue::isFull() {
	if ((front == 0 && rear == size - 1) || (rear == front - 1)) 
		return true;
	else 
		return false;
}
bool circularQueue::isEmpty() {
	if (front == rear )
		return true;
	else 
		return false;
}
////enqueue
//void circularQueue::enqueue(int x) {
//	if (isFull())
//		std::cout << "The queue is Full" << std::endl;
//	else {
//		if (rear == size - 1) {
//			rear = 0;
//			q[rear] = x;
//		}
//		else
//			q[++rear] = x;
//	}
//}
//enqueue
void circularQueue::enqueue(int x) {
	if (isFull())
		std::cout << "The queue is Full" << std::endl;
	else {
		rear = (rear + 1) % size;
		q[rear] = x;
	}
}
//dequeue
//void circularQueue::dequeue() {
//	if (isEmpty())
//		std::cout << "The queue is Empty" << std::endl;
//	else {
//		if (front == size - 1)
//			front = 0;
//		else
//			++front;
//	}	
//}
void circularQueue::dequeue() {
	if (isEmpty())
		std::cout << "The queue is Empty" << std::endl;
	else {
		front = (front + 1) % size;
	}	
}
//DisplayQueue:
void circularQueue::DisplayQueue() {
	if(isEmpty())
		std::cout << "The queue is Empty" << std::endl;
	else {
		if (front > rear) {
			for (int i = front + 1; i < size; i++)
				std::cout << q[i] << " ";
			for (int i = 0; i <= rear; i++)
				std::cout << q[i] <<" ";
		}
		else {
			std::cout << std::endl;
			for (int i = front+1; i <= rear; i++)
				std::cout << q[i] << " ";
		}
	}
	std::cout << std::endl;
}
int circularQueue::getFront() const {
	return q[front+1];
}
int circularQueue::getRear() const {
	return q[rear];
}
//int main() {
//	circularQueue q;
//	q.enqueue(10);
//	q.enqueue(20);
//	q.enqueue(60);
//	q.enqueue(90);
//	q.DisplayQueue();
//	q.dequeue();
//	q.DisplayQueue();
//	q.enqueue(180);
//	q.DisplayQueue();
//	q.dequeue();
//	q.DisplayQueue();
//	q.enqueue(250);
//	q.DisplayQueue();
//	std::cout << "front : " << q.getFront() << std::endl;
//	std::cout << "rear : " << q.getRear() << std::endl;
//	std::cin.get();
//}