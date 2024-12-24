#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "procTextFile.h"
#include "SE1.h"

/**
 *
 * @brief   prog15: Test program to demonstrate the processFile and lineFilterPrint functions.
 *          Exercise 1.5 : Processes a text file line by line, printing each line that matches a given filter.
 */
int main(int argc, char *argv[])
{
    if (argc != 3) { // if the number of arguments is different from 3, return -1
        perror("That's not how you use this program!! Please provide a filename as following:\n\n ./prog15 <filename> <contextField>\n\n");
        return -1;
    }

    const char *filename = argv[1]; // the filename is the second argument, and should be in the same directory as the program
    char filter[512]; // get memory for the filter contextField = argv[2]
    strncpy(filter, argv[2], sizeof(filter) - 1); // copy the contextField terminal input to the filter array
    filter[sizeof(filter) - 1] = '\0'; // add a terminator to the end of the filter array

    printf("Original contextField: '%s'\n", filter); // Debug print

    separatorUnify(filter); // uniformize the separators in the filter

    printf("Uniformized contextField: '%s'\n", filter); // Debug print

    printf("Uniformized contextField '%s' matches:\n\n", filter); // print the filter contextField

    int filtered = processFile(filename, lineFilterPrint, (void *)filter); // process the file with the lineFilterPrint function
    
    if (filtered < 0) { // if the number of lines processed is less than 0, return -1 because it means there was an error processing the file
        fprintf(stderr, "File processing error: %s\n", filename);
        return -1;
    }

    printf("\nTotal number of processed lines: %d\n", filtered);  // print the number of lines processed just for demonstration purposes ig

    return 0;
}