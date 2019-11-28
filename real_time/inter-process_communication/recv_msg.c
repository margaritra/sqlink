#include <stdio.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/ioctl.h>
#include<sys/stat.h>


#include "mq.h"
#include<stdlib.h>

int main(int argc, char** argv)
{
   int fd,ret;
   char* msg;
   msg = malloc(sizeof(char)*4096);

    fd = open(argv[1], O_RDONLY);
    
    if (fd == -1)
    {
        printf("error in open file\n");
    }
    else
    {
        ret=ioctl(fd, MQ_GET_MESSAGE, msg);
        if(ret==-1)
        {
            perror("ioctl error\n");
        }
        printf("%s\n",msg);
        close (fd);
    }

    return 0;
}
