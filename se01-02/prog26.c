#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "func.h"

#define MENOR -1
#define MAIOR +1

int main(int argc, char** argv)
{
	// Não foi intruduzida palavra
	if (argv[1] == NULL)
	{
		puts("Utilização: prog26 palavra");
		return 1;
	}
			
	char* word = argv[1];
	char word2[50+1]; // Arrau de chars para armezenar uma palavra até 50 caracteres
	int result = 0;
	
	//Pedir input ao utilizador
	puts("Intruduza as palavras a comparar");
	
	/* 
	* A cada iteração:
 	* Lê para "word2" uma palavra, no máximo 50 carateres, de uma linha de "stdin".
 	* Chama a função strcmp_ic sobre "word" e "word2".
 	* Apresenta o resultado da comparação no "stdout"
 	* Sai do ciclo se a leitura chegar ao EOF de um ficheiro ou resultar num erro.
	*/
	while((result = scanf("%50s", word2)) != EOF) 
	{	
		//while (getchar() != '\n'); //lê os restantes caracteres da linha mas não os armazena
			 
		if (result != 1)
		{
			puts("Erro no scanf");
			return 1;
		}
		
		result = strcmp_ic(word, word2); 
		
		if (result < 0)
			printf("%s < %s \n", word, word2);
			
		else if (result > 0)
			printf("%s > %s  \n", word, word2);
			
		else
			printf("%s = %s \n", word, word2);
	}
}
		

