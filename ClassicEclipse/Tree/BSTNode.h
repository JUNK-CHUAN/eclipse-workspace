//
// Created by 杨小川 on 2018/12/2.
//

#ifndef TREE_BINARY_BSTNODE_H
#define TREE_BINARY_BSTNODE_H

#include <cstdlib>
#include "BinNode.h"


// Simple binary tree node implementation
template <typename Key, typename E>
class BSTNode: public BinNode<E> {
private:
    Key k;
    E it;
    BSTNode* lc;
    BSTNode* rc;

public:
    BSTNode() { lc = rc = NULL; }
    BSTNode(Key K, E e, BSTNode* l = NULL, BSTNode* r = NULL) {
        k = K;
        it = e;
        lc = l;
        rc = r;
    }
    ~BSTNode() {}

    E& element() { return it; }
    void setElement(const E& e) { it = e; }
    Key& key() { return k; }
    void setKey(const Key& K) { k = K; }

    inline BSTNode* left() const { return lc; }
    void setLeft(BinNode<E>* b) { lc = (BSTNode*)b; }
    inline BSTNode* right() const { return rc;}
    void setRight(BinNode<E>* b) { rc = (BSTNode*)b; }

    bool isLeaf() { return (lc == NULL) && (rc == NULL); }
};


#endif //TREE_BINARY_BSTNODE_H
