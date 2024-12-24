#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dynModule.h"
#include "vecModule.h"
#include "bookModule.h"
#include "Serie2.h"

// Function to create a dynamic collection descriptor
DynCollection *dynCollCreate(void) {
    DynCollection *coll = (DynCollection *)malloc(sizeof(DynCollection));
    if (!coll) return NULL;

    coll->titleVec = vecRefCreate();
    coll->isbnVec = vecRefCreate();
    if (!coll->titleVec || !coll->isbnVec) {
        if (coll->titleVec) vecRefFree(coll->titleVec, 0);
        if (coll->isbnVec) vecRefFree(coll->isbnVec, 0);
        free(coll);
        return NULL;
    }

    return coll;
}

// Function to add a book to the dynamic collection
int dynCollAddBook(const char *line, void *context) {
    if (!line || !context) return 0;

    DynCollection *coll = (DynCollection *)context;
    Book *book = bookCreate(line);
    if (!book) return 0;

    vecRefAdd(coll->titleVec, book);
    vecRefAdd(coll->isbnVec, book);

    return 1;
}

// Function to fill the dynamic collection from a file
void dynCollFill(DynCollection *coll, const char *filename) {
    if (!coll || !filename) return;

    printf("Filling collection from file: %s\n", filename);
    processFile(filename, dynCollAddBook, coll);

    printf("Sorting title vector\n");
    vecRefSortTitle(coll->titleVec);
    printf("Sorting ISBN vector\n");
    vecRefSortIsbn(coll->isbnVec);
}

// Function to free the dynamic collection
void dynCollFree(DynCollection *coll) {
    if (!coll) return;

    vecRefFree(coll->titleVec, 1);
    vecRefFree(coll->isbnVec, 0);
    free(coll);
}