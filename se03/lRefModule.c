#include <stdio.h>
#include <stdlib.h>
#include "bookModule.h"
#include "lRefModule.h"

int lRefAdd(LNode **headPtr, Book *ref)
{

    LNode *newNode = malloc(sizeof(LNode));
    if (!newNode)
        return 0;

    newNode->ref = ref;
    newNode->next = NULL;

    // Caso a lista esteja vazia, o novo nó será a cabeça
    if (!*headPtr)
    {
        *headPtr = newNode;
        return 1;
    }

    // Procura o local correto para inserir o novo nó (ordem alfabética por título)
    LNode *current = *headPtr, *previous = NULL;
    while (current && strcmp(ref->title, current->ref->title) > 0)
    {
        previous = current;
        current = current->next;
    }

    // Verifica se o livro já está na lista
    if (current && strcmp(ref->title, current->ref->title) == 0)
    {
        free(newNode); // O livro já existe; não adiciona duplicatas
        return 0;
    }

    // Insere o novo nó na lista
    if (previous)
    {
        previous->next = newNode;
    }
    else
    {
        *headPtr = newNode; // Atualiza a cabeça da lista
    }
    newNode->next = current;

    return 1;
}

void lRefPrint(LNode *head)
{
    while (head)
    {
        Book *book = head->ref;
        printf("Título: %s, ISBN: %s, Autores: %s, Editor: %s\n",
               book->title, book->isbn, book->authors, book->publisher);
        head = head->next; // próximo nó
    }
}

void lRefFree(LNode *head)
{
    while (head)
    {
        LNode *temp = head; // Armazena o nó atual
        head = head->next;  // Avança para o próximo nó
        free(temp);         // Libera o nó atual
    }
}
