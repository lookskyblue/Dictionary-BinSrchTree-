#pragma once
#include "BinaryNode2.h"

class BinaryTree {
protected:
	BinaryNode* root;

public:
	void inorder();
	void preorder();
	void postorder();
	bool isEmpty() { return root == nullptr; }

	int getCount();
	int getHeight();
	int getLeafCount();
};

void BinaryTree::inorder() {
	printf("\n inorder: ");
	if (!isEmpty()) root->inorder();
}

void BinaryTree::preorder() {
	printf("\n preorder: ");
	if (!isEmpty()) root->preorder();
}

void BinaryTree::postorder() {
	printf("\n postorder: ");
	if (!isEmpty()) root->postorder();
}

int BinaryTree::getCount() {
	printf("\n getCount: ");
	if (!isEmpty()) root->getCount();
}

int BinaryTree::getHeight() {
	printf("\n getHeight: ");
	if (!isEmpty()) root->getHeight();
}

int BinaryTree::getLeafCount() {
	printf("\n getHeight: ");
	if (!isEmpty()) root->getLeafCount();
}

