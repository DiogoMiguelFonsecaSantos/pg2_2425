#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "bookModule.h"
#include "Serie1.h"
#include "Serie2.h"

Book *bookCreate(const char *line) {
    if (line == NULL || strlen(line) == 0) { // Verifies if line is NULL or if line is empty, if so,
        return NULL;
    }

    char *p1, *p2; // Pointers to the beginning and end of the field
    int fieldCounter = 1; // Counter for the fields

    p1 = line; // p1 points to the beginning of the line

    Book *b = (Book *)malloc(sizeof(Book)); // Allocates memory for the Book structure
    if (!b) { // Verifies if b is NULL, if so return NULL
        return NULL;
    }

    memset(b, 0, sizeof(Book)); // Initializes the Book structure with zeros, always a good practice

    do { // Do-while loop to fill the fields of the Book structure
        p2 = splitField(p1); // Splits the field and returns the pointer to the next field
        separatorUnify(p1); // Unifies the separators in the field

        switch (fieldCounter) { // Switch case to fill the fields of the Book structure
            case 1:
                b->title = strdup(p1); // Allocates memory for the title and copies the string
                break;
            case 2:
                strncpy(b->isbn, p1, MAX_ISBN); // Copies the string to the isbn field
                b->isbn[MAX_ISBN - 1] = '\0'; // Adds the null terminator
                break;
            case 4:
                b->authors = strdup(p1); // Allocates memory for the authors and copies the string
                break;
            case 5:
                b->publisher = strdup(p1); // Allocates memory for the publisher and copies the string
                break;
            default:
                break;
        }
        fieldCounter++; // Increments the field counter
    } while ((p1 = p2) != NULL); // Loops while p1 is different from NULL

    return b;
}

void bookFree(Book *b) {
    if (b) { // Verifies if b is NULL, if not, free the memory allocated for title, authors, publisher and b

        free(b->title); 
        free(b->authors);
        free(b->publisher);
        free(b);

    }
}