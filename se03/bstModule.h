#ifndef BST_H
#define BST_H
#include "lRefModule.h"
#include "SE1.h"
#include "SE2.h"

typedef struct tNode
{
	struct tNode *left, *right;
	char *word;
	LNode *head;
} TNode;

void bstAdd(TNode **rootPtr, char *namWord, BookSE3 *ref);
void bstBalance(TNode **rootPtr);
LNode *bstSearch(TNode *root, char *namWord);
void bstFree(TNode *root);

#endif
