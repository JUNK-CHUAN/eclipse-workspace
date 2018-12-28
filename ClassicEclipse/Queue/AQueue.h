/*
 * AQueue.h
 *
 *  Created on: Dec 23, 2018
 *      Author: junk_chuan
 */

#ifndef AQUEUE_H_
#define AQUEUE_H_

#include <assert.h>
#include "Queue.h"

// Array-based queue implementation
template <typename E>
class AQueue: public Queue<E> {
private:
	int maxSize;  // Maximum size of queue
	int front;    // Index of front element
	int rear;     // Index of rear element
	E *listArray; // Array holding queue elements


public:
	AQueue(int size =defaultSize) {     // Constructor
		// Make list array one position larger for empty slot
	  maxSize = size+1; rear=0; front=1;
	  listArray = new E[maxSize];
	}
	~AQueue() { delete [] listArray; }  // Destructor
	void clear() { rear = 0; front = 1; } // Reinitialize

	// Put "it" in queue
	void enqueue(const E& it) {
		Assert(((rear+2) % maxSize) != front, "Queue is full");
		rear = (rear+1) % maxSize;      // Circular increment
		listArray[rear] = it;
	}

	// Take element out
	E dequeue() {
		Assert(length() != 0, "Queue is empty");
		E it = listArray[front];
		front = (front+1) % maxSize;    // Circular increment
		return it;
	}

	// Get front value
	const E& frontValue() const {
		Assert(length() != 0, "Queue is empty");
		return listArray[front];
	}

	// Return length
	int length() const
	{ return ((rear+maxSize) - front + 1) % maxSize; }
};


#endif /* AQUEUE_H_ */
