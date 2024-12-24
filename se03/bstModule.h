#ifndef BST_H
#define BST_H
#include "lRefModule.h"

typedef struct tNode
{
	struct tNode *left, *right;
	char *word;
	LNode *head;
} TNode;

void bstAdd(TNode **rootPtr, char *namWord, Book *ref);
void bstBalance(TNode **rootPtr);
LNode *bstSearch(TNode *root, char *namWord);
void bstFree(TNode *root);

#endif
