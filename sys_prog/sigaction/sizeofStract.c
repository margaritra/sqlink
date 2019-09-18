#include <stdio.h> 
#include <string.h>
  
int main() 
{ 
  
    struct A { 
  
        // sizeof(int) = 4 
        int x; 
        // Padding of 4 bytes 
  	// sizeof(int) = 4 
       
	// sizeof(int) = 4 
	int y;
    }; 
	struct A a1;
	struct A a2;
	int ret;
  
    printf("Size of struct: %ld\n", sizeof(struct A)); 

	ret = memcmp(&a1,&a2,sizeof(struct A));
	printf("memcmp: %d\n", ret); 
	
  
    return 0; 
} 
