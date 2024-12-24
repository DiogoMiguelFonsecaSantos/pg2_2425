/**
 * Nome: Diogo Miguel Fonseca Santos
 * Número: A49936
 * Disciplina: Programação 2
 * Data: 23/11/2024
 * Grupo 07
 * Turma LT31N
 * Série de Exercícios 2 - Exercício 1: Leitura de um ficheiro de texto, com processamento linha a linha, parametrizável
 */

// Includes for the procTextFile.c file
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "procTextFile.h"
#include "funcSE1.h"

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
    { // "Sugere-se que realize a leitura do ficheiro de entrada com a função fgets."
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

    printf("%s\n", line); // print the line
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

    if (strcmp_ic(firstField, (const char *)context) == 0)
    {
        printf("%s\n", line); // Se o primeiro campo for igual ao contexto, imprime a linha e retorna 1
        return 1;
    }

    return 0; // Caso contrário, retorna 0
}