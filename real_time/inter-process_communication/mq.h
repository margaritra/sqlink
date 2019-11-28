#ifndef MESSAGEMODULE
#define MESSAGEMODULE

#define MQ_SEND_MESSAGE 150
#define MQ_GET_MESSAGE 151

struct message_t{
	char* buff;
	int size;
};
 
#endif
