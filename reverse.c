#include <sys/stat.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "file_utils.h"
/*****************************************************************
Inputs a text file and reverse all characters. The reversed text
is written to a new file.

@Author Quinn Meagher
@version Fall 2018
*****************************************************************/
int main(int argc, char **argv)
{ 
	/** Buffer to store text from file */
	char *buffer;

	/** Obtains and the size of the text file
	 * and reads it into buffer */
	int size = read_file(argv[1], &buffer);

	/** Initializes a pointer to the start of the buffer */
	char *fileStart = buffer;

	/** Initializes a pointer to the end of the buffer */
	char *fileEnd = fileStart + size - 1;

	/*************************************************
	 *While the ending pointer is at a greater position then the starting
	 *pointer the characters will swap and increment towards each other
	 * **********************************************/
	while (fileEnd > fileStart)	{
		char placeholder = *fileStart;
		*fileStart = *fileEnd;
		*fileEnd = placeholder;
		fileStart++;
		fileEnd--;
	}

	// Writes the buffer to a new text file
	write_file(argv[2], buffer, size);

	// Releases the memory set aside for the text buffer
	free(buffer);

	return 0;
}
