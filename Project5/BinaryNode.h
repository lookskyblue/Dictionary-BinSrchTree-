#pragma once
#include "Record.h"

class BinaryNode : public Record {
private:
	BinaryNode* left;
	BinaryNode* right;

public:
	BinaryNode(char w[], char m[]) :
		Record(w, m),
		left(nullptr),
		right(nullptr) {}

	void setLeft(BinaryNode* l) { left = l; }
	void setRight(BinaryNode* r) { right = r; }
	BinaryNode* getLeft() { return left; }
	BinaryNode* getRight() { return right; }
	bool isLeaf() { return (left == nullptr && right == nullptr); }

	BinaryNode* search(char word[MAX_WORD_SIZE]);
	void insert(BinaryNode* n);
};

BinaryNode* BinaryNode::search(char word[MAX_WORD_SIZE]) {
	if (this == nullptr) return nullptr;
	else if (this->compare(word) == 0) return this;
	else if (this->compare(word) < 0) return left->search(word);
	else return right->search(word);
}

void BinaryNode::insert(BinaryNode* n) {

	if (this->compare(n) == 0)
		return;

	else if (this->compare(n) < 0)
	{
		if (left == nullptr)
			left = n;

		else
			left->insert(n);
	}

	else
	{
		if (right == nullptr)
			right = n;

		else
			right->insert(n);
	}
}

