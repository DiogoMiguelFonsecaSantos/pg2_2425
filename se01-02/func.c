/*********************************************************************
 * @file   func.c
 * @brief  Todas as funções necessárias à resolução do grupo 2 do enunciado;
 * @version 1.0
 * @date 17 Out 2024
 * @author Diogo Santos
 **********************************************************************/

#include <stdio.h>
#include "func.h"
#include <string.h>
#include <ctype.h> //para o tolower

char *splitField(char *str)
{
    if (str == NULL)// Verifica se a string fornecida inválida.
    {
        printf("String sem nenhum campo / String NULL\n\n");// Se for NULL, retorna NULL imediatamente para indicar String sem nenhum campo.
        return NULL;
    }

    while (*str != ';' && *str != '\0')//Varrimento da string até encontrar um separador ';' ou o final da string ('\0').
    {
        str++; // Avança o ponteiro para o próximo char.
    }

    if (*str == ';')// Se o char encontrado for o separador ';', processa o final do campo.
    {
        *str = '\0';    // Substitui o separador ';' por '\0', terminando a string atual.
        return str + 1; // Retorna o ponteiro para o próximo campo, logo após o ';'.
    }
    else
    {                // Se não houver mais separadores, significa que chegamos ao fim da string.
        return NULL; // Retorna NULL para indicar que não há mais campos a processar.
    }
}

void separatorUnify(char str[])
{
    int i = 0, j = 0;

    // Ignorar separadores no início (espaços, tabulações ou novas linhas)
    while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
    {
        i++;
    }

    // Processar a string, copiando apenas caracteres não-separadores ou adicionando um único espaço entre palavras
    while (str[i] != '\0')
    {
        if (str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
        {
            // Copiar caractere não-separador para a posição correta
            str[j++] = str[i];
        }
        else if (j > 0 && str[j - 1] != ' ')
        {
            // Se encontramos um separador e o último caractere copiado não é um espaço,
            // adicionamos um único espaço (para evitar múltiplos espaços consecutivos)
            str[j++] = ' ';
        }
        i++;
    }

    // Remover qualquer espaço extra no final
    if (j > 0 && str[j - 1] == ' ')
    {
        j--;
    }

    // Colocar o terminador nulo no final da nova string
    str[j] = '\0';
}


int strcmp_ic(const char *str1, const char *str2)
{
    char *str1copy = str1;
    char *str2copy = str2;

    while (*str1 && *str2)
    {
        char c1 = tolower((unsigned char)*str1);
        char c2 = tolower((unsigned char)*str2);

        if (c1 != c2)
        {
            return c1 - c2;
        }

        str1++;
        str2++;
    }

    int result = tolower((unsigned char)*str1) - tolower((unsigned char)*str2);
    printf("%d   %s    %s   %d  %d\n",result,str1,str2,strlen(str1copy),strlen(str2copy));
    return result;
}



