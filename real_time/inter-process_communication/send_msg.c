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

    fd = open(argv[1], O_WRONLY);
    
    if (fd == -1)
    {
        printf("error in open file\n");
    }
    else
    {
        struct message_t msg;
        msg.buff = malloc(strlen(argv[2]) * sizeof(char));
        strcpy(msg.buff, argv[2]);
        msg.size = strlen(argv[2]);
        printf("buff: %s, size: %d\n", msg.buff, msg.size);
        ret=ioctl(fd, MQ_SEND_MESSAGE, &msg);
        if(ret==-1)
        {
            perror("ioctl error\n");
        }
        printf("ret= %d\n",ret);
        close (fd);
    }

    return 0;
}
