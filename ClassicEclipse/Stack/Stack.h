//
// Created by 杨小川 on 2018/10/30.
//

#ifndef STACK_STACK_H
#define STACK_STACK_H

#include<iostream>
#include<stdlib.h>

using namespace std;


// Stack abstract class
template <typename E>
class Stack
{
private:
    void operator =(const Stack&) {}  // Protect assignment
    Stack(const Stack&) {}            // Protect copy constructor

public:
    Stack() {}          // Constructor
    virtual ~Stack() {} // Destructor

    // Reinitialize the stack. The user is responsible for
    // reclaiming the storage used by the stack elements.
    virtual void clear() = 0;

    // Push an element onto the top of the stack.
    // it: The element being pushed onto the stack.
    virtual void push(const E&) = 0;

    // Remove the element at the top of the stack.
    // Return: The element at the top of the stack.
    virtual E pop() = 0;

    // Return: A copy of the top element.
    virtual const E& topValue() const = 0;

    // Return: The number of elements in the stack.
    virtual int length() const = 0;
};


#endif //STACK_STACK_H
