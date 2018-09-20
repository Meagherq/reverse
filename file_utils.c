#include "file_utils.h"
#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>
/**************************************************************
 *This takes in a file with name filename and adds it to buffer
 *************************************************************/
int read_file( char* filename, char **buffer )
{
	//Opens the text file
	FILE *input = fopen(filename, "r");

	//checks to see if file is valid and exits if so
	if(input == NULL) {fprintf(stderr,"Invalid file name, exiting now.");}

	//Determines the size of the file.
	struct stat st;
	stat(filename, &st);
	int size = st.st_size;

	//Sets aside an appropriate amount of memory for the buffer
	*buffer = (char*)malloc(size * sizeof(char));

	//Reads the text into the buffer
	fread(*buffer,1,size,input);
	
	//Closes the text file
	fclose(input);
	return size;

}
/** Takes in a filename, a buffer to hold the text, and the buffer's size
 * and writes it to a file under the given filename */
int write_file( char* filename, char*buffer, int size )
{
	int writeSize = size;
	char writeBuffer = *buffer;
	FILE *output = fopen(filename, "w");
	int results = fwrite(buffer,1, size,output);

	//Closes the text file
	fclose(output);
	return 0;
}
