#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>
#include <stdbool.h>
#include "walk.h"

#define DEBUG 1


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
		printf("\n\tWalking \"%s\"\n", basedir);
		
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
				printf("\n\tDIR: %s\n", ent->d_name);
				
				// directory, walk it
				walkDir(entpath,first);
			}
			else // file
			{
				printf("\n\tFILE: %s\n", ent->d_name);
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
		printList(root);
		return root;
		closedir(dir);
	}
	else
	{
		fprintf(stderr, "\nFailed to walk directory \"%s\"\n", basedir);
		if(DEBUG)
		{
			perror("opendir()");
		}
	}
}
