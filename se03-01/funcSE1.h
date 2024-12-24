
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
