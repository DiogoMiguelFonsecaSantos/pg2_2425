#ifndef VEC_H
#define VEC_H

#include "SE1.h"
#include "SE2.h"

typedef struct
{				 // Descritor de um vetor
	BookSE3 **refs; // array alojado dinamicamente
	int size;	 // quantidade de elementos preenchidos
	int space;	 // quantidade de elementos alojados
} VecBookRef;

VecBookRef *vecRefCreate(void);
void vecRefAdd(VecBookRef *vec, BookSE3 *ref);
int vecRefSize(VecBookRef *vec);
void vecRefSortTitle(VecBookRef *vec);
void vecRefSortIsbn(VecBookRef *vec);
BookSE3 *vecRefSearchIsbn(VecBookRef *vec, const char *isbn);
void vecRefFree(VecBookRef *vec, int freeBooks);

#endif