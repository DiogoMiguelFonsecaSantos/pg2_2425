
/*********************************************************************
 * @file   prog01.c
 * @brief  Funções necessárias à resolução do enunciado 1.1 (decode, ...);
 * @version 1.0
 * @date 1 Out 2024
 * @author Diogo Santos
 **********************************************************************/

/**Na utilização de inteiros com sinal a 32 bits, são frequentes os valores que não necessitam de ocupar os 32
 * bits por terem uma sequência de bits a zero na parte baixa ou uma sequência de bits com o valor do sinal
 * na parte alta. Tirando partido desta observação, propõe-se uma representação compacta, a 16 bits, com o seguinte formato:
 *
 * • bits 0 a 10: codificam a parte significativa do valor, a 11 bits, incluindo o sinal;
 *
 * • bits 11 a 15: codificam o deslocamento, indicando o número de bits a deslocar para a esquerda para
 *   reproduzir o valor original, de modo a posicionar a parte significativa na palavra a 32 bits.
 *
 * A tabela seguinte contém exemplos de alguns valores acompanhados de uma codificação possível.
 * ____________________________________________________________________________________________________________________________________________________________________
 * Valor a 32 bits                       |      Deslocamento (5 bit)   | Parte significativa (11 bit) Já RShiftado  |     Codificação Bin    |  Codificação Hexa
 *   0    0000 0000 .. 0000 0000         |          0 (00000)          |              000 0000 0000                 |   0000 0000 0000 0000  |     0x0000
 *   1    0000 0000 .. 0000 0001         |          0 (00000)          |              000 0000 0001                 |   0000 0000 0000 0001  |     0x0001
 *   2    0000 0000 .. 0000 0010         |          0 (00000)          |              000 0000 0010                 |   0000 0000 0000 0010  |     0x0002
 *  -1    1111 1111 .. 1111 1111         |          0 (00000)          |              111 1111 1111                 |   0000 0111 1111 1111  |     0x07ff
 *  -2    1111 1111 .. 1111 1110         |          0 (00000)          |              111 1111 1110                 |   0000 0000 0000 0000  |     0x07fe
 *   2048  0000 0000 ..0 1000 0000 0000  |          2 (00010)          |              010 0000 0000                 |   0001 0010 0000 0000  |     0x1200
 *  -2048  1111 ..1 1111 1000 0000 0000  |          1 (00001)          |              100 0000 0000                 |   0000 1100 0000 0000  |     0x0c00
 * ___________________________________________________________________________________________________________________________________________________________________
 *
 * Há valores que podem ter várias representações equivalentes, por terem menos do que 11 bits significativos.
 * Também há valores não codificáveis neste formato, por terem mais do que 11 bits significativos.
 *
 * */

/* in my WSL:
int = 4 bytes = 32 bits <<==========
long = 8 bytes = 64 bits
short = 2 bytes = 16 bits <<==========
*/

#include <stdio.h>

// A função encode, abaixo, realiza a codificação do parâmetro data e devolve o respetivo código a 16 bits.
#define VAL_BITS 11

/**
 * @brief  Realiza a codificação do parâmetro data.
 * @return Devolve o respetivo código a 16 bits.

 */
/**
 * @brief Realiza a codificação do parâmetro data e afeta a variável valid.
 * @param data Valor de 32 bits que será codificado.
 * @param valid Ponteiro para um int que indica a validade do código gerado: se a codificação for válida, o int vale 1, else 0.
 * @return Devolve o respetivo código a 16 bits.
 * @note   Esta função foi dada pelo enunciado.
 */
