/*
Nome: Diogo Miguel Fonseca Santos
Número: A49936
Disciplina: Programação 2
Data: 23/11/2024
Grupo 07
Série de Exercícios 2 - Exercício 1: Leitura de um ficheiro de texto, com processamento linha a linha, parametrizável */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "funcSE1.h"

/**
 * @brief 1.1 Processes a text file line by line, applying a specified action to each line.
 *
 * This function opens the file with the given filename, reads its content line by line,
 * and applies the specified action function to each line. The action function is passed
 * a string containing the line to process and the context parameter received by processFile.
 * The function returns the sum of the values returned by all calls to the action function.
 *
 * @param filename The name of the file to process.
 * @param action A pointer to a function that processes a line. This function should take
 *               a const char* representing the line to process and a void* context parameter.
 * @param context A pointer to user-defined data that will be passed to the action function.
 * 
 * @return The sum of the values returned by all calls to the action function.
 * 
 * @note The function returns -1 if the file cannot be opened.
 */
int processFile( const char *filename, int (*action)( const char *line, void *context ), void *context );

/**
 * @brief Prints the given line of text to the standard output.
 *
 * This function is intended to be used as the action parameter in the processFile function.
 * It prints the entire content of the line to the standard output.
 * The context parameter is not used in this function.
 *
 * @param line The line of text to be printed.
 * @param context A pointer to a context, not used in this function.
 * @return Always returns 1.
 */
int linePrintRaw( const char *line, void *context );

/**
 * @brief Filters and prints a line based on a given context.
 *
 * This function processes a given line and checks if it matches a specified context.
 * If the line matches the context, it prints the line and returns 1. If the line does not match,
 * it returns 0. If either the line or context is NULL, it returns -1.
 *
 * @param line The line to be processed and filtered.
 * @param context The context to compare against the first field of the line.
 * @return 1 if the line matches the context and is printed, 0 if it does not match,
 *         and -1 if either the line or context is NULL.
 */
int lineFilterPrint( const char *line, void *context );