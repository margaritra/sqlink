#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <pthread.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include "mq.h"

const int producerNum = 10;
const int consumerNum = 10;

char* queuePath;
char* msg;

void* producer(void *arg) 
{   
    int fd ,ret;
    struct message_t reg;
    fd=open(queuePath,O_WRONLY);
    if(fd==-1) 
    {
        fprintf(stderr, "open error [%s]\n", queuePath);
        /*return NULL; -only stops the currennt thread*/
        exit(1); /* kills not only the currennt thread,but all the brothrs*/
    }
    reg.buff=msg;
    reg.size=strlen(msg);
    ret=ioctl(fd, MQ_SEND_MESSAGE,&reg);
    if(ret==-1) 
    {
        fprintf(stderr, "ioctl error\n");
        return NULL;
    }
    ret=close(fd);
    if(ret==-1) 
    {
        fprintf(stderr, "close error\n");
        return NULL;
    }
    return NULL;
}

void* consumer() 
{ 
	int fd, ret;
    char* buffer= (char*)malloc(sizeof(char)*4096);
    
    fd=open(queuePath,O_RDONLY);
    if(fd==-1) 
    {
        fprintf(stderr, "open error\n");
       return NULL;;
    }
    ret=ioctl(fd, MQ_GET_MESSAGE, buffer);
    if(ret==-1) 
    {
        fprintf(stderr, "ioctl error\n");
        return NULL;;
    }
    printf("The message is %s\n", buffer);
    ret=close(fd);
    if(ret==-1) 
    {
        fprintf(stderr, "close error\n");
        return NULL;
    }

    free(buffer);
    return NULL;
}

int main (int argc, char** argv)
{ 
    pthread_t* produsers = malloc(producerNum*sizeof(int));
    pthread_t* consumers =malloc(consumerNum*sizeof(int));
   
    int i ,j,w,z;

    queuePath=argv[1];
    if(argc ==3)
    {
        msg = argv[2];
    }
    
    for(i=0;i<producerNum;i++)
    {
         pthread_create(&produsers[i],NULL,producer,&i);   
    }

   for(j=0;j<consumerNum;j++)
    {
        pthread_create(&consumers[j],NULL,consumer,&j);
    }
    
    for(w=0;w<producerNum;w++)
    {
        pthread_join(produsers[w],NULL);
    }

    for(z=0;z<consumerNum;z++)
    {
        pthread_join(consumers[z],NULL);
    }

   return 0;
}


