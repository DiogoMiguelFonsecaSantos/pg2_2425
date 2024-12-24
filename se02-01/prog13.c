#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "procTextFile.h"
#include "SE1.h"

/**
 * @brief   prog13: Test program to demonstrate the processFile and linePrintRaw functions.
 *          Exercise 1.3 : Processes a text file line by line, printing each line to the standard output.
 */
int main(int argc, char *argv[])
{

    if (argc != 2)
    { // if the number of arguments is different from 2, return -1
        perror("That's not how you use this program!! Please provide a filename as following:\n\n ./proc13 <filename>\n\n");
        return -1;
    }

    const char *filename = argv[1]; // the filename is the second argument, and should be in the same directory as the program

    int procResult = processFile(filename, linePrintRaw, NULL); // process the file with the linePrintRaw function

    if (procResult < 0)
    { // if the number of lines processed is less than 0, return -1 because it means there was an error processing the file
        fprintf(stderr, "File processing error: %s\n", filename);
        return -1;
    }

    printf("\nTotal number of processed lines: %d\n", procResult); // print the number of lines processed just for demonstration purposes ig
    return 0;
}
