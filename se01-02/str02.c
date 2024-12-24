/*********************************************************************
 * @file   str02.c
 * @brief  Programa de teste (enunciado 2.2);
 * @version 1.0
 * @date 17 Out 2024
 * @author Diogo Santos
 **********************************************************************/

#include <stdio.h>
#include "func.h"

int main() //./str02 < in.txt
{
    char lineBuffer[256]; // Buffer para armazenar uma linha de até 255 caracteres, como dito no enunciado

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
            nextField = splitField(field);
            printf("{%s}", field); // Imprime cada campo entre chaves
            field = nextField;
        } while (field != NULL);

        printf("\n"); // Nova linha após processar todos os campos de uma linha
    }

    return 0;
}