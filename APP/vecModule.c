#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "bookModule.h"
#include "vecModule.h"
#include "Serie1.h"
#include "Serie2.h"

VecBookRef *vecRefCreate(void) {
    VecBookRef *vec = (VecBookRef *)malloc(sizeof(VecBookRef)); // Allocates memory for the VecBookRef structure
    if (!vec) 
        return NULL; // Verifies if vec is NULL, if so, return NULL

    vec->refs = (Book **)malloc(INIT_SPACE * sizeof(Book *)); // Allocates memory for the refs array
    if (!vec->refs) { // Verifies if vec->refs is NULL, if so, free the memory allocated for vec and return NULL
        free(vec); 
        return NULL;
    }

    vec->size = 0; // Initializes the size field with 0
    vec->space = INIT_SPACE; // Initializes the space field with INIT_SPACE = 10
    return vec; // Returns the address of the VecBookRef structure
}



