//
// Created by 杨小川 on 2018/12/16.
//

#ifndef GRAPH_AQUEUE_H
#define GRAPH_AQUEUE_H

// Array-based queue implementation
class AQueue {
private:
    int maxsize;
    int front;
    int  rear;
    int *listArray;

public:
    AQueue(int size) {
        maxsize = size + 1;
        rear = 0;
        front = 1;
        listArray = new int[maxsize];
    }
    ~AQueue() { delete [] listArray; }

    void clear() {
        rear = 0;
        front = 1;
    }

    void enqueue(const int& it) {
        rear = (rear+1) % maxsize;
        listArray[rear] = it;
    }

    int dequeue() {
        int it = listArray[front];
        front = (front+1) % maxsize;
        return it;
    }

    const int& frontValue() const { return listArray[front]; }

    int length() const { return ((rear + maxsize) - front + 1) % maxsize; }
};


#endif //GRAPH_AQUEUE_H
