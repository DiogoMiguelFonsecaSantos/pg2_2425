// #include <stdio.h>
// #include "pergunta2.h"
// #include "string.h"

// #define MAX_FIELDS 4
// #define FIELD_DELIMITER ';'

// int fillBookData( BookData *b, const char *line ){
//     char fields[MAX_FIELDS][128]; // Armazena os campos extraídos da linha
//     int field_count;

//     // Divide a linha nos campos esperados
//     field_count = splitField(line, fields, MAX_FIELDS, FIELD_DELIMITER);
//     if (field_count != MAX_FIELDS) {
//         return 0; // Falha se o número de campos não for o esperado
//     }

//     // Uniformiza o conteúdo de cada campo
//     for (int i = 0; i < field_count; i++) {
//         separatorUnify(fields[i]);
//     }

//     // Copia os campos relevantes para a estrutura BookData
//     strncpy(b->title, fields[0], sizeof(b->title) - 1);
//     b->title[sizeof(b->title) - 1] = '\0'; // Garante terminação nula

//     strncpy(b->authors, fields[1], sizeof(b->authors) - 1);
//     b->authors[sizeof(b->authors) - 1] = '\0';

//     strncpy(b->year, fields[2], sizeof(b->year) - 1);
//     b->year[sizeof(b->year) - 1] = '\0';

//     strncpy(b->genre, fields[3], sizeof(b->genre) - 1);
//     b->genre[sizeof(b->genre) - 1] = '\0';

//     return 1;
// }

// int collAddBook( const char *line, void *context ){
// 	if(line == NULL ) return 0;
// 	Collection * collection = (Collection *) context;
// 	if(collection->count + 1 > MAX_BOOKS) return 0;
// 	int retorno = fillBookData( collection-> books, line);
// 	collection->count++;
// 	return retorno;
// }
