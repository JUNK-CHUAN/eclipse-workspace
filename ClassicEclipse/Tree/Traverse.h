/*
 * Traverse.h
 *
 *  Created on: Dec 24, 2018
 *      Author: junk_chuan
 */

#ifndef TRAVERSE_H_
#define TRAVERSE_H_

#include <iostream>
#include <cstdlib>
#include "BSTNode.h"


template <typename E>
void preorder(BinNode<E>* root) {
	if (root == NULL) return; // Empty subtree, do nothing
	visit(root);              // Perform desired action
	preorder(root->left());
	preorder(root->right());
}

template <typename E>
void preorder2(BinNode<E>* root) {
	visit(root);  // Perform whatever action is desired
	if (root->left() != NULL) preorder2(root->left());
	if (root->right() != NULL) preorder2(root->right());
}

template <typename E>
int count(BinNode<E>* root) {
	if (root == NULL) return 0;  // Nothing to count
    return 1 + count(root->left()) + count(root->right());
}

template <typename Key, typename E>
bool checkBST(BSTNode<Key,E>* root, Key low, Key high) {
	if (root == NULL) return true; // Empty subtree
	Key rootkey = root->key();
	if ((rootkey < low) || (rootkey > high))
		return false; // Out of range
	if (!checkBST<Key,E>(root->left(), low, rootkey))
		return false; // Left side failed
	return checkBST<Key,E>(root->right(), rootkey, high);
}


template <typename E>
void visit(BinNode<E>* root) {
	std::cout << 1;
}

#endif /* TRAVERSE_H_ */
