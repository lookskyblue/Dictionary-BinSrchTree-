#pragma once
#include"BinaryTree.h"

class BinSrchTree : public BinaryTree {

public:

/*
	BinaryNode* search(char key[]) { return searchRecur(root, key); }
	BinaryNode* searchRecur(BinaryNode* n, char key[])
	{
		if (n == nullptr)
			return nullptr;

		else if (n->compare(key) == 0)
			return n;

		else if (n->compare(key) < 0)
			return searchRecur(n->getLeft(), key);

		else
			return searchRecur(n->getRight(), key);
	}
	void insert(BinaryNode* n) 
	{ 
		if (isEmpty())
			root = n;

		else if (n == nullptr)
			return;

		else
			insertRecur(root, n);
	}
	void insertRecur(BinaryNode* r, BinaryNode* n) 
	{
		if (r->compare(n) == 0)
			return;

		else if (r->compare(n) < 0) {
			if (r->getLeft() == nullptr) r->setLeft(n);
			else insertRecur(r->getLeft(), n);
		}

		else {
			if (r->getRight() == nullptr) r->setRight(n);
			else insertRecur(r->getRight(), n);
		}
}
*/
	void remove(char key[])
	{
		if (isEmpty()) return;

		BinaryNode* parent = nullptr;
		BinaryNode* node = root;

		while (node != nullptr && node->compare(key) != 0)
		{
			parent = node;
			node = (node->compare(key) < 0) ? node->getLeft() : node->getRight();
		}

		if (node != nullptr)
			remove(parent, node);
	}
	void remove(BinaryNode* p, BinaryNode* n) 
	{
		// case1: 삭제할 노드가 단말노드이다.
		if (n->isLeaf()) {
			if (p == nullptr)
				root = nullptr;

			else {
				if (p->getLeft() == n)
					p->setLeft(nullptr);

				else
					p->setRight(nullptr);
			}
		}

		else if (n->getLeft() == nullptr || n->getRight() == nullptr) {
		
			BinaryNode* child = (n->getLeft() != nullptr) ? n->getLeft() : n->getRight();
			
			if (n == root) root = child;

			else {
				if (p->getLeft() == n)
					p->setLeft(child);

				else
					p->setRight(child);

			}
		}

		else {
			
			BinaryNode* succp = n;
			BinaryNode* succ = n->getRight();

			while (succ->getLeft() != nullptr)
			{
				succp = succ;
				succ = succ->getLeft();
			}

			if (succp->getLeft() == succ)
				succp->setLeft(succ->getRight());

			else
				succp->setRight(succ->getRight());

			n->copy(succ);
			n = succ;
		}

		delete n;
	}

	BinaryNode* search(char key[MAX_WORD_SIZE]);
	void insert(BinaryNode* n);
};

BinaryNode* BinSrchTree::search(char key[MAX_WORD_SIZE]) { return root->search(key); }

void BinSrchTree::insert(BinaryNode* n)
{
	if (isEmpty()) root = n;

	else if (n == nullptr) return;

	else
		root->insert(n);
}