/*********************************************************************
 * @file   str06.c
 * @brief  Programa de teste (enunciado 2.6);
 * @version 1.0
 * @date 18 Out 2024
 * @author Diogo Santos
 **********************************************************************/
#include <stdio.h>
#include "func.h"

int main(int argc, char *argv[])
{
    // Verificar se o número de argumentos está correto
    if (argc != 2)
    {
        fprintf(stderr, "Uso: %s <palavra_a_comparar>\n", argv[0]);
        return 1;
    }

    char *palavra_a_comparar = argv[1];
    char buffer[256]; // Buffer para ler a string do standard input
    char *campo;      // Para armazenar os campos separados por ponto e vírgula

    // Ler palavras do standard input usando scanf
    while (scanf("%s", buffer) != EOF)
    {
        // Unificar separadores (espaço, tabulação, nova linha) na string lida
        separatorUnify(buffer);

        // Processar campos separados por ';' usando splitField
        campo = buffer;
        while (campo != NULL)
        {
            // Obter o próximo campo
            char *proximo_campo = splitField(campo);

            // Comparar o campo atual com a palavra a comparar
            int resultado = strcmp_ic(campo, palavra_a_comparar);

            // Exibir o resultado da comparação
            if (resultado < 0)
            {
                printf("'%s' é alfabeticamente inferior a '%s'\n", campo, palavra_a_comparar);
            }
            else if (resultado == 0)
            {
                printf("'%s' é igual a '%s'\n", campo, palavra_a_comparar);
            }
            else
            {
                printf("'%s' é alfabeticamente superior a '%s'\n", campo, palavra_a_comparar);
            }

            // Passar para o próximo campo
            campo = proximo_campo;
        }
    }

    return 0;
}