//
// Created by 杨小川 on 2018/10/28.
//

#ifndef DLIST_DLIST_H
#define DLIST_DLIST_H


#include<iostream>
#include"List.h"
using namespace std;

// Doubly linked list link node with freelist support
template <typename E>
class DLink
{
private:
    static DLink<E>* freelist; // Reference to freelist head
public:
    E element; // Value for this node
    DLink* next; // Pointer to next node in list
    DLink* prev; // Pointer to previous node

    // Constructors
    DLink(const E& it, DLink* prevp, DLink* nextp) {
        element = it;
        prev = prevp;
        next = nextp;
    }
    DLink(DLink* prevp =NULL, DLink* nextp =NULL) {
        prev = prevp;
        next = nextp;
    }

    void* operator new(size_t) { // Overloaded new operator
        if (freelist == NULL) return ::new DLink; // Create space
        DLink<E>* temp = freelist; // Can take from freelist
        freelist = freelist->next;
        return temp; // Return the link
    }
    // Overloaded delete operator
    void operator delete(void* ptr) {
        ((DLink<E>*)ptr)->next = freelist; // Put on freelist
        freelist = (DLink<E>*)ptr;
    }
};

// The freelist head pointer is actually created here
template <typename E>
DLink<E>* DLink<E>::freelist = NULL;



template<typename E>
class DList : public List<E>
{
private:
    DLink<E>* head; // Pointer to list header
    DLink<E>* tail; // Pointer to last header
    DLink<E>* curr; // Access to current element
    int cnt;        // Size of list

    // Initialization helper method
    void init() {
        curr = head = new DLink<E>;
        head->next = tail = new DLink<E>;
        tail->prev = head;
        cnt = 0;
    }
    // Return link nodes to free store
    void removeall() {
        while (head != NULL) {
            curr = head;
            head = head->next;
            delete curr;
        }
    }

public:
    DList() { init(); } // Constructor
    ~DList() { removeall(); } // Destructor
    void print() const; // Print list contents
    void clear() { removeall(); init(); } // Clear list

    // Insert "it" at current position
    void insert(const E& it) {
        curr->next = curr->next->prev = new DLink<E>(it, curr, curr->next);
        cnt++;
    }
    // Append "it" to list
    void append(const E& it) {
        tail->prev = tail->prev->next = new DLink<E>(it, tail->prev, tail);
        cnt++;
    }

    // Remove and return current element
    E remove() {
        assert (curr->next == tail);
        E it = curr->next->element;    // Remember value
        DLink<E>* ltemp = curr->next;  // Remember link node
        curr->next->next->prev = curr;
        curr->next = curr->next->next; // Remove from list
        delete ltemp;                  // Reclaim space
        cnt--;                         // Decrement the count
        return it;
    }

    // Place curr at list start or end
    void moveToStart() { curr = head; }
    void moveToEnd() { curr = tail->prev; }
    // Move curr one step left; no change if already at front
    void prev() {
        if (curr == head) return; // No previous element
        curr = curr->prev;
    }
    // Move curr one step right; no change if already at end
    void next() {
        if (curr->next == tail)return;
        curr = curr->next;
    }

    int length() const { return cnt; } // Return length

    // Return the position of current element
    int currPos() const {
        DLink<E>* temp = head;
        int i;
        for (i = 0; curr != temp; i++) temp = temp->next;
        return i;
    }

    // Move down list to "pos" position
    void moveToPos(int pos) {
        assert((pos >= 0 && pos <= cnt));
        curr = head;
        for (int i = 0; i < pos; i++) curr = curr->next;

    }
    // Return current element
    E& getValue() const {
        assert(curr->next != tail);
        return curr->next->element;
    }

    // Added functional method with bubble sort
    void sort() {
        DLink<E> *pos;
        E temp;
        DLink<E> *pend = tail;

        for (int i = 0; i < cnt; i++) {
            for (pos = head; pos->next->next != pend; pos = pos->next) {
                if (pos->next->element.getIndex() > pos->next->next->element.getIndex()) {
                    temp = pos->next->element;
                    pos->next->element = pos->next->next->element;
                    pos->next->next->element = temp;
                }
            }
            pend = pend->prev;
        }
    }
};


#endif //DLIST_DLIST_H
