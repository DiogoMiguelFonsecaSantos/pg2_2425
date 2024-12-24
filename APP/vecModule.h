#ifndef VECMODULE_H
#define VECMODULE_H

#include "bookModule.h"

typedef struct {
    Book **refs; // dynamically allocated array of pointers
    int size;    // number of filled elements
    int space;   // number of allocated elements
} VecBookRef;

VecBookRef *vecRefCreate(void);
void vecRefAdd(VecBookRef *vec, Book *ref);
int vecRefSize(VecBookRef *vec);
Book *vecRefGet(VecBookRef *vec, int index);
void vecRefSortTitle(VecBookRef *vec);
void vecRefSortIsbn(VecBookRef *vec);
Book *vecRefSearchIsbn(VecBookRef *vec, char *isbn);
void vecRefFree(VecBookRef *vec, int freeBooks);

#endif