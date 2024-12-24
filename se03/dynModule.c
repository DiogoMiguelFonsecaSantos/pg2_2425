#include <stdio.h>
#include <stdlib.h>
#include "bookModule.h"
#include "dynModule.h"
#include "SE1.h"
#include "SE2.h"

#define INITIAL_SPACE 10

DynCollection *dynCollCreate(void)
{
    DynCollection *coll = malloc(sizeof(DynCollection));
    coll->titleVec = vecRefCreate();
    coll->isbnVec = vecRefCreate();
    return coll;
}

int dynCollAddBook(const char *line, void *context)
{

    DynCollection *coll = (DynCollection *)context;

    BookSE3 *newBook = bookCreate(line);
    if (!newBook)
        return 0;

    // Adiciona o livro ao vetor de referências ordenado por
    vecRefAdd(coll->titleVec, newBook);

    vecRefAdd(coll->isbnVec, newBook);

    return 1;
}

void dynCollFill(DynCollection *coll, const char *filename)
{
    int result = processFile(filename, dynCollAddBook, coll);
    if (result < 0)
    {
        fprintf(stderr, "Erro ao processar o arquivo: %s\n", filename);
        return;
    }

    vecRefSortTitle(coll->titleVec);
    vecRefSortIsbn(coll->isbnVec);

    printf("Coleção preenchida com sucesso. Livros processados: %d\n", result);
}

void dynCollFree(DynCollection *coll)
{
    vecRefFree(coll->titleVec, 1);
    vecRefFree(coll->isbnVec, 0);
    free(coll);
}
