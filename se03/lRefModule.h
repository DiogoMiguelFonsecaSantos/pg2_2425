#ifndef LREF_H
#define LREF_H

#include "SE1.h"
#include "SE2.h"

typedef struct lNode
{
	struct lNode *next; // ligação na lista
	BookSE3 *ref;			// referência de acesso a um descritor de livro
} LNode;

int lRefAdd(LNode **headPtr, BookSE3 *ref);
void lRefPrint(LNode *head);
void lRefFree(LNode *head);

#endif