#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "prog13.h"
#include <ctype.h>

int main(int argc, char *argv[]){
	
	printf("Leitura das linhas de um ficheiro:\n");
	printf("\n");
	
	const char *filename = argv[1];
	char *context = argv[2];
	
	if(context == NULL){
	printf("erro context.\n");
	return -1;
	}
	//segundo caso apenas leitura das linhas com o mesmo campo
	int total_linhas = processFile(filename, lineFilterPrint, context);
	
	printf("numero total de linhas: %d\n", total_linhas);



return 0;	
}

