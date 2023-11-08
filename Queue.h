//
// Created by st0rm on 01.11.23.
//

#ifndef LAB3_QUEUE_H
#define LAB3_QUEUE_H
class Queue {
private:
    static const int MAX_SIZE = 100;
    int elements[MAX_SIZE];
    int front;
    int rear;

public:
    Queue() : front(-1), rear(-1) {}

    bool isEmpty() {
        return front == -1 && rear == -1;
    }

    bool isFull() {
        return (rear + 1) % MAX_SIZE == front;
    }

    void enqueue(int item) {

        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % MAX_SIZE;
        }
        elements[rear] = item;
    }

    int dequeue() {

        int item = elements[front];
        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % MAX_SIZE;
        }
        return item;
    }
};

#endif //LAB3_QUEUE_H
