/*
 * KVpair.h
 *
 *  Created on: Dec 23, 2018
 *      Author: junk_chuan
 */

#ifndef KVPAIR_H_
#define KVPAIR_H_


// Container for a key-value pair
template <typename Key, typename E>
class KVpair {
private:
	Key k;
	E e;

public:
	// Constructors
	KVpair() {}
	KVpair(Key kval, E eval)
    	{ k = kval; e = eval; }
	KVpair(const KVpair& o)  // Copy constructor
    	{ k = o.k; e = o.e; }

	// Assignment operator
	void operator =(const KVpair& o)
    	{ k = o.k; e = o.e; }

	// Data member access functions
	Key key() { return k; }

	void setKey(Key ink) { k = ink; }

	E value() { return e; }
};


#endif /* KVPAIR_H_ */
