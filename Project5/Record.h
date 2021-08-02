#pragma once
#include<cstdio>
#include<cstring>

#define MAX_WORD_SIZE 40
#define MAX_MEANING_SIZE 200

class Record {
private:
	char word[MAX_WORD_SIZE];
	char meaning[MAX_MEANING_SIZE];

public:
	Record(char word[MAX_WORD_SIZE], char meaning[MAX_MEANING_SIZE])	{ set(word, meaning); }

	char* getWord() { return word; }
	char* getMeaning() { return meaning; }

	void set(char w[], char m[]) {
		strcpy_s(word, strlen(w)+1, w);
		strcpy_s(meaning, strlen(m)+1, m);
	}

	int compare(Record* n) { return compare(n->word); }
	int compare(char w[MAX_WORD_SIZE]) { return strcmp(w, word); }
	int compareMeaning(char m[MAX_MEANING_SIZE]) { return strcmp(meaning, m); }

	void display() { printf(" %12s : %-40s\n", word, meaning); }
	void copy(Record* n) { set(n->word, n->meaning); }
};