#pragma once
#include "BinSrchTree.h"

class Dictionary : public BinSrchTree {
public:
	void printAllWords() {
		printf(" >> ���� �ܾ���: \n");
		if (!isEmpty()) inorder(root);
	}

	void searchWord(char word[MAX_WORD_SIZE]) {
		BinaryNode* node = search(word);

		if (node != nullptr) {
			printf("   >>");
			node->display();
		}

		else
			printf("   >> ��ϵ��� ���� �ǹ�: %s \n", word);
	}

	void searchMeaning(char m[MAX_MEANING_SIZE]) {
		BinaryNode* node = (isEmpty() ? nullptr : searchByMeaning(root, m));
			if (node != nullptr) {
				printf("   >>");
				node->display();
			}

			else
				printf("   >> ��ϵ��� ���� �ǹ�: %s \n", m);
	}

	BinaryNode* searchByMeaning(BinaryNode* node, char m[MAX_MEANING_SIZE])
	{
		if (node == nullptr || node->compareMeaning(m) == 0) return node;
		BinaryNode* theNode = searchByMeaning(node->getLeft(), m);
		if (theNode != nullptr) return theNode;
		return searchByMeaning(node->getRight(), m);
	}
};