#pragma once
#include<conio.h>
#include<cstdio>
#include "Dictionary.h"

void help() {
	printf("[사용법] i-추가 d-삭제 w-단어검색 m-의미검색 p-출력 -q종료 =>");
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
			printf("   > 삽입 단어: "); gets_s(word);
			printf("   > 단어 설명: "); gets_s(meaning);
			tree.insert(new BinaryNode(word, meaning));
			break;

		case 'd':
			printf("   > 삭제 단어: "); gets_s(word);
			tree.remove(word);
			break;

		case 'p':
			tree.printAllWords();
			printf("\n");
			break;

		case 'w':
			printf("   > 단어 검색: "); gets_s(word);
			tree.searchWord(word);
			break;

		case 'm':
			printf("   > 의미 검색: "); gets_s(word);
			tree.searchMeaning(word);
			break;
		}
	} while (command != 'q');
}

void main() {
	startDic();
}