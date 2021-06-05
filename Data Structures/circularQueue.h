#ifndef _CIRCUALR_QUEUE
#define _CIRCUALR_QUEUE

#include<iostream>

class circularQueue {
	int* q;
	int rear, front,size;
public :
	circularQueue();
	circularQueue(int);
	~circularQueue();
	circularQueue(const circularQueue&);
	void enqueue(int);
	void dequeue();
	bool isEmpty();
	bool isFull();
	void DisplayQueue();
	int getFront()const;
	int getRear() const;
};

#endif // !_CIRCUALR_QUEUE
