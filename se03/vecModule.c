#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bookModule.h"
#include "vecModule.h"
#include "SE1.h"
#include "SE2.h"

#define INIT_SPACE 10
#define BLOCK_SIZE 10 // Quantidade de elementos por bloco quando redimensionar

VecBookRef *vecRefCreate(void)
{

    VecBookRef *vec = malloc(sizeof(VecBookRef));
    vec->refs = malloc(INIT_SPACE * sizeof(BookSE3 *));
    vec->size = 0;
    vec->space = INIT_SPACE;

    return vec;
}

void vecRefAdd(VecBookRef *vec, BookSE3 *ref)
{

    if (vec->size == vec->space)
    {
        vec->space += BLOCK_SIZE;
        vec->refs = realloc(vec->refs, vec->space * sizeof(BookSE3 *));
    }

    vec->refs[vec->size++] = ref;
}

int vecRefSize(VecBookRef *vec)
{
    return vec->size;
}

BookSE3 *vecRefGet(VecBookRef *vec, int index)
{
    if (!vec || index < 0 || index >= vec->size)
    {
        return NULL;
    }
    return vec->refs[index];
}

int compareByTitle(const void *a, const void *b)
{
    BookSE3 *bookA = *(BookSE3 **)a;
    BookSE3 *bookB = *(BookSE3 **)b;
    return strcmp(bookA->title, bookB->title);
}

void vecRefSortTitle(VecBookRef *vec)
{
    qsort(vec->refs, vec->size, sizeof(BookSE3 *), compareByTitle);
}

int compareIsbn(const void *a, const void *b)
{
    BookSE3 *bookA = *(BookSE3 **)a;
    BookSE3 *bookB = *(BookSE3 **)b;
    return strcmp(bookA->isbn, bookB->isbn);
}

void vecRefSortIsbn(VecBookRef *vec)
{
    qsort(vec->refs, vec->size, sizeof(BookSE3 *), compareIsbn);   
}



BookSE3 *vecRefSearchIsbn(VecBookRef *vec, const char *isbn) // Change here
{
    BookSE3 key; // Create a temporary object to represent the search key
    strncpy(key.isbn, isbn, MAX_ISBN - 1);
    key.isbn[MAX_ISBN - 1] = '\0';

    BookSE3 *keyP = &key;
    BookSE3 **result = bsearch(&keyP, vec->refs, vec->size, sizeof(BookSE3 *), compareIsbn);

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