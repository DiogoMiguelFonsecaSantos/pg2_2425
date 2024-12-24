#ifndef VEC_H
#define VEC_H

typedef struct
{				 // Descritor de um vetor
	Book **refs; // array alojado dinamicamente
	int size;	 // quantidade de elementos preenchidos
	int space;	 // quantidade de elementos alojados
} VecBookRef;

VecBookRef *vecRefCreate(void);
void vecRefAdd(VecBookRef *vec, Book *ref);
int vecRefSize(VecBookRef *vec);
void vecRefSortTitle(VecBookRef *vec);
void vecRefSortIsbn(VecBookRef *vec);
Book *vecRefSearchIsbn(VecBookRef *vec, char *isbn);
void vecRefFree(VecBookRef *vec, int freeBooks);

#endif