#pragma once
#include<conio.h>
#include<cstdio>
#include "Dictionary.h"

void help() {
	printf("[����] i-�߰� d-���� w-�ܾ�˻� m-�ǹ̰˻� p-��� -q���� =>");
}

void startDic() {
	char command;
	char word[90];
	char meaning[200];
	Dictionary tree;

	do {
		help();
		command = _getche();
		printf("\n");

		switch (command) {
		case 'i':
			printf("   > ���� �ܾ�: "); gets_s(word);
			printf("   > �ܾ� ����: "); gets_s(meaning);
			tree.insert(new BinaryNode(word, meaning));
			break;

		case 'd':
			printf("   > ���� �ܾ�: "); gets_s(word);
			tree.remove(word);
			break;

		case 'p':
			tree.printAllWords();
			printf("\n");
			break;

		case 'w':
			printf("   > �ܾ� �˻�: "); gets_s(word);
			tree.searchWord(word);
			break;

		case 'm':
			printf("   > �ǹ� �˻�: "); gets_s(word);
			tree.searchMeaning(word);
			break;
		}
	} while (command != 'q');
}

void main() {
	startDic();
}