#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "prog13.h"
#include <ctype.h>

// para ler linhas

int processFile( const char *filename,int (*action)( const char *line, void *context ),void *context ){

FILE *file = fopen( filename, "r" );

if( file == NULL ) {
    return -1;
};

char line[512];
int count = 0;
int i = 1;

while(fgets(line, sizeof(line), file) != NULL) {

    /*
    printf("num da linha: %d\n", i++);
    char *contextString = (char *)context;
    printf("%s", contextString);
    */

    count+= action( line, context );

 }
 return count;

 }




	
