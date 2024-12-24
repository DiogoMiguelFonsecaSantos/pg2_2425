#include "pergunta1.h"

int processFile(const char *filename, int (*action)(const char *line, void *context), void *context)
{
	char line[MAX_CARACTERES];
	int total = 0;

	FILE *file = fopen(filename, "r");
	if (!file)
	{ // verifique se a abertura do arquivo falhou
		printf("Erro ao abrir o arquivo\n");
		return -1;
	}
	// Lê o arquivo linha por linha
	while (fgets(line, MAX_CARACTERES, file))
	{
		// Chama a função action para processar a linha e acumula o retorno
		total += action(line, context);
	}
	fclose(file);
	return total;
}

int linePrintRaw(const char *line, void *context)
{
	if (line != NULL)
		printf("%s", line);
	return 1;
}

int lineFilterPrint(const char *line, void *context)
{

	if (line == NULL || context == NULL)
		return 0; // erro por falta de dados
	char aux_line[strlen(line) + 1];
	char *aux = (char *)context;
	strcpy(aux_line, line);

	char *primeiroCampo = splitField(aux_line);
	if (primeiroCampo == NULL)
		return 0;
	separatorUnify(aux);
	separatorUnify(primeiroCampo);

	if (!strcmp_ic(aux, aux_line))
	{
		printf("%s", aux);
		return 1; // SUCESSO;
	}
	return 0;
}
