#ifndef DA_H
#define DA_H

struct LRchar
{ 
	unsigned int left: 4;
	unsigned int right: 4;
};

union un{
	char c;
	struct LRchar lr;
	
};



char * withoutBitField(char *str);
void printFromCharToDecimal(char c);
int withBitField(char *str);

#endif
