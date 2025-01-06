// bookModule.h
#ifndef BOOK_H
#define BOOK_H

#define MAX_TITLE 200    // Tamanho máximo do título -f1                            (cut -d";" -f1 dados.csv | wc -L: 200)
#define MAX_ISBN 10      // Tamanho máximo do ISBN -f2                              (cut -d";" -f2 dados.csv | wc -L: 10)
#define MAX_AUTHORS 92   // Tamanho máximo do campo de autores -f4                  (cut -d";" -f4 dados.csv | wc -L: 92)
#define MAX_PUB_NAME 51  // Tamanho máximo do campo do editor -f5                   (cut -d";" -f5 dados.csv | wc -L : 51)

typedef struct {
    char *title;         // string alojada dinamicamente
    char isbn[MAX_ISBN]; // string com dimensão fixa
    char *authors;       // string alojada dinamicamente
    char *publisher;     // string alojada dinamicamente
} Book;

/**
 * @brief Creates a book descriptor with fields obtained from the specified text line.
 * 
 * This function dynamically allocates the necessary space for a structure of type Book,
 * as well as for the strings to be associated with the fields title, authors, and publisher.
 * It returns the address of the allocated Book on success, or NULL if the text line is invalid.
 * 
 * This function can be constructed by adapting the old function fillBookData. Care should be taken
 * to avoid leaving allocated space unused, especially when the line is invalid.
 * 
 * @param line The text line containing the book information.
 * @return Book* The address of the allocated Book structure, or NULL if the line is invalid.
 */
Book *bookCreate(const char *line);

/**
 * @brief Frees the dynamically allocated memory occupied by the given Book struct and its dependent strings.
 *
 * @param b Pointer to the Book struct to be freed.
 */
void bookFree(Book *b);

#endif // BOOK_H