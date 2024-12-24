#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "prog13.h"
#include <ctype.h>



//Funcoes:

char *splitField(char *str) {
	
	char buffer_str[512];
	
	if (str == NULL) {
		return NULL;
	}
	
	int i = 0;
	//printf("Antes %s\n",str);
	while( *str != ';' && *str != '\0') {
		buffer_str[i] = *str;
		str++;
		i++;
	}
	
	buffer_str[i] = '\0';
	
	char *str2 = buffer_str;
	
	//printf("%s\n",buffer_str);
	
    return str2;

}



void separatorUnity(char str[]) {
    int i = 0;
    int j = 0;
    int size_str = strlen(str);

    char buffer[size_str];

	//sem espaco inicial
    while(str[i] == ' ' || str[i] == '\t' || str[i] == '\n') {
                i++;
    }
	
	buffer[j] = str[i];
	
    while(str[i] != '\0') {
		
        if(str[i] == ' ' || str[i] == '\t' || str[i] == '\n') {
            buffer[j++] = ' ';
        
            while(str[i] == ' ' || str[i] == '\t' || str[i] == '\n') {
                i++;
            }
        }else {
            buffer[j++] = str[i++];
        }
    }
    
    if(buffer[j-1] == ' ') {
        j--;
    }
	
		
    buffer[j] = '\0';
   

    strcpy(str, buffer);

}

int strcmp_ic( const char *str1, const char *str2 ) {

	int size_buffer_str1 = strlen(str1) +1;
	char buffer_str1[size_buffer_str1];
	int size_buffer_str2 = strlen(str2) +1;
	char buffer_str2[size_buffer_str2];	
	
	int i = 0;
	while(str1[i] != '\0') {
		buffer_str1[i] = str1[i];
		buffer_str1[i] = tolower((unsigned char) buffer_str1[i] );		
		i++;
	}
	buffer_str1[i] = '\0';
	
	i = 0;
	
	while(str2[i] != '\0') {
		buffer_str2[i] = str2[i];
		buffer_str2[i] = tolower((unsigned char) buffer_str2[i] );		
		i++;
	}
	buffer_str2[i] = '\0';
	
	i = 0;
	
	i = strcmp(buffer_str1, buffer_str2);
	
	if(i == 0){
		return 0;
	}
	else if(i < 0){
		return -1;
	}
	return 1;

}

int lineFilterPrint(const char *line, void *context) {

    char *contextString = (char *)context;
    //printf("%s\n", contextString);
	
	char buffer_line[512];
	strcpy(buffer_line, line);
	
	//printf("Buffer before split: %s\n", buffer_line);
	
    char *primeiro_campo = splitField(buffer_line);
	//printf("first field: %s \n", primeiro_campo);
    
    separatorUnity(primeiro_campo);
    //printf("first field: %s \n", primeiro_campo);

    if (strcmp_ic(primeiro_campo, contextString) == 0) {
        printf("%s\n", line);
        return 1;
    }

    return 0;	
	
}

