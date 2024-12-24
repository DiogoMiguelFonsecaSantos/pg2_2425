#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "func.h"

#define SEPARADOR ';'
#define MAX_SIZE 255 + 1
 


int main() 
{
	// Array de chars com capacidade para 255 carateres úteis 
	char s[MAX_SIZE]; 
	char *str1 = s , *str2;
	
	//Pedir input ao utilizador
	puts("Intruduza texto");
	
	//A cada iteração lê até 255 caracteres de uma linha de "stdin" para "str1" 
	while (fgets(str1, MAX_SIZE,  stdin) != NULL)
	{	
		do{ 
			str2 = splitField( str1 ); 
			printf( "{%s}", str1 ); 
		} while( (str1 = str2) != NULL ); 
		
		str1 = s;
		puts("\n");
	}
	printf("\n\n\n\n");
	
	return 0;	
}
	
	
		
	
