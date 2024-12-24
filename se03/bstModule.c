#include <stdio.h>
#include <stdlib.h>
#include "bookModule.h"
#include "bstModule.h"
#include "lRefModule.h"
#include "SE1.h"
#include "SE2.h"

void bstAdd(TNode **rootPtr, char *namWord, BookSE3 *ref)
{

    if (*rootPtr == NULL)
    {
        TNode *n = malloc(sizeof(*n));

        n->word = strdup(namWord); // Copia a palavra para o nó
        n->head = NULL;            // Inicializa a lista de referências
        n->left = n->right = NULL; // Inicializa os filhos como NULL

        // Associa o livro à lista de referências da palavra
        lAddRef(&n->head, ref);

        *rootPtr = n; // Atualiza a raiz da árvore
        return;
    }

    // Compara a palavra com a palavra do nó atual
    int cmp = strcmp(namWord, (*rootPtr)->word);
    if (cmp < 0)
    {
        // Se a palavra for menor, insere na subárvore esquerda
        bstAdd(&(*rootPtr)->left, namWord, ref);
    }
    else if (cmp > 0)
    {
        // Se a palavra for maior, insere na subárvore direita
        bstAdd(&(*rootPtr)->right, namWord, ref);
    }
    else
    {
        // Se a palavra já existe, adiciona o livro à lista de referências
        lAddRef(&(*rootPtr)->head, ref);
    }
}

TNode *treeToSortedList(TNode *r, TNode *link)
{
    TNode *p;
    if (r == NULL)
        return link;
    p = treeToSortedList(r->left, r);
    r->left = NULL;
    r->right = treeToSortedList(r->right, link);
    return p;
}

TNode *sortedListToBalancedTree(TNode **listRoot, int n)
{
    if (n == 0)
        return NULL;
    TNode *leftChild = sortedListToBalancedTree(listRoot, n / 2);
    TNode *parent = *listRoot;
    parent->left = leftChild;
    *listRoot = (*listRoot)->right;
    parent->right = sortedListToBalancedTree(listRoot, n - (n / 2 + 1));
    return parent;
}

int tCount(TNode *r)
{
    return r == NULL ? 0 : 1 + tCount(r->left) + tCount(r->right);
}

void bstBalance(TNode **rootPtr)
{
    // Converte a árvore em uma lista ordenada
    *rootPtr = treeToSortedList(*rootPtr, NULL);

    // Construa uma árvore balanceada a partir da lista ordenada
    *rootPtr = sortedListToBalancedTree(rootPtr, tCount(*rootPtr));
}

LNode *bstSearch(TNode *root, char *namWord)
{
    if (root == NULL)
    {
        return NULL; // Se a árvore estiver vazia, retorna NULL
    }

    int cmp = strcmp(namWord, root->word); // Compara a palavra procurada com a palavra do nó atual

    if (cmp == 0)
    {
        // Se a palavra foi encontrada, retorna a lista ligada de livros associada a ela
        return root->head;
    }

    if (cmp < 0)
    {
        // Se a palavra procurada for menor, procura na subárvore esquerda
        return bstSearch(root->left, namWord);
    }

    // Se a palavra procurada for maior, procura na subárvore direita
    return bstSearch(root->right, namWord);
}

void bstFree(TNode *root)
{
    bstFree(root->left);

    // Libera a subárvore direita
    bstFree(root->right);

    // Libera a lista ligada de referências associada a esse nó
    lRefFree(root->head);

    // Libera o campo word, que contém a palavra associada ao nó
    free(root->word);

    // Libera o próprio nó
    free(root);
}