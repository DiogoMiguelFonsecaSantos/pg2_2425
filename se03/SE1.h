/**
 * @brief Realiza a codificação do parâmetro data e afeta a variável valid.
 * @param data Valor de 32 bits que será codificado.
 * @param valid Ponteiro para um int que indica a validade do código gerado: se a codificação for válida, o int vale 1, else 0.
 * @return Devolve o respetivo código a 16 bits.
 * @note   Esta função foi dada pelo enunciado.
 */
unsigned short encode(int data, int *valid);

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
int decode(unsigned short code);

/**
 * @brief Separa um campo localizado no início da string str, substituindo o respetivo separador (‘;’) pelo terminador de string \0
 * @param str* String formada por uma sequência de campos, separados por ponto-e-vírgula.
 * @return Retorna um ponteiro para o campo seguinte, indicando o endereço do caráter após o separador.
 *         Quando o campo processado é o último, não existindo mais nenhum separador até ao terminador de string,
 *         a função retorna NULL para indicar que não há mais campos.
 */
char *splitField(char *str);

/**
 * @brief Uniformiza a separação entre palavras numa string, colocando um espaço apenas entre palavras,
 *        em substituição de qualquer sequência de separadores, espaço (' '), tabulação ('\t') ou mudança de linha ('\n').
 *        Se houver separadores no início ou no final das string, são eliminados.
 * @param str[] Array de chars formada por uma sequência de campos, separados por ponto-e-vírgula.
 * @return None.
 */
void separatorUnify(char str[]);

/**
 * @brief string compare ignoring case: compara alfabeticamente, insensível a maiúsculas ou minúsculas, as strings indicadas pelos parâmetros.
 * @param str1 String comparada com str2.
 * @param str2 String objeto de comparação.
 * @return Retorna um valor negativo, zero ou positivo se, respetivamente, str1 é alfabeticamente inferior, idêntica ou superior a str2.
 */
int strcmp_ic( const char *str1, const char *str2 );