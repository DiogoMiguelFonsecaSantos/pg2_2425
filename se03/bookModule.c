#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <errno.h>
#include "funcSE1.h"
#include "procTextFile.h"
#include "bookModule.h"
#include <stdlib.h>
#include <string.h>
#include "func2.h"

int fillBookData(BookData *b, const char *line)
{
    char aux[MAX_LINE]; // array to store the line (manual copy array)
    char *p1, *p2;      // pointers to store the fields
    int i = 0;          // counter to iterate through the line
    int countField = 1; // counter to store the field number
    while (*(line + i) != '\0')
    {                         // while the current character is not the null terminator
        aux[i] = *(line + i); // aux receives the current character
        i++;                  // increments i
    }
    aux[i] = '\0'; // adds the null terminator to aux
    p1 = aux;      // p1 receives the address of aux
    do
    {

        p2 = splitField(p1);
        separatorUnify(p1);
        switch (countField)
        {
        case 1:
            if ((strlen(p1) > MAX_TITLE - 1))
            {
                return 0;
            }
            strcpy(b->title, p1);
            break;

        case 2:
            break;

        case 3:
            if ((strlen(p1) != SIZE_ISBN - 1))
            {
                return 0;
            }
            strcpy(b->isbn, p1);
            break;

        case 4:
            if ((strlen(p1) > MAX_AUTHORS - 1))
            {
                return 0;
            }
            strcpy(b->authors, p1);
            break;

        case 5:
            if ((strlen(p1) > MAX_PUB_NAME - 1))
            {
                return 0;
            }
            strcpy(b->publisher, p1);
            break;

        default:
            break;
        }
        countField++;
    } while ((p1 = p2) != NULL);
    return 1;
}



// Function to create a Book object from a line of text
Book *bookCreate(const char *line)
{
    // Declare pointers for parsing the line
    char *p1, *p2;
    // Initialize p1 to point to the start of the line
    p1 = line;
    // Initialize field counter
    int countField = 1;

    // Allocate memory for a new Book object
    Book *b = malloc(sizeof(Book));
    // Check if memory allocation failed
    if (!b)
        return NULL;

    // Initialize Book fields to NULL
    b->title = NULL;
    b->authors = NULL;
    b->publisher = NULL;

    // Loop to parse each field in the line
    do
    {
        // Split the line into fields
        p2 = splitField(p1);
        // Unify field separators
        separatorUnify(p1);
        // Switch based on the current field number
        switch (countField)
        {
        case 1:
            // Duplicate the title field

            b->title = strdup(p1);
            if (b->title == NULL)
            {
                return NULL;
            }

            break;

        case 2:
            // No operation for field 2
            break;

        case 3:
            // Check if the ISBN length is valid
            if ((strlen(p1) != MAX_ISBN - 1))
            {
                return NULL;
            }
            // Copy the ISBN field
            strcpy(b->isbn, p1);
            break;

        case 4:
            // Duplicate the authors field
            b->authors = strdup(p1);
            break;

        case 5:
            // Duplicate the publisher field
            b->publisher = strdup(p1);
            break;

        default:
            // No operation for other fields
            break;
        }
        // Increment the field counter
        countField++;
    } while ((p1 = p2) != NULL);

    // Check if the publisher field is still NULL
    if (b->publisher == NULL)
    {
        // Free allocated memory for title and authors
        free(b->title);
        free(b->authors);
        // Free the Book object
        free(b);
        // Return NULL to indicate an error
        return NULL;
    }
    else
    {
        // Return the created Book object
        return b;
    }
}

void bookFree(Book *b)
{
    if (b)
    {
        free(b->title);
        free(b->authors);
        free(b->publisher);
        free(b);
    }
}