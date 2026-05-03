#include "hello.hpp"
#include <iostream>

QueueTees::QueueTees(int size) {
    capacity = size;
    data.resize(capacity);
    front = 0;
    rear = -1;
    count = 0;
}

bool QueueTees::isFull() {
    return count == capacity;
}

bool QueueTees::isEmpty() {
    return count == 0;
}

void QueueTees::enqueue(Cutie* item) {
    if (isFull()) {
        std::cout << "Queue is full!" << std::endl;
        return;
    }

    rear = (rear + 1) % capacity;
    data[rear] = item;
    count++;
}

Cutie* QueueTees::dequeue() {
    if (isEmpty()) {
        std::cout << "Queue is empty!" << std::endl;
        return nullptr;
    }

    Cutie* item = data[front];
    front = (front + 1) % capacity;
    count--;

    return item;
}

int QueueTees::size() {
    return count;
}