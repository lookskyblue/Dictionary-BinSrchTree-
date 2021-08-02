#pragma once
#include "BinaryNode.h"

class BinaryTree {
protected:
	BinaryNode* root;

public:
	BinaryTree() :
		root(nullptr) {}

	bool isEmpty() { return root == nullptr; }
	void inorder(BinaryNode* n) {
		if (n == nullptr)
			return;

		inorder(n->getLeft());
		n->display();
		inorder(n->getRight());
	}
};