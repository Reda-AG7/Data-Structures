#ifndef _QUEUE_ARRAY
#define _QUEUE_ARRAY
#include <iostream>
class  Queue {
    int size;
    int* q;
    int rear, front;
public:
    Queue();
    Queue(int);
    ~Queue();
    void enqueue(int);
    void dequeue();
    bool isEmpty();
    bool isFull();
    int getFront() const;
    int getRear() const;
    void displayQueue();
};

#endif // !_QUEUE_ARRAY

