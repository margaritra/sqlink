#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>
#include <stdbool.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <errno.h>


typedef struct node 
{
   char *data;
   struct node *next;
}node;

struct node *root;


node* insertfirst(node* first,char *data)
{
	first = malloc(sizeof(node));
	if(first!=NULL)
	{
		first->data = data;
		first->next = NULL;
		root = first;
	}
	return first;
}

node* addnode(node* firstNode, char *data)
{
	if(firstNode!=NULL)
	{
		if(root == NULL)
		{
			root = firstNode;//only once
		}
		else
		{
			node * p;
			p = root;
			node * last = malloc(sizeof(node));
			if(last!=NULL)
			{
				last->data = data;
				last->next = NULL;
			}
			while(p->next!=NULL)
			{
				p = p->next;
			}
			p->next = last;
			return last;
		}
	}

}

void printList(node* link)
{
	printf("[");
	while(link != NULL)
	{
		printf("(%s),",link->data);
		link = link->next;
	}
	printf("]\n");
}

int isDir(const char *file_path)
{
	struct stat s;
	stat(file_path, &s);
	return S_ISDIR(s.st_mode);
}

node* walkDir(char *basedir,node* first)
{
	DIR *dir;
	struct dirent *ent;
	
	dir = opendir(basedir);
	
	if(dir != NULL)
	{
		//printf("\n\tWalking \"%s\"\n", basedir);
		
		while((ent = readdir(dir)) != NULL)
		{
			// do not allow "." or ".."
			if(strcmp(ent->d_name, ".") == 0 || strcmp(ent->d_name, "..") == 0)
			{
				continue;
			}
			
			char *entpath = malloc(1000*(sizeof(char)));
			strcat(entpath, basedir);
			strcat(entpath, "/");
			strcat(entpath, ent->d_name);
			
			if(isDir(entpath)) // directory
			{
				//printf("\n\tDIR: %s\n", ent->d_name);
				
				// directory, walk it
				walkDir(entpath,first);
			}
			else // file
			{
				//printf("\n\tFILE: %s\n", ent->d_name);
				if(first==NULL)
				{
					first = insertfirst(first,entpath);
				}
				else 
				{
					addnode(first,entpath);
				}
			}
		}
		//printList(root);
		return root;
		closedir(dir);
	}
	else
	{
		fprintf(stderr, "\nFailed to walk directory \"%s\"\n", basedir);
/*
		if(DEBUG)
		{
			perror("opendir()");
		}
*/
	}
}


char* permissions(char *file){
    struct stat st;
    char *modeval = malloc(sizeof(char) * 9 + 1);
    if(stat(file, &st) == 0){
        mode_t perm = st.st_mode;
        modeval[0] = (perm & S_IRUSR) ? 'r' : '-';
        modeval[1] = (perm & S_IWUSR) ? 'w' : '-';
        modeval[2] = (perm & S_IXUSR) ? 'x' : '-';
        modeval[3] = (perm & S_IRGRP) ? 'r' : '-';
        modeval[4] = (perm & S_IWGRP) ? 'w' : '-';
        modeval[5] = (perm & S_IXGRP) ? 'x' : '-';
        modeval[6] = (perm & S_IROTH) ? 'r' : '-';
        modeval[7] = (perm & S_IWOTH) ? 'w' : '-';
        modeval[8] = (perm & S_IXOTH) ? 'x' : '-';
        modeval[9] = '\0';
	printf("prmission:%s \n",modeval);
        return modeval;     
    }
    else{
        return strerror(errno);
    }   
}

void test(int argc, char *argv[])
{
	int file_descript;

	if(argc != 2) 
	{ 
        	printf("Must specify the directory\n");
        	exit(-1);
    	}

    	//printf("using directory:\t%s\n", argv[1]);

	file_descript = open(argv[1], O_RDONLY);

    	if(file_descript < 0) 
	{
		exit(-1);
	}
	//module for ops
	node * listofFiles = NULL;
	char *basedir = argv[1];
	listofFiles = walkDir(basedir,listofFiles); //return the node *listofFiles
	while(listofFiles != NULL)
	{
		permissions(listofFiles->data);
		listofFiles = listofFiles->next;
	}
	
}



int main(int argc, char *argv[])
{
    test(argc,argv);
    return 0;
}



