/**
 * Nome: Diogo Miguel Fonseca Santos
 * Número: A49936
 * Disciplina: Programação 2
 * Data: 23/11/2024
 * Grupo 07
 * Turma LT31N
 * Série de Exercícios 2 - Exercício 2: Armazenamento, ordenação e pesquisa de uma lista de livros
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <errno.h>
#include "func2.h"
#include "funcSE1.h"
#include "procTextFile.h"

// 2.1 - Macros
#define MAX_BOOKS 300    // Número máximo de livros na coleção por agora            (wc -l dados.csv: 296)
#define MAX_TITLE 200    // Tamanho máximo do título -f1                            (cut -d";" -f1 dados.csv | wc -L: 200)
#define SIZE_ISBN 10     // Tamanho máximo do ISBN -f2                              (cut -d";" -f2 dados.csv | wc -L: 10)
#define SIZE_ISBN_13 13  // Tamanho máximo do ISBN 13 -f3                           (cut -d";" -f3 dados.csv | wc -L: 13)
#define MAX_AUTHORS 92   // Tamanho máximo do campo de autores -f4                  (cut -d";" -f4 dados.csv | wc -L: 92)
#define MAX_PUB_NAME 51  // Tamanho máximo do campo do editor -f5                   (cut -d";" -f5 dados.csv | wc -L : 51)
#define MAX_KEYWORDS 127 // Tamanho máximo do campo de palavras-chave -f6           (cut -d";" -f6 dados.csv | wc -L: 127)
#define MAX_PAGES 4      // Tamanho máximo do campo de número de páginas -f7        (cut -d";" -f7 dados.csv | wc -L: 4)
#define MAX_DATE 10      // Tamanho máximo do campo de data de publicação -f8       (cut -d";" -f8 dados.csv | wc -L: 10)
#define MAX_BINDING 9    // Tamanho máximo do campo de tipo de encadernação -f9     (cut -d";" -f9 dados.csv | wc -L: 9)
#define MAX_PRICE 10     // Tamanho máximo do campo de preço -f10                   (cut -d";" -f10 dados.csv | wc -L: 10)

int fillBookData(BookData *b, const char *line)
{
    if (!b || !line || strlen(line) == 0)
    { // Verifies if b (BookData) and line are NULL or if line is empty, if not, return 0
        return 0;
    }

    char tempLine[strlen(line) + 1]; // creates a temporary line with the same size as line
    strcpy(tempLine, line);          // copies the content of line to tempLine

    char *field = tempLine;                                                                                                                              // field receives the address of tempLine so it can be used in splitField
    const int fieldSizes[] = {MAX_TITLE_SE2, SIZE_ISBN_SE2, SIZE_ISBN_13, MAX_AUTHORS_SE2, MAX_PUB_NAME_SE2, MAX_KEYWORDS, MAX_PAGES, MAX_DATE, MAX_BINDING, MAX_PRICE}; // array with the sizes of each field
    char *bookFields[] = {b->title, b->isbn, b->isbn13, b->authors, b->publisher, b->keywords, b->num_pages, b->date, b->binding, b->price};             // array with the fields of the book

    for (int i = 0; i < 10; i++)
    {
        field = splitField(field); // field receives the address of the next field for the next splitField
        if (!field)
        { // if field is non-existent, return 0
            return 0;
        }

        separatorUnify(tempLine);                        // uniformizes the tempLine (replaces single/multiple ' ', '\t' and '\n' by ' ')
        strncpy(bookFields[i], tempLine, fieldSizes[i]); // copies the content of tempLine to the field of the book of the current iteration
        bookFields[i][fieldSizes[i] - 1] = '\0';         // adds the null terminator to the field of the book of the current iteration
        tempLine[0] = '\0';                              // tempLine is reset, so that it can be used again in the next field
    }

    return 1; // returns 1 if the function was successful
}

int collAddBook(const char *line, void *context)
{
    if (!line || !context) 
    { // verifies if line or context are NULL, if so, return 0
        return 0; 
    }

    Collection *collection = (Collection *)context; // casts context to Collection and assigns it to collection so that it can be used 
                                                    // as a Collection type pointer and access its fields
    if (collection->count >= MAX_BOOKS)
    { // if the number of books in the collection is greater than or equal to the maximum number of books, return 0 
        return 0; 
    }

    if (fillBookData(&collection->books[collection->count], line))
    { // if the function fillBookData was successful, increment the count of the collection and return 1 
        collection->count++; 
        return 1;            
    }
    return 0; // if the function fillBookData was not successful, return 0
}

int compareByTitle(const void *a, const void *b)
{ // Helper Compare function to sort the collection by title

    const BookData *booka = (const BookData *)a; // casts a to BookData and assigns it to booka so that it can be used as a BookData type pointer
    const BookData *bookb = (const BookData *)b; // casts b to BookData and assigns it to bookb so that it can be used as a BookData type pointer

    char titlea[MAX_TITLE_SE2], titleb[MAX_TITLE_SE2]; // creates two arrays of chars with the size of MAX_TITLE for the titles of the books

    for (size_t i = 0; i < MAX_TITLE_SE2; i++) 
    { // for each character in the title of the books, convert it to lowercase and assign it to the respective title array

        titlea[i] = tolower(booka->title[i]); // titlea receives the lowercase of the title of booka
        titleb[i] = tolower(bookb->title[i]); // titleb receives the lowercase of the title of bookb
        if (booka->title[i] == '\0' || bookb->title[i] == '\0')
        { // if the current character of the title of booka or bookb is the null terminator, break the loop
            break;
        }
    }

    return strcmp(titlea, titleb); // returns the comparison of the two titles
}

void collSortTitle(Collection *col)
{
    if (col == NULL || col->count <= 1)
        return; // if col is NULL or the count of the collection is less than or equal to 1, it doesn't make sense to sort it; returns 

    // might need to use a compare function to sort the collection by title using qsort
    // smth like qsort(col->books, col->count, sizeof(BookData), compareByTitle);

    qsort(col->books, col->count, sizeof(BookData), compareByTitle);
}

// 2.7
void collSortRefIsbn(Collection *col)
{
}

// 2.9
int bookContainsAuthor(BookData *b, const char *word)
{
    return 0;
}