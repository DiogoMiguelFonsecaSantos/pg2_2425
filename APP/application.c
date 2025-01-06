/**
 * 5th day: -2.2
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>#include "bookModule.h"
#include "vecModule.h"
#include "dynModule.h"
#include "Serie2.h"
#include "Serie1.h"

void listBooks(DynCollection *coll) {
    int size = vecRefSize(coll->titleVec);
    for (int i = 0; i < size; i++) {
        Book *book = vecRefGet(coll->titleVec, i);
        if (book) {
            printf("Title: %s, Author: %s, Publisher: %s, ISBN: %s\n", book->title, book->authors, book->publisher, book->isbn);
        }
    }
}

void findBookByIsbn(DynCollection *coll, const char *isbn) {
    Book *book = vecRefSearchIsbn(coll->isbnVec, (char *)isbn);
    if (book) {
        printf("Title: %s, Author: %s, Publisher: %s, ISBN: %s\n", book->title, book->authors, book->publisher, book->isbn);
    } else {
        printf("Book with ISBN %s not found.\n", isbn);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    DynCollection *coll = dynCollCreate();
    if (!coll) {
        fprintf(stderr, "Failed to create collection.\n");
        return 1;
    }

    dynCollFill(coll, argv[1]);

    char command[256];
    while (1) {
        printf("Enter command (l to list, i <isbn> to find by ISBN, q to quit): ");
        if (!fgets(command, sizeof(command), stdin)) {
            break;
        }

        if (command[0] == 'q') {
            break;
        } else if (command[0] == 'l') {
            listBooks(coll);
        } else if (command[0] == 'i') {
            char isbn[20];
            if (sscanf(command, "i %19s", isbn) == 1) {
                findBookByIsbn(coll, isbn);
            } else {
                printf("Invalid command format.\n");
            }
        } else {
            printf("Unknown command.\n");
        }
    }

    dynCollFree(coll);
    return 0;
}