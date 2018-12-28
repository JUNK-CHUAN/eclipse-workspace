//
// Created by 杨小川 on 2018/11/3.
//

#ifndef STACK_LSTACK_H
#define STACK_LSTACK_H

#include <assert.h>
#include <cstdio>
#include "Stack.h"


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



// Linked stack implementation
template <typename E>
class LStack: public Stack<E> {
private:
    Link<E>* top;
    int size;                   // The size of Link Stack
    static const int defaultsize = 100; // Set defaultsize
public:
    // Constructor
    LStack(int sz =defaultsize) {
        top = NULL;
        size = 0;
    }
    // Destructor
    ~LStack() {
        clear();
    }

    // Reinitialize
    void clear() {
        while (top != NULL) {
            Link<E>* temp = top;
            top = top->next;
            delete temp;
        }
        size = 0;
    }

    // Put "it" on stack
    void push(const E& it) {
        top = new Link<E>(it, top);
        size++;
    }

    // Remove "it" from stack
    E pop() {
        //Assert(top != NULL, "Stack is empty");
        assert(top != NULL);
        E it = top->element;
        Link<E>* ltemp = top->next;
        delete top;
        top = ltemp;
        size--;
        return it;
    }

    // Return top value
    const E& topValue() const {
        //Assert(top != NULL, "Stack is empty");
        assert(top != NULL);
        return top->element;
    }

    // Return length
    int length() const {
        return size;
    }
};



#endif //STACK_LSTACK_H
