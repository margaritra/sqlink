#include <stdio.h>
//#include "libN.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dlfcn.h>

int main(int argc, char** argv)
{
	void *handle;
	void(*my_lib)(void);
	
	handle = dlopen("./libN.so", RTLD_LAZY);
	*(void**)(&my_lib) = dlsym(handle,"funLib");
        my_lib();
	
	
	return 0;
}
