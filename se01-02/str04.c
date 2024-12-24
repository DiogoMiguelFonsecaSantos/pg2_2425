/*********************************************************************
 * @file   str04.c
 * @brief  Programa de teste (enunciado 2.4);
 * @version 1.0
 * @date 19 Out 2024
 * @author Diogo Santos
 **********************************************************************/

#include <stdio.h>
#include "func.h"

int main() // ./prog24 < in.txt
{
    char lineBuffer[256]; // Buffer para armazenar uma linha de até 255 caracteres

    // Lê cada linha do input até ao EOF (End Of File)
    while (fgets(lineBuffer, sizeof(lineBuffer), stdin))
    {
        // Remover o '\n' no final da linha, se existir
        for (int i = 0; lineBuffer[i] != '\0'; i++)
        {
            if (lineBuffer[i] == '\n')
            {
                lineBuffer[i] = '\0';
                break;
            }
        }

        char *field = lineBuffer;
        char *nextField;

        // Aplica splitField em cada campo da linha
        do
        {
            // Separa o próximo campo com base no separador ';'
            nextField = splitField(field);

            // Aplica a função separatorUnify ao campo atual
            separatorUnify(field);

            // Imprime o campo uniformizado entre chaves, mesmo que esteja vazio
            printf("{%s}", field);

            // Avança para o próximo campo
            field = nextField;
        } while (field != NULL); // Repete até não haver mais campos

        printf("\n"); // Nova linha após processar todos os campos de uma linha
    }

    return 0;
}