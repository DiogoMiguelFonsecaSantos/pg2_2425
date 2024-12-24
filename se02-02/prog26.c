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
#include "func2.h"      
#include "funcSE1.h"     
#include "procTextFile.h"

int main(int argc, char *argv[]) {

    if (argc != 2) { // Verifies if the number of arguments is different from 2, if so, prints the usage and returns 1
        perror("That's not how you use this program!! Please provide a valid file as following:\n\n ./prog26 <filename>\n\n");
        return -1;
    }

    const char *filename = argv[1]; // file with the lines of data of books that will be added to the collection
    Collection collection = {.count = 0}; // initializes the collection with 0 books

    int numBooks = processFile(filename, collAddBook, &collection); // processes the file with the collAddBook function and the collection as context
    if (numBooks == -1) { // if the number of books is -1, there was an error processing the file and returns -1
        fprintf(stderr, "Error processing the file.\n");
        return -1;
    }

    printf("Data stored successfully (%d books).\n", numBooks); // prints the number of books loaded successfully

    char command[256]; // translate the string that will be printed to english
    while (1) { // infinite loop to read the commands
        printf("Command (l to list, q to quit): ");
        if (!fgets(command, sizeof(command), stdin)) { // reads the command from the user
            fprintf(stderr, "Error reading the command.\n");
            continue;
        }

    
        size_t len = strlen(command); // gets the length of the command
        if (len > 0 && command[len - 1] == '\n') {
            command[len - 1] = '\0';
        }

        if (strcmp(command, "q") == 0) { // if the command is 'q', terminates the program
            printf("Terminating the program.\n");
            break;
        } else if (strcmp(command, "l") == 0) { // if the command is 'l', lists the books sorted by title

            collSortTitle(&collection); // translate the string that will be printed to english


            printf("List of books (sorted by title):\n");
            for (int i = 0; i < collection.count; i++) { // prints the books in the collection
                printf("%s | %s | %s | %s\n",
                       collection.books[i].title,
                       collection.books[i].authors,
                       collection.books[i].publisher,
                       collection.books[i].isbn);
            }
        } else {
            printf("Invalid command. Use 'l' to list or 'q' to quit.\n");
        }
    }

    return 0;
}