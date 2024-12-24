// Includes for the procTextFile.c file
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "Serie2.h"
#include "Serie1.h"

// Defines for the procTextFile.c file
#define DIM_MEM 512

// Functions

int processFile(const char *filename, int (*action)(const char *line, void *context), void *context)
{
    /**
     * Thinking process:
     * 1. Open the file with the given filename, perror if it can't be opened or smth goes wrong
     * 2. Read the file line by line
     * 3. Transform the line into a string
     * 4. Apply the specified action function to each transformed line
     * 5. The return value of the action function is stored in a variable and summed up in another variable
     * ! 6. DO NOT FORGET TO CLOSE THE FILE!!!!
     * 7. Return the sum of the return values of the action function
     */

    FILE *file = fopen(filename, "r"); // "r" means read mode

    if (file == NULL) // if the file is not found or can't be opened, return -1
    {
        perror("Something went wrong trying to open the selected file...\n"); // error message
        return -1;
    }

    char lineOfText[DIM_MEM]; // "Propõe-se a dimensão de 512 carateres para a memória destinada ao armazenamento da linha."
    int sumOfValues = 0;      // "A função retorna a soma dos valores retornados por todas as chamadas à função action."

    while (fgets(lineOfText, sizeof(lineOfText), file) != NULL)
    {   // "Sugere-se que realize a leitura do ficheiro de entrada com a função fgets."
        // while there are lines to read, do the following:

        size_t length = strlen(lineOfText); // gets the length of the line in size_t format

        if (length > 0 && lineOfText[length - 1] == '\n')
        {                                  // if the line is not empty and the last character is a newline character
            lineOfText[length - 1] = '\0'; // then replace the newline character with a null character
        }

        int returned = action(lineOfText, context); // variable to store the return value of the action function
        sumOfValues += returned;                    // sum of the return values of the action function
    }

    fclose(file);       // close the file
    return sumOfValues; // return the sum of the return values of the action function
}

int linePrintRaw(const char *line, void *context)
{
    /**
     * Thinking process:
     * 1. Print the line to the standard output?
     * 2. Return 1
     */
    if (line != NULL)
		printf("%s", line);// print the line
    return 1;             // return 1 just like the assignment asks
}

int lineFilterPrint(const char *line, void *context)
{

    /**
     * Thinking process:
     * ! 1. wanted to make sure that if no line or context is given, the function that called this one knows that what it asked for is not possible, letting the
     * ! user know that as well
     * 2. make a copy of th line im processing and change the copy so that the original line is not changed, give it a terminator
     * 3. split the field and store it, make sure it not NULL
     * 4. uniformize the separators in the firstField
     * 5. compare the firstField with the context, if they are equal, print the line and return 1
     * 6. if they are not equal, return 0
     */

    if (!line || !context)
    {
        return -1; // Se a linha ou o contexto forem NULL, retorna -1 (erro)
    }

    char lineCopy[512]; // Faz uma cópia da linha para não alterar a original
    strncpy(lineCopy, line, sizeof(lineCopy) - 1);
    lineCopy[sizeof(lineCopy) - 1] = '\0'; // Adiciona um terminador nulo ao final da cópia da linha

    char *firstField = splitField(lineCopy); // Separa o primeiro campo da linha
    if (firstField == NULL)
    {
        return 0; // Se não houver primeiro campo, retorna 0
    }
    
    separatorUnify(firstField); // Uniformiza os separadores no primeiro campo
    
    printf("Comparing '%s' with '%s'\n", firstField, (const char *)context); // Debug print

    if (strcmp_ic(firstField, (const char *)context) == 0)
    {
        printf("%s\n", line); // Se o primeiro campo for igual ao contexto, imprime a linha e retorna 1
        return 1;
    }

    return 0; // Caso contrário, retorna 0
}

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