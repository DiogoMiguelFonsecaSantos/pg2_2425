#ifndef DYN_H
#define DYN_H

#include "vecModule.h"
#include "SE1.h"
#include "SE2.h"

typedef struct
{						  // Descritor de um vetor
	VecBookRef *titleVec; // vetor a ordenar por título
	VecBookRef *isbnVec;  // vetor a ordenar por isbn
} DynCollection;

DynCollection *dynCollCreate(void);
int dynCollAddBook(const char *line, void *context);
void dynCollFill(DynCollection *coll, const char *filename);
void dynCollFree(DynCollection *coll);

#endif