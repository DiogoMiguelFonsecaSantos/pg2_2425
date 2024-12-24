#ifndef DYNMODULE_H
#define DYNMODULE_H

#include "vecModule.h"

typedef struct {
    VecBookRef *titleVec; // vector sorted by title
    VecBookRef *isbnVec;  // vector sorted by ISBN
} DynCollection;

DynCollection *dynCollCreate(void);
int dynCollAddBook(const char *line, void *context);
void dynCollFill(DynCollection *coll, const char *filename);
void dynCollFree(DynCollection *coll);

#endif