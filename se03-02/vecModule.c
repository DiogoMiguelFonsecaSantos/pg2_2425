#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bookModule.h"
#include "vecModule.h"

#define INIT_SPACE 10
#define BLOCK_SIZE 10 // Quantidade de elementos por bloco quando redimensionar

VecBookRef *vecRefCreate(void)
{

    VecBookRef *vec = malloc(sizeof(VecBookRef));
    vec->refs = malloc(INIT_SPACE * sizeof(Book *));
    vec->size = 0;
    vec->space = INIT_SPACE;

    return vec;
}

void vecRefAdd(VecBookRef *vec, Book *ref)
{

    if (vec->size == vec->space)
    {
        vec->space += BLOCK_SIZE;
        vec->refs = realloc(vec->refs, vec->space * sizeof(Book *));
    }

    vec->refs[vec->size++] = ref;
}

int vecRefSize(VecBookRef *vec)
{
    return vec->size;
}

Book *vecRefGet(VecBookRef *vec, int index)
{
    if (!vec || index < 0 || index >= vec->size)
    {
        return NULL;
    }
    return vec->refs[index];
}

int compareByTitle(const void *a, const void *b)
{
    Book *bookA = *(Book **)a;
    Book *bookB = *(Book **)b;
    return strcmp(bookA->title, bookB->title);
}

void vecRefSortTitle(VecBookRef *vec)
{
    qsort(vec->refs, vec->size, sizeof(Book *), compareByTitle);
}

int compareIsbn(const void *a, const void *b)
{
    Book *bookA = *(Book **)a;
    Book *bookB = *(Book **)b;
    return strcmp(bookA->isbn, bookB->isbn);
}

void vecRefSortIsbn(VecBookRef *vec)
{
    qsort(vec->refs, vec->size, sizeof(Book *), compareIsbn);   
}



Book *vecRefSearchIsbn(VecBookRef *vec, char *isbn)
{
    Book key; // Create a temporary object to represent the search key
    strncpy(key.isbn, isbn, MAX_ISBN - 1);
    key.isbn[MAX_ISBN - 1] = '\0';

    Book *keyP = &key;
    Book **result = bsearch(&keyP, vec->refs, vec->size, sizeof(Book *), compareIsbn);

    return (result) ? *result : NULL;
}

void vecRefFree(VecBookRef *vec, int freeBooks)
{

    if (freeBooks)
    {
        for (int i = 0; i < vec->size; i++)
        {
            bookFree(vec->refs[i]);
        }
    }
    free(vec->refs);
    free(vec);
}