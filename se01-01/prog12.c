#include <stdio.h>
#include "prog01.h"

void printBinary(int num)
{
    for (int i = 31; i >= 0; i--) // varrimento de todos os 32 bits
    {
        printf("%d", (num >> i) & 1); // print de cada bit deixando um espaço a cada 4
        if (i % 4 == 0)
            printf(" "); // espaço
    }
    printf("\n");
}

int main()
{

    int integer;
    int status;

    printf("Digite um valor inteiro (Números codificados de −2147483648 a 2147483647): ");
    scanf("%d", &integer); // Leitura do standard input do número para encoding
    printf("Valor inteiro em bin: ");
    printBinary(integer);

    unsigned short encodedValue = encode(integer, &status); // Processo de encoding do número

    if (status == 0)
    { // Mensagem de aviso quando a função encode indica resultado inválido.
        printf("\n\nWARNING: o número %d não pode ser representado nos 11 bits significativos\napós os Right Shifts e manter o seu valor original!!\n(codificação é inválida).\n", integer);
    }

    int decodedValue = decode(encodedValue); // Processo de decoding do número

    // Exibe os resultados
    printf("\nValor codificado em hexa: 0x%04X\n", encodedValue);
    printf("Valor codificado em bin: ");
    printBinary(encodedValue);
    printf("\nValor decodificado: %d\n", decodedValue);

    return 0;
}

/*
Observações para a alínea 1.1
Para os inteiros dados na tabela, este algoritmo de descodificação funciona.
Para álem disso, números que tenham bits (incluindo o bit de sinal - IMPORTANTE) que consigam ser shiftados na sua totalidade para a janela dos primeiros
11 bits, conseguem ser codificados sem perder o seu valor inicial, mesmo com números grande como 2143289344 (0111 1111 1100 0000 0000 0000 0000 0000):

 • Da direita para a esquerda, a partir do primeiro bit que esteja a 1, se a quantidade de bits até ao bit de sinal (signalBit incluido) for menor ou igual a
   VAL_BITS = 11, o número pode ser codificado sem perder o seu valor original.

 • Neste caso, a quantidade de bits até ao bit de sinal (signalBit incluido) é 10.
   Então, o número de shifts a fazer é 21, a parte significativa fica 011 1111 1110, a codificação final fica 1010 1011 1111 1110 (0xabfe).
   Na descodificação, shift = 1010 1011 1111 1110 >> 11 = 0000 0000 0001 0101 (aqui não problemas no shift porque o shift é um unsigned int) e
   a parte significativa é 0000 0111 1111 1111 & 1010 1011 1111 1110 = 0000 0011 1111 1110 e é recuperado o valor original fazendo o Lshift de 10101.

 No caso de data = 1111 1111 1110 0000 0000 0000 0000 0000 (-2097152 em decimal), a quantidade de bits até ao bit de sinal (signalBit incluido) é 11, mas na
 realidade só precisamos de um bit porque como está tudo a 1 a partir do primeiro 1 que se vê da direita para a esquerda, porque o sinal de bit está repetido.
 De qualquer maneira, este número é codificável. Então, o número de shifts a fazer é 11 (01011), porque são o número de shifts mínimo para que se veja o bit
 de sinal na janela dos primeiros 11 bits; a parte significativa fica 100 0000 0000, a codificação final fica 0101 1100 0000 0000 (0x5c00).
 Na descodificação, shift = 0101 1100 0000 0000 >> 11 = 0000 0000 0000 1011 (aqui não problemas no shift porque o shift é um unsigned int) e
 a parte significativa é 0000 0111 1111 1111 & 0101 1100 0000 0000 = 0000 0100 0000 0000. O bit de sinal é verificado e como é 1, o bit é extendido
 a 32 bits, ficando 1111 1111 1111 1111 1111 1100 0000 0000. é recuperado o valor original fazendo o Lshift de 01011.

 Para um número não consegue ser codificado sem perder o seu valor original, como o -1221209919 (1011 0111 0011 0101 1101 0000 1100 0001), a quantidade de
 bits até ao bit de sinal (signalBit incluido) é 32 bits (tudo). Se observarmos pelo encode, o número de shifts contado seria 21 e teriamos uma parte
 significativa 0000 0101 1011 1001, logo a codificação final ficaria 1010 1101 1011 1001 (0xadb9).
 Através do processo de decode já falado, perderiamos 21 bits que definem em conjunto com os outros o valor original, e o resultado do decode seria -1222639616:
  • 1011 0111 0010 0000 0000 0000 0000 0000 que é diferente de 1011 0111 0011 0101 1101 0000 1100 0001
*/