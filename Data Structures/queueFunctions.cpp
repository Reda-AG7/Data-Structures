#include "queue.h"

Queue::Queue() {
    size = 5;
    q = new int[size];
    rear = front = -1;
}
Queue::Queue(int size) {
    this->size = size;
    q = new int[this->size];
    rear = front = -1;
}
Queue::~Queue() {
    delete[] q;
}
bool Queue::isEmpty() {
    if (rear == front) {
        rear = front = -1;
        return true;
    }   
    else return false;
}
bool Queue::isFull() {
    if (rear == (size - 1) && front == -1)
        return true;
    else {
        if (rear == size - 1 && front > -1) {  //resizing the Queue
            int k = 0;
            for (int i = front + 1; i <= rear; i++)
                q[k++] = q[i];
            front = -1;
            rear = k - 1;
            return false;
        }
        else return false;
        
    }
}
void Queue::enqueue(int x) {
    if (isFull())
        std::cout << "The Queue is Full" << std::endl;
    else {
        q[++rear] = x;
    }
}
void Queue::dequeue() {
    if (!isEmpty())
        ++front;
    else std::cout << "The Queue is Empty" << std::endl;
}
int Queue::getFront() const {
    return q[front + 1];
}
int Queue::getRear() const {
    return q[rear];
}
void Queue::displayQueue() {
    if (isEmpty())
        std::cout << "The queue is Empty" << std::endl;
    else {
        for (int i = front + 1; i <= rear; i++)
            std::cout << q[i] << " ";
    }
    std::cout << "\n";
}
/*
int main() {
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(50);
    q.enqueue(100);
    q.enqueue(240);
    q.displayQueue();
    q.enqueue(340);
    q.dequeue();
    q.displayQueue();
    q.enqueue(340);
    q.displayQueue();
    //q.displayQueue();
    std::cout << q.getFront() << std::endl;
    std::cout << q.getRear();
    std::cin.get();
}*/