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
#include <stdbool.h>
#include <errno.h>
#include "funcSE1.h"
#include "procTextFile.h"

// 2.1 - Macros
#define MAX_BOOKS 300    // Número máximo de livros na coleção por agora           (wc -l dados.csv: 296)
#define MAX_TITLE 200    // Tamanho máximo do título f1                            (cut -d";" -f1 dados.csv | wc -L: 200)
#define SIZE_ISBN 10     // Tamanho máximo do ISBN f2                              (cut -d";" -f2 dados.csv | wc -L: 10)
#define SIZE_ISBN_13 13  // Tamanho máximo do ISBN 13 f3                           (cut -d";" -f3 dados.csv | wc -L: 13)
#define MAX_AUTHORS 92   // Tamanho máximo do campo de autores f4                  (cut -d";" -f4 dados.csv | wc -L: 92)
#define MAX_PUB_NAME 51  // Tamanho máximo do campo do editor f5                   (cut -d";" -f5 dados.csv | wc -L : 51)
#define MAX_KEYWORDS 127 // Tamanho máximo do campo de palavras-chave f6           (cut -d";" -f6 dados.csv | wc -L: 127)
#define MAX_PAGES 4      // Tamanho máximo do campo de número de páginas f7        (cut -d";" -f7 dados.csv | wc -L: 4)
#define MAX_DATE 10      // Tamanho máximo do campo de data de publicação f8       (cut -d";" -f8 dados.csv | wc -L: 10)
#define MAX_BINDING 9    // Tamanho máximo do campo de tipo de encadernação f9     (cut -d";" -f9 dados.csv | wc -L: 9)
#define MAX_PRICE 10     // Tamanho máximo do campo de preço f10                   (cut -d";" -f10 dados.csv | wc -L: 10)

typedef struct book {
 char title[MAX_TITLE_SE2];
 char isbn[SIZE_ISBN_SE2];
 char isbn13[SIZE_ISBN_13];
 char authors[MAX_AUTHORS_SE2];
 char publisher[MAX_PUB_NAME_SE2];
 char keywords[MAX_KEYWORDS];
 char num_pages[MAX_PAGES];
 char date[MAX_DATE];
 char binding[MAX_BINDING];
 char price[MAX_PRICE];
} BookData;

typedef struct{
 BookData books[MAX_BOOKS];
 BookData *refs[MAX_BOOKS];
 int count; // quantidade de elementos preenchidos em books
} Collection;

/**
 * @brief Fills the BookData structure with data parsed from a given line.
 *
 * This function takes a BookData structure and a line of text, then parses the line
 * to fill the fields of the BookData structure. The line is expected to contain
 * fields separated by a specific delimiter. It is intended to store book information.
 * It should identify the fields in the line indicated by 'line' and copy the relevant
 * ones to the structure indicated by 'b', standardizing their contents. It should use
 * the functions splitField and separatorUnify from the previous series.
 *
 * @param b Pointer to the BookData structure to be filled.
 * @param line The line of text containing the book data fields.
 * @return int Returns 1 if the function was successful, 0 otherwise.
 *
 * @note The function assumes that the line contains exactly 10 fields, and each field
 *       is separated by a specific delimiter. The sizes of the fields are defined
 *       by the fieldSizes array. Not sure if that was the intent of the teachers or not, though.
 *       I just assumed somethings in the assignment given.
 */
int fillBookData( BookData *b, const char *line );

/**
 * @brief Adds book data to a collection's storage.
 *
 * This function is intended to be passed in the action parameter of the processFile function to add book data
 * to a collection's storage. The text line indicated by line contains the information fields, as obtained from
 * the file. The context parameter represents the address of the descriptor of type Collection that stores the data.
 * In this, the books array field is intended to store the data, with one element per book, and the count field
 * represents the number of filled elements. In this exercise, the refs array field is not used.
 * Given the limited capacity of the descriptor, if the number of books is excessive, the data in the initial part
 * of the file is considered. The fillBookData function should be used to add the new element.
 *
 * @param line Text line containing the book information fields.
 * @param context Address of the descriptor of type Collection that stores the data.
 * @return int Returns 1 on success, or 0 otherwise, due to incorrect line or insufficient descriptor capacity.
 * 
 * @note Not sure this this is how it works, should review this function if i have time. 
 */
int collAddBook( const char *line, void *context );

/**
 * @brief Sorts the books in the array field books of the collection pointed to by col by title.
 * 
 * The order is alphabetically ascending, case insensitive.
 * It should use the qsort function from the standard library.
 * 
 * @param col Pointer to the collection of books to be sorted.
 * 
 * @note If col is NULL or if the book count in the collection is less than or equal to 1, the function returns without doing anything.
 *        This function uses a helper compare function to sort the collection by title.
 */
void collSortTitle( Collection *col );





void collSortRefIsbn( Collection *col );






int bookContainsAuthor( BookData *b, const char *word );

