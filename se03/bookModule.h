#ifndef BOOK_H
#define BOOK_H

#define MAX_ISBN 20
#define MAX_LINE 4

typedef struct
{						 // Descritor dos dados de um livro
	char *title;		 // string alojada dinamicamente
	char isbn[MAX_ISBN]; // string com dimensão fixa
	char *authors;		 // string alojada dinamicamente
	char *publisher;	 // string alojada dinamicamente
} BookSE3;

void bookFree(BookSE3 *b);
BookSE3 *bookCreate(const char *line);

#endif	