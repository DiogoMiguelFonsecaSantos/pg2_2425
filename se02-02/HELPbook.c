

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <errno.h>
#include "func2.h"
#include "funcSE1.h"
#include "procTextFile.h"

// 2.1 - Macros
#define MAX_BOOKS 300    // Número máximo de livros na coleção por agora            (wc -l dados.csv: 296)

#define MAX_TITLE 200    // Tamanho máximo do título -f1                            (cut -d";" -f1 dados.csv | wc -L: 200)
#define SIZE_ISBN 10     // Tamanho máximo do ISBN -f2                              (cut -d";" -f2 dados.csv | wc -L: 10)
#define SIZE_ISBN_13 13  // Tamanho máximo do ISBN 13 -f3                           (cut -d";" -f3 dados.csv | wc -L: 13)
#define MAX_AUTHORS 92   // Tamanho máximo do campo de autores -f4                  (cut -d";" -f4 dados.csv | wc -L: 92)
#define MAX_PUB_NAME 51  // Tamanho máximo do campo do editor -f5                   (cut -d";" -f5 dados.csv | wc -L : 51)
#define MAX_KEYWORDS 127 // Tamanho máximo do campo de palavras-chave -f6           (cut -d";" -f6 dados.csv | wc -L: 127)
#define MAX_PAGES 4      // Tamanho máximo do campo de número de páginas -f7        (cut -d";" -f7 dados.csv | wc -L: 4)
#define MAX_DATE 10      // Tamanho máximo do campo de data de publicação -f8       (cut -d";" -f8 dados.csv | wc -L: 10)
#define MAX_BINDING 9    // Tamanho máximo do campo de tipo de encadernação -f9     (cut -d";" -f9 dados.csv | wc -L: 9)
#define MAX_PRICE 10     // Tamanho máximo do campo de preço -f10                   (cut -d";" -f10 dados.csv | wc -L: 10)

int fillBookData( BookData *b, const char *line ){
    char aux[MAX_LINE];
    char *p1, *p2;
    int i = 0;
    int countField = 1;
    while(*(line+i) != '\0'){
        aux[i] = *(line+i);
        i++;
    }
    aux[i] = '\0';
    p1 = aux;
    do{

        p2 = splitField(p1);
        separatorUnify(p1);
        switch(countField){
            case 1:
                if((strlen(p1) > MAX_TITLE_SE2-1)){
                    return 0;
                }
                strcpy(b->title, p1);
                break;

            case 2:
                break;

            case 3:
                if((strlen(p1) != SIZE_ISBN_SE2-1)){
                    return 0;
                }
                strcpy(b->isbn, p1);
                break;
                
            case 4:
                if((strlen(p1) > MAX_AUTHORS_SE2-1)){
                    return 0;
                }
                strcpy(b->authors, p1);
                break;
            
            case 5:
                if((strlen(p1) > MAX_PUB_NAME_SE2-1)){
                    return 0;
                }
                strcpy(b->publisher, p1);
                break;

            default:
                break;
        }
        countField++;
    }while((p1 = p2) != NULL);
    return 1;
}