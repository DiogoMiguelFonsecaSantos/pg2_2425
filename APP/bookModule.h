// bookModule.h
#ifndef BOOK_H
#define BOOK_H

#define MAX_ISBN 20

typedef struct {
    char *title;        // string alojada dinamicamente
    char isbn[MAX_ISBN]; // string com dimensão fixa
    char *authors;      // string alojada dinamicamente
    char *publisher;    // string alojada dinamicamente
} Book;

void bookFree(Book *b);
Book *bookCreate(const char *line);

#endif