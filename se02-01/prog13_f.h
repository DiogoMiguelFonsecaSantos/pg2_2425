#ifndef prog13_h
#define prog13_h

int processFile( const char *filename, int (*action)( const char *line, void *context), void *context);

int linePrintRaw( const char *line, void *context);

//funcoes para o filter (serie 1):
char *splitField(char *str);
void separatorUnity(char str[]);
int strcmp_ic( const char *str1, const char *str2 );
int lineFilterPrint( const char *line, void *context );

#endif
