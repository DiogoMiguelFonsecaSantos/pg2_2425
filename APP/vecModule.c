#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vecModule.h"
#include "bookModule.h"

// Function to create a vector of references
VecBookRef *vecRefCreate(void) {
    VecBookRef *vec = (VecBookRef *)malloc(sizeof(VecBookRef));
    if (!vec) return NULL;

    vec->refs = (Book **)malloc(10 * sizeof(Book *));
    if (!vec->refs) {
        free(vec);
        return NULL;
    }

    vec->size = 0;
    vec->space = 10;
    return vec;
}

// Function to add a book reference to the vector
void vecRefAdd(VecBookRef *vec, Book *ref) {
    if (vec->size >= vec->space) {
        vec->space *= 2;
        vec->refs = (Book **)realloc(vec->refs, vec->space * sizeof(Book *));
        if (!vec->refs) return;
    }
    vec->refs[vec->size++] = ref;
}

// Function to get the size of the vector
int vecRefSize(VecBookRef *vec) {
    return vec->size;
}

// Function to get a book reference by index
Book *vecRefGet(VecBookRef *vec, int index) {
    if (index < 0 || index >= vec->size) return NULL;
    return vec->refs[index];
}

// Helper function to compare books by title
int compareByTitle(const void *a, const void *b) {
    Book *bookA = *(Book **)a;
    Book *bookB = *(Book **)b;
    if (!bookA || !bookB || !bookA->title || !bookB->title) {
        printf("Null pointer encountered in compareByTitle\n");
        return 0;
    }
    printf("Comparing '%s' with '%s'\n", bookA->title, bookB->title);
    return strcasecmp(bookA->title, bookB->title);
}

// Function to sort the vector by book titles
void vecRefSortTitle(VecBookRef *vec) {
    printf("Sorting %d books by title\n", vec->size);
    for (int i = 0; i < vec->size; i++) {
        if (vec->refs[i] && vec->refs[i]->title) {
            printf("Book %d: %s\n", i, vec->refs[i]->title);
        } else {
            printf("Book %d: NULL\n", i);
        }
    }
    qsort(vec->refs, vec->size, sizeof(Book *), compareByTitle);
}

// Helper function to compare books by ISBN
int compareByIsbn(const void *a, const void *b) {
    Book *bookA = *(Book **)a;
    Book *bookB = *(Book **)b;
    return strcmp(bookA->isbn, bookB->isbn);
}

// Function to sort the vector by book ISBNs
void vecRefSortIsbn(VecBookRef *vec) {
    qsort(vec->refs, vec->size, sizeof(Book *), compareByIsbn);
}

// Function to search for a book by ISBN
Book *vecRefSearchIsbn(VecBookRef *vec, char *isbn) {
    Book key;
    strncpy(key.isbn, isbn, MAX_ISBN);
    Book *keyPtr = &key;
    Book **result = (Book **)bsearch(&keyPtr, vec->refs, vec->size, sizeof(Book *), compareByIsbn);
    return result ? *result : NULL;
}

// Function to free the vector and optionally the books
void vecRefFree(VecBookRef *vec, int freeBooks) {
    if (freeBooks) {
        for (int i = 0; i < vec->size; i++) {
            bookFree(vec->refs[i]);
        }
    }
    free(vec->refs);
    free(vec);
}