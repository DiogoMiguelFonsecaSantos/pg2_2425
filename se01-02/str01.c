
#include <stdio.h>
#include "func.h"

int main() //./str01
{
    char s[] = "primeiro;; terceiro \t; ; palavras do quinto \n";
    char *p1 = s, *p2;
    do
    {
        p2 = splitField(p1);
        printf("{%s}", p1);
    } while ((p1 = p2) != NULL);
    
    return 0;
}