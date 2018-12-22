/*
 * KVpair.h
 *
 *  Created on: Dec 22, 2018
 *      Author: junk_chuan
 */

#ifndef PAIR_H_
#define PAIR_H_


template<typename Coeft, typename Index>
class KVpair
{
private:
    Coeft k;
    Index e;
public:
    // Constructors
    KVpair() {}
    KVpair(Coeft kval, Index eval) {
        k = kval;
        e = eval;
    }
    // Copy constructor
    KVpair(const KVpair& o) {
        k = o.k;
        e = o.e;
    }

    void operator =(const KVpair& o) {
        k = o.k;
        e = o.e;
    }

    // Data member access functions
    Coeft coeffeicient() {
        return k;
    }
    void setcoeft(Coeft kval) {
        k = kval;
    }
    Index getIndex() {
        return e;
    }
    void setIndex(Index eval) {
        e = eval;
    }
};


#endif /* PAIR_H_ */
