/*
 * LQueue.h
 *
 *  Created on: Dec 23, 2018
 *      Author: junk_chuan
 */

#ifndef LQUEUE_H_
#define LQUEUE_H_

#include <stdlib.h>
#include "Queue.h"


//Singly linked list node
template <typename E>
class Link
{
private:
    static Link<E>* freelist;
public:
    // Value for this node
    E element;
    // Pointer to next node in list
    Link *next;

    // Constructor
    Link(const E& elemval, Link* nextval = NULL)
    {element = elemval; next = nextval;}
    Link(Link* nextval = NULL)
    {next = nextval;}

    void* operator new(size_t)
    {
        if(freelist == NULL) return ::new Link;
        Link<E>* temp = freelist;
        freelist = freelist->next;
        return temp;
    }

    void operator delete(void* plt)
    {
        ((Link<E>*)plt)->next = freelist;
        freelist = (Link<E>*)plt;
    }
};

template <typename E>
Link<E>* Link<E>::freelist = NULL;



// Linked queue implementation
template <typename E>
class LQueue: public Queue<E> {
private:
	Link<E>* front; // Pointer to front queue node
	Link<E>* rear;  // Pointer to rear queue node
	int size;       // Number of elements in queue

public:
	LQueue(int sz =defaultSize)          // Constructor
    	{ front = rear = new Link<E>(); size = 0; }
	~LQueue() { clear(); delete front; } // Destructor

	// Clear queue
	void clear() {
		while(front->next != NULL) { // Delete each link node
			rear = front;
			delete rear;
		}
		rear = front;
		size = 0;
	}

	// Put element on rear
	void enqueue(const E& it) {
		rear->next = new Link<E>(it, NULL);
		rear = rear->next;
		size++;
	}

	// Remove element from front
	E dequeue() {
		Assert(size != 0, "Queue is empty");
		E it = front->next->element;     // Store dequeued value
		Link<E>* ltemp = front->next;    // Hold dequeued link
		front->next = ltemp->next;       // Advance front
		if (rear == ltemp) rear = front; // Dequeue last element
		delete ltemp;                    // Delete link
		size --;
		return it;                       // Return element value
	}

	// Get front element
  	const E& frontValue() const {
  		Assert(size != 0, "Queue is empty");
  		return front->next->element;
  	}
  	int length() const { return size; }
};


#endif /* LQUEUE_H_ */
