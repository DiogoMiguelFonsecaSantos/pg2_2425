#ifndef LREF_H
#define LREF_H

typedef struct lNode
{
	struct lNode *next; // ligação na lista
	Book *ref;			// referência de acesso a um descritor de livro
} LNode;

int lRefAdd(LNode **headPtr, Book *ref);
void lRefPrint(LNode *head);
void lRefFree(LNode *head);

#endif