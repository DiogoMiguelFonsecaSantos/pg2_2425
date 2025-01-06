#ifndef VEC_H
#define VEC_H

#include "bookModule.h"

#define INIT_SPACE 10

typedef struct{ // Descritor de um vetor
    Book **refs; // array alojado dinamicamente
    int size; // quantidade de elementos preenchidos
    int space; // quantidade de elementos alojados
}VecBookRef;

/**
 * @brief Allocates memory for a vector descriptor of references and initializes it with initial conditions.
 * 
 * The size field will be set to 0, indicating an empty state.
 * The space field will be set to a value consistent with the initialization of the refs field.
 * 
 * @return VecBookRef* Pointer to the newly created VecBookRef structure.
 */
VecBookRef *vecRefCreate ( void );

/**
 * @brief Adds a book reference to the vector.
 *
 * This function adds the reference of a book to the vector. The parameter `vec` indicates the vector descriptor.
 * The parameter `ref` indicates the book to reference. The allocated space for the pointer array should be resized
 * when necessary, using the standard library function `realloc`. The resizing should occur in blocks of multiple
 * elements for efficiency reasons.
 *
 * @param vec The vector descriptor.
 * @param ref The book to reference.
 */
void vecRefAdd( VecBookRef *vec, Book *ref );

/**
 * @brief Returns the number of elements referenced in the reference vector identified by vec.
 *
 * @param vec Pointer to the VecBookRef structure.
 * @return The number of elements referenced in the vector.
 */
int vecRefSize( VecBookRef *vec );

/**
 * @brief Returns the address of the element referenced at the position index of the reference vector identified by vec.
 * 
 * @param vec Pointer to the reference vector.
 * @param index Position in the reference vector.
 * @return Book* Address of the referenced element at the given position. If the position is invalid, returns NULL.
 */
Book *vecRefGet( VecBookRef *vec, int index );

/**
 * @brief Sorts the array of references identified by vec in ascending alphabetical order by the titles of the referenced books.
 * 
 * This function supports the "l" command and uses the qsort library function to perform the sorting.
 * 
 * @param vec Pointer to the array of book references to be sorted.
 */
void vecRefSortTitle( VecBookRef *vec );

#endif // VEC_H