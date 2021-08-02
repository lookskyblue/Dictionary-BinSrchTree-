#pragma once
#include <cstdio>

class BinaryNode {
private:
	int data;
	BinaryNode* left;
	BinaryNode* right;

public:
	BinaryNode(int val, BinaryNode* L, BinaryNode* R) :
		data(val),
		left(L),
		right(R) {}

	void setData(int val) { data = val; }
	void setLeft(BinaryNode* L) { left = L; }
	void setRight(BinaryNode* R) { right = R; }

	int getData() { return data; }
	BinaryNode* getLeft() { return left; }
	BinaryNode* getRight() { return right; }

	bool isLeaf() { return left == nullptr && right == nullptr; }

	void inorder() {}
	void preorder() {}
	void postorder() {}
	
	int getCount() {}
	int getHeight() {}
	int getLeafCount() {}
};

void BinaryNode::inorder() {
	if (left != nullptr) left->inorder();
	printf("%d ", data);
	if (right != nullptr) right->inorder();
}

void BinaryNode::preorder() {
	printf("%d ", data);
	if (left != nullptr) left->inorder();
	if (right != nullptr) right->inorder();
}

void BinaryNode::postorder() {
	if (left != nullptr) left->inorder();
	if (right != nullptr) right->inorder();
	printf("%d ", data);
}

int BinaryNode::getCount() {
	if (this == nullptr) return 0;
	return 1 + left->getCount() + right->getCount();
}

int BinaryNode::getHeight() {
	if (this == nullptr) return 0;
	
	int hLeft = left->getHeight();
	int hRight = right->getHeight();

	return (hLeft < hRight) ? 1 + hLeft : 1 + hRight;

//	return 1 + (left->getHeight() < right->getHeight()) ? right->getHeight() : left->getHeight(); 한줄로 끝낼 수 있지만 가독성이 안 좋아.
}

int BinaryNode::getLeafCount() {
	if (this == nullptr) return 0;
	if (this->isLeaf()) return 1;
	else
		return left->getLeafCount() + right->getLeafCount();
}