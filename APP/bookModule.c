#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bookModule.h"

// Function to create a book descriptor from a text line
Book *bookCreate(const char *line) {
    if (!line || strlen(line) == 0) {
        return NULL;
    }

    Book *b = malloc(sizeof(Book));
    if (!b) {
        return NULL;
    }

    char tempLine[strlen(line) + 1];
    strcpy(tempLine, line);

    char *field = strtok(tempLine, ";");
    if (!field) {
        free(b);
        return NULL;
    }

    b->title = strdup(field);
    if (!b->title) {
        free(b);
        return NULL;
    }

    field = strtok(NULL, ";");
    if (!field) {
        free(b->title);
        free(b);
        return NULL;
    }
    strncpy(b->isbn, field, MAX_ISBN - 1);
    b->isbn[MAX_ISBN - 1] = '\0';

    field = strtok(NULL, ";");
    if (!field) {
        free(b->title);
        free(b);
        return NULL;
    }
    b->authors = strdup(field);
    if (!b->authors) {
        free(b->title);
        free(b);
        return NULL;
    }

    field = strtok(NULL, ";");
    if (!field) {
        free(b->title);
        free(b->authors);
        free(b);
        return NULL;
    }
    b->publisher = strdup(field);
    if (!b->publisher) {
        free(b->title);
        free(b->authors);
        free(b);
        return NULL;
    }

    return b;
}

// Function to free the memory occupied by a book descriptor
void bookFree(Book *b) {
    if (b) {
        free(b->title);
        free(b->authors);
        free(b->publisher);
        free(b);
    }
}