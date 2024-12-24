/*********************************************************************
 * @file   func.c
 * @brief  Todas as funções necessárias à resolução do grupo 2 do enunciado;
 * @version 1.0
 * @date 17 Out 2024
 * @author Diogo Santos
 **********************************************************************/

#include <stdio.h>
#include "funcSE1.h"
#include <string.h>
#include <ctype.h> //para o tolower

char *splitField(char *str)
{
    if (str == NULL)
        return NULL;

    while (*str != ';' && *str != '\0')
        str++;
    

    if (*str == ';')
    {
        *str = '\0';
        return str + 1;
    }
    else
        return NULL;
}

void separatorUnify(char str[])
{
    int i = 0, j = 0;

    while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
    {
        i++;
    }

    while (str[i] != '\0')
    {
        if (str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
        {
            str[j++] = str[i];
        }
        else if (j > 0 && str[j - 1] != ' ')
        {
            str[j++] = ' ';
        }
        i++;
    }

    if (j > 0 && str[j - 1] == ' ') 
    {
        j--;
    }

    str[j] = '\0';
}

int strcmp_ic(const char *str1, const char *str2)
{
    while (*str1 && *str2)
    {
        char c1 = tolower((unsigned char)*str1);
        char c2 = tolower((unsigned char)*str2);

        if (c1 != c2)
            return c1 - c2;

        str1++;
        str2++;
    }

    return tolower((unsigned char)*str1) - tolower((unsigned char)*str2);
}