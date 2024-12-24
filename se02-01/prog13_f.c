#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "prog13.h"
#include <ctype.h>

int main(int argc, char *argv[]){
	
	printf("Leitura das linhas de um ficheiro:\n");
	printf("\n");
	
	const char *filename = argv[1];
	
	//primeiro caso apenas leitura das linhas
	int total_linhas = processFile(filename, linePrintRaw, NULL);

	printf("numero total de linhas: %d\n", total_linhas);



return 0;	
}

