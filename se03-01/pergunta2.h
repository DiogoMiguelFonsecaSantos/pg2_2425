#ifndef __PERGUNTA2_H__
#define __PERGUNTA2_H__

#include <stdio.h>

#define MAX_BOOKS 1000
#define MAX_TITLE 100
#define SIZE_ISBN 13
#define MAX_AUTHORS 150
#define MAX_PUB_NAME 60

typedef struct book
{
	char title[MAX_TITLE];
	char isbn[SIZE_ISBN];
	char authors[MAX_AUTHORS];
	char publisher[MAX_PUB_NAME];
} BookData;

typedef struct
{
	BookData books[MAX_BOOKS];
	BookData *refs[MAX_BOOKS];
	int count; // quantidade de elementos preenchidos em books
} Collection;

int fillBookData(BookData *b, const char *line);
int collAddBook(const char *line, void *context);
void collSortTitle(Collection *col);
void collSortRefIsbn(Collection *col);
int bookContainsAuthor(BookData *b, const char *word);

#endif
