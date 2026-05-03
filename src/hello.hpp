#ifndef HELLO_HPP
#define HELLO_HPP

#include <vector>
#include "cutie.hpp"

class QueueTees {
private:
    std::vector<Cutie*> data;
    int front;
    int rear;
    int capacity;
    int count;

public:
    QueueTees(int size = 10);

    void enqueue(Cutie* item);
    Cutie* dequeue();
    int size();

    bool isFull();
    bool isEmpty();
};

#endif