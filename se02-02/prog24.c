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

void printBook(const BookData *b)
{ // helper function that prints the book data
    printf("%s;%s;%s;%s;%s;%s;%s;%s;%s;%s\n",
           b->title, b->isbn, b->isbn13, b->authors, b->publisher,
           b->keywords, b->num_pages, b->date, b->binding, b->price); // prints the book data
}

void printCollection(const Collection *collection)
{ // helper function that prints the collection data
    for (int i = 0; i < collection->count; i++)
    { // for each book in the collection, print the book data
        printBook(&collection->books[i]); 
    }
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Uso: %s <nome_ficheiro>\n", argv[0]);
        return -1;
    }

    const char *filename = argv[1];
    Collection collection = {.count = 0}; // Only one of the fields (count) is initialized, the rest are initialized to 0/NULL
    // without this action, the structure fields are not initialized and may contain garbage


    int result = processFile(filename, collAddBook, &collection);
    // processFile is called with the filename, the collAddBook function and the collection as context
    
    if (result < 0) // if the result is negative, print an error message
    {
        perror("Something went wrong with the file processing...\n");
        return -1;
    }

    printf("Total books stored: %d\n", collection.count); // prints the total number of books stored
    printf("Data added to collection:\n"); 
    printCollection(&collection); // prints the collection data

    return 0;
}