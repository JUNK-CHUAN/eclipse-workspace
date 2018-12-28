/*
 * SALdict.h
 *
 *  Created on: Dec 24, 2018
 *      Author: junk_chuan
 */

#ifndef SALDICT_H_
#define SALDICT_H_

#include <assert.h>
#include "Dictionary.h"
#include "KVpair.h"
#include "AList.h"

// Sorted array-based list
// Inherit from AList as a protected base class
template <typename Key, typename E>
class SAList: protected AList<KVpair<Key,E> > {
public:
	// Constructor & Destructor
	SAList(int size=defaultSize) :
		AList<KVpair<Key,E> >(size) {}
	~SAList() {}

	// Redefine insert function to keep values sorted
	void insert(KVpair<Key,E>& it) {       // Insert at right
		KVpair<Key,E> curr;
		for (moveToStart(); currPos() < length(); next()) {
			curr = getValue();
			if(curr.key() > it.key())
				break;
		}
		AList<KVpair<Key,E> >::insert(it); // Do AList insert
	}

	// With the exception of append, all remaining methods are
	// exposed from AList. Append is not available to SAlist
	// class users since it has not been explicitly exposed.
	AList<KVpair<Key,E> >::clear;
	AList<KVpair<Key,E> >::remove;
	AList<KVpair<Key,E> >::moveToStart;
	AList<KVpair<Key,E> >::moveToEnd;
	AList<KVpair<Key,E> >::prev;
	AList<KVpair<Key,E> >::next;
	AList<KVpair<Key,E> >::length;
	AList<KVpair<Key,E> >::currPos;
	AList<KVpair<Key,E> >::moveToPos;
	AList<KVpair<Key,E> >::getValue;
};


// Dictionary implemented with a sorted array-based list
template <typename Key, typename E>
class SALdict : public Dictionary<Key, E> {
private:
	SAList<Key,E>* list;

public:
	SALdict(int size=defaultSize)   // Constructor
    { list = new SAList<Key,E>(size); }
	~SALdict() { delete list; }     // Destructor
	void clear() { list->clear(); } // Reinitialize

	// Insert an element: Keep elements sorted
	void insert(const Key&k, const E& e) {
		KVpair<Key,E> temp(k, e);
		list->insert(temp);
	}

	// Use sequential search to find the element to remove
	E remove(const Key& k) {
		E temp = find(k);
		if (temp != NULL) list->remove();
		return temp;
	}

	// Remove the last element
	E removeAny() {
		Assert(size() != 0, "Dictionary is empty");
		list->moveToEnd();
		list->prev();
		KVpair<Key,E> e = list->remove();
		return e.value();
	}

	// Find "K" using binary search
	E find(const Key& k) const {
		int l = -1;
		int r = list->length();
		while (l+1 != r) { // Stop when l and r meet
			int i = (l+r)/2; // Check middle of remaining subarray
			list->moveToPos(i);
			KVpair<Key,E> temp = list->getValue();
			if (k < temp.key()) r = i;        // In left
			if (k == temp.key()) return temp.value(); // Found it
			if (k > temp.key()) l = i;        // In right
		}
		return NULL; // "k" does not appear in dictionary
	}

	// Return list size
	int size() { return list->length(); }
};



#endif /* SALDICT_H_ */
