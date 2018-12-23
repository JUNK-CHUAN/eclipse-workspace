//
// Created by 杨小川 on 2018/10/30.
//

#ifndef STACK_ASTACK_H
#define STACK_ASTACK_H

#include "Stack.h"
#include <assert.h>



// Array-based stack implementation
template <typename E>
class AStack: public Stack<E>
{
private:
    int maxSize;   // Maximum size of stack
    int top;       // Index for top element
    E* listArray;  // Array holding stack elements
    static const int defaultsize = 100; // Set defaultsize

public:
    // Constructor
    AStack(int size = defaultsize) {
        maxSize = size;
        top = 0;
        listArray = new E[size];
    }

    // Destructor
    ~AStack() {
        delete [] listArray;
    }

    // Reinitialize
    void clear() {
        top = 0;
    }

    // Put "it" on stack
    void push(const E& it) {
        //Assert(top != 0, "Stack is empty");
        listArray[top++] = it;
    }

    // Pop top element
    E pop() {
        //Assert(top != 0, "Stack is empty");
        assert(top != 0);
        return listArray[top-1];
    }

    // Return top element
    const E& topValue() const {
        assert(top != 0);
        return listArray[top-1];
    }

    // Return length
    int length() const { return top; }
};


#endif //STACK_ASTACK_H
