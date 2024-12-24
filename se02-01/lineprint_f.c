#include <stdio.h>
#include "prog13.h"

int linePrintRaw( const char *line, void *context ){

    printf( "%s\n", line );
    return 1;

}
