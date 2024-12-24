#include <stdio.h>
#include <ctype.h>
#include <stdlib.h> 
#include <string.h> 
#include "func.h"

#define MENOR -1
#define MAIOR +1
#define MAX_SIZE 255 + 1
#define SEPARADOR ';'

int main(int argc, char** argv)
{
	// Verifica se o número correto de argumentos foi passado
	if (argc != 3)
	{
		puts("Utilização: filter <posição do campo> <string a comparar>");
		return 1;
	}
	
	// Converte a posição passada no argumento para um inteiro
	char c;
	char *cptr = &c;
	char **endptr = &cptr;
	unsigned long argIdx = strtoul(argv[1], endptr, 10);
	
	// Verifica se a posição é válida
	if (argIdx < 1)
	{
		puts("<posição do campo> deve ser um número, de valor 1 ou superior");
		return 1;
	}
	
	char* strArg = argv[2];  // String a comparar
	separatorUnify(strArg);
	
	char str1[MAX_SIZE];   // Armazena a linha introduzida no "stdin"
	char linhaOg[MAX_SIZE]; // Armazena a linha introduzida sem alterações
	
	char* linhaIn; // Ponteiro para o campo atual
	char *campo; // Ponteiro para o campo seguinte
	puts("Introduza as linhas");
	
	while ( fgets(str1, MAX_SIZE, stdin) != NULL )
	{
		linhaIn = str1;
		strcpy(linhaOg, str1);  // Guarda a linha original
		int idx = 1; // Indica o número do campo atual
		
		// Processa os campos da linha introduzida até não serem detetados mais campos
		while (1)
		{
			campo = splitField(linhaIn); // "linhaIn" é campo atual 
			separatorUnify(linhaIn); // "campo" é o próximo campo
			 
			// Compara o campo atual com a string a comparar
			// Verifica se o campo atual corresponde ao indicado em "argIdx"
			if ((strcmp_ic(linhaIn, strArg) == 0) && (idx == argIdx))
			{
				printf("%s", linhaOg); 	// Caso as condições se verifiquem imprime a linha original
				break;
			}
			
			if (campo == NULL) 
				break;
				
			idx++; 	
			linhaIn = campo; // Avança para o próximo campo
		}
	}
}
