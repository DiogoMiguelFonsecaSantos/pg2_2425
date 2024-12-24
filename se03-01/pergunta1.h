#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdlib.h>
#include "string.h"

#define MAX_CARACTERES 512

int processFile(const char *filename, int (*action)(const char *line, void *context), void *context);
int linePrintRaw(const char *line, void *context);
int lineFilterPrint(const char *line, void *context);