unsigned short encode(int data, int *valid) // 32 bits para 16 bits sem sinal
{
    int initialData = data;
    int shift = 0; // shift inicia a 0
    int highBits;  // a variavel contem os bits mais à esquerda do valor original de data, que foram deslocados para se ajustarem dentro da window dos
                   // primeiros 11 bits
    while ((highBits = data >> VAL_BITS - 1) != 0 && highBits != ~0)
    /*instancia a variável highBits ao valor de data shiftado de 10 bits
      nao ha shift se highBits tiver os bits todos a 0 ou todos a 1 (~0):

        • se highBits = 0,todos os bits mais significativos do valor foram deslocados e o valor
        de data já foi reduzido a algo que pode ser representado com 11 bits

        • se highBits = ~(0) ou tudo a 1, estamos a lidar com um número negativo e o valor de data
        está negativo e totalmente preenchido com 1s, e por consequência  o laço também deve parar porque
        o número negativo já está pronto para ser codificado.*/
    {
        data >>= 1; // Right Shift para encoding, logo Left Shift para decoding: cada vez que este shift é feito, o número é dividido por 2
        ++shift;    // o shift feito anteriormente é contado
    }

    /*Não preciso de me preocupar com o número de shifts exceder os 31 shifts:
        • A função encode recebe um int que é de 32 bits. Sendo que queremos compactar este inteiro num unsigned short e queremos que os bits significativos
          façam parte da janela dos primeiros 11 bits do short, e já que temos 5 bits para codificar o numero de vezes que shiftamos o int de input da função
          (significa que podemos shiftar entre 0 e 31 vezes), o número de vezes que vamos precisar de shiftar o int nunca vai exceder as 31 vezes.
    */

    /*Preciso de me preocupar com bits que se possam perder na codificação:
        • Caso isso aconteça, o resultado do encoding é inválido e consegue-se meter *valid = 0.
          Para que isso aconteça, pode se fazer uma comparação entre a data antes de encoded e depois de encoded, uma espécie de checkpoint
          para averiguar se o unsigned short retornado é valido. A melhor maneira será provavelmente guardar o valor original de data e comparar com a data
          depois dos shifts mas shiftada para a esquerda o número de shifts contado.
    */

    // Checkpoint
    if ((data << shift) == initialData)
    {
        *valid = 1; // Tudo correu bem: caso de sucesso
    }
    else
    {
        *valid = 0; // Existem bits que foram perdidos: caso oposto
    }

    
    return shift << VAL_BITS | data & ~(~0 << VAL_BITS);
    /* shift << VAL_BITS: o valor do shift fica guardado nos bits de 11 a 15 por causa do LShift dos 11 bits significativos
       data & ~(~0 << VAL_BITS): mascara de bits (primeiros 11 bits a 1 e resto a 0) aplicada ao numero de input (primeiros 11 bits de data
       JÁ RShifted e resto a 0 para a esquerda)*/

    /*resultado:
    15 14 13 12 11 | 10  9 8  7  6  5  4  3  2  1  0     S: Number of Shifts Done Bits (de 0 a 31 shifts possíveis)
    S4 S3 S2 S1 S0 |D10 D9 D8 D7 D6 D5 D4 D3 D2 D1 D0    D: Bits Significativos após RShift
    */
}

/**
 * @brief  Realiza a codificação a 32 bits do parâmetro code,
 *         reproduzindo o valor originalmente passado à função encode para criar a forma codificada.
 * @param  code Valor de 16 bits sem sinal que será descodificado.
 * @return Devolve o valor a 32 bits com sinal.
 * @note   Escreva um programa (ficheiro prog12.c) de teste para as funções anteriores, que receba valores
 *         inteiros do standard input e, para cada valor, apresente no standard output a representação a 16 bits
 *         codificada com o formato especificado, exibida em hexadecimal, e o valor a 32 bits reproduzido a partir
 *         dela. O executável deve ter o nome prog12.
 *         Ensaie com diversos casos, incluindo valores codificáveis e não codificáveis; verifique os resultados da
 *         descodificação.
 */
int decode(unsigned short code)
{

    // Extrair a parte significativa e o deslocamento

    unsigned int shift = code >> VAL_BITS; // Deslocamento nos 5 bits mais significativos para achar a quantidade de vezes que code foi originalmente Rshiftado
                                           // tecnicamente é o oposto do que se fez no encode (shift << VAL_BITS)

    int sigMask = ~(~0 << VAL_BITS); // VAL_BITS = 11: isto cria a mascara .... 0000 0111 1111 1111
    int sigPart = code & sigMask;    // mascara aplicada para obter a parte significativa

    int bitSignal = sigPart & (1 << (VAL_BITS - 1));

    if (bitSignal) // Se a parte significativa for negativa, extende-se o sinal para tamanho de int (4 bytes / 32 bits)
    {
        sigPart |= ~sigMask; //~sigMask= ... 1111 1000 0000 0000 com OR com a parte significativa, de maneira a extender o sinal
    }

    return sigPart << shift; // Só falta shiftar de volta (Left Shift) e retornar o valor
}      