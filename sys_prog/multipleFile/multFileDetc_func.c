#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include "multFileDetc.h"

#include <openssl/md5.h>

unsigned char result[MD5_DIGEST_LENGTH];

// Get the size of the file by its file descriptor
static unsigned long get_size_by_fd(int fd) {
    struct stat statbuf;
    if(fstat(fd, &statbuf) < 0) exit(-1);
    return statbuf.st_size;
}

unsigned char * getMd5FromFile(char* dirPath)
{
	FILE * pFile;
	int file_descript;
	unsigned long file_size;
	char* file_buffer;

	pFile = fopen(dirPath, "r");
  	if (pFile == NULL)
    		perror("fopen() error file");

	file_descript = fileno(pFile);
	if(file_descript < 0) exit(-1);

	file_size = get_size_by_fd(file_descript);

	file_buffer = mmap(0, file_size, PROT_READ, MAP_SHARED, file_descript, 0);
	MD5((unsigned char*) file_buffer, file_size, result);
	munmap(file_buffer, file_size); 
	fclose(pFile);

	return result;
}
