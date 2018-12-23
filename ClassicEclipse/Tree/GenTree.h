//
// Created by 杨小川 on 2018/10/31.
//

#ifndef TREE_GENERAL_GENTREE_H
#define TREE_GENERAL_GENTREE_H

#include "GTNode.h"


// General tree ADT
template  <typename  E>
class  GenTree {
public:
    void clear();                               // Send all nodes to free store
    GTNode<E>* root();                // Return the root of the tree
    // Combine two subtrees
    void newroot(E&, GTNode<E>*, GTNode<E>*);
    void print();                                // Print a tree
};

#endif //TREE_GENERAL_GENTREE_H
