#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h> //para o tolower
#include "bookModule.h"
#include "vecModule.h"
#include "dynModule.h"
#include "lRefModule.h"
#include "bstModule.h"

/**
 * * 2.1 *
 * Escreva e teste o módulo de aplicação capaz de responder aos comandos “l” e “i”, ou adapte o realizado
 * na SE2, explorando as estruturas de dados dinâmicas.
 *
 * BEFORE: Apresenta a lista de todos os livros, com ordem alfabeticamente crescente por título,
 * indicando, para cada um: título, autor, editor e ISBN;
 * NOW: O comando “l” explora o vetor de referências ordenado por título, pertencente ao descritor da coleção,
 * usando as funções vecRefSize e vecRefGet.
 *
 * BEFORE: Apresenta os dados relativos ao livro com o ISBN indicado; Se este não existir, apresenta
 * um aviso;
 * NOW: O comando “i” explora o vetor de referências ordenado por ISBN, realizando a pesquisa binária através
 * da função vecRefSearchIsbn.
 *
 * A este programa serão, adiante, adicionados os comandos “a” e “q”.
 */

void listBooks(VecBookRef *titleVec)
{
    int size = vecRefSize(titleVec);
    for (int i = 0; i < size; i++)
    {
        Book *book = vecRefGet(titleVec, i);
        printf("Title: %s, Author: %s, Publisher: %s, ISBN: %s\n", book->title, book->authors, book->publisher, book->isbn);
    }
}

void searchBookByIsbn(VecBookRef *isbnVec, const char *isbn)
{
    Book *book = vecRefSearchIsbn(isbnVec, isbn);
    if (book)
    {
        printf("Title: %s, Author: %s, Publisher: %s, ISBN: %s\n", book->title, book->authors, book->publisher, book->isbn);
    }
    else
    {
        printf("Book with ISBN %s not found.\n", isbn);
    }
}

int main()
{
    DynCollection *coll = dynCollCreate();
    dynCollFill(coll, "books.txt");

    char command;
    while (1)
    {
        printf("Enter command (l: list, i: search by ISBN, q: quit): ");
        scanf(" %c", &command);

        if (command == 'l')
        {
            listBooks(coll->titleVec);
        }
        else if (command == 'i')
        {
            char isbn[20];
            printf("Enter ISBN: ");
            scanf("%s", isbn);
            searchBookByIsbn(coll->isbnVec, isbn);
        }
        else if (command == 'q')
        {
            break;
        }
        else
        {
            printf("Invalid command. Use 'l' to list, 'i' to search by ISBN, or 'q' to quit.\n");
        }
    }

    dynCollFree(coll);
    return 0;
}