/* HTTP server that serves static and dynamic content with the GET method.*/
/* In terminal you need to put the second argument the port number like 8080 
	for example: ./server 8080 
   when you want to see the output you need to enter :
	 http://localhost:8080/
   or if you need TO OPEN THE SPECIFY FILE so you need to enter the name in the end like this:
	 http://localhost:8080/index.html
	
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <fcntl.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <sys/wait.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUFSIZE 1024
#define MAXERRS 16


/*
	There are a few steps involved in using sockets:

	1.Create the socket
	2.Identify the socket
	3.On the server, wait for an incoming connection
	4.Send and receive messages
	5.Close the socket
*/

/* error - wrapper for perror used for bad syscalls  */

void error(char *msg) 
{
	perror(msg);
	exit(1);
}

/*
 	cerror - returns an error message to the client
*/
void cerror(FILE *stream, char *cause, char *errno, char *shortmsg, char *longmsg) 
{
	fprintf(stream, "HTTP/1.1 %s %s\n", errno, shortmsg);
	fprintf(stream, "Content-type: text/html\n");
	fprintf(stream, "\n");
	fprintf(stream, "<html><title>Tiny Error</title>");
	fprintf(stream, "<body bgcolor=""ffffff"">\n");
	fprintf(stream, "%s: %s\n", errno, shortmsg);
	fprintf(stream, "<p>%s: %s\n", longmsg, cause);
	fprintf(stream, "<hr><em>The Tiny Web server</em>\n");
}

int main(int argc, char **argv) 
{

	int parentfd;          /* parent socket */
	int childfd;           /* child socket */
	int portno;            /* port to listen on */
	int clientlen;         /* byte size of client's address */
	struct sockaddr_in serveraddr; /* server's addr */
	struct sockaddr_in clientaddr; /* client addr */

	FILE *stream;          /* stream version of childfd */
	char buf[BUFSIZE];     /* message buffer */
	char method[BUFSIZE];  /* request method */
	char uri[BUFSIZE];     /* request uri */
	char version[BUFSIZE]; /* request method */
	char filename[BUFSIZE];/* path derived from uri */
	char filetype[BUFSIZE];/* path derived from uri */
	char cgiargs[BUFSIZE]; /* cgi argument list */
	char *p;               /* temporary pointer */
	int is_static;         /* static request? */
	struct stat sbuf;      /* file status */
	int fd;                /* static content filedes */

	/* check command line args */
	if (argc != 2) 
	{
		fprintf(stderr, "usage: %s <port>\n", argv[0]);
		exit(1);
	}
	portno = atoi(argv[1]);

	/* socket - give programs access to the network*/
	/* so open socket descriptor */

	parentfd = socket(AF_INET, SOCK_STREAM, 0);
	if (parentfd < 0)
	{
		error("ERROR opening socket");
	}

	serveraddr.sin_family = AF_INET;
	serveraddr.sin_addr.s_addr = htonl(INADDR_ANY);
	serveraddr.sin_port = htons((unsigned short)portno);
	
	/*Indentify (name) a socket*/

	if (bind(parentfd, (struct sockaddr *) &serveraddr, sizeof(serveraddr)) < 0)
	{
		error("ERROR on binding");
	}
	
	/* listen - On the server, wait for an incoming connection*/
	/* get us ready to accept connection requests */
	if (listen(parentfd, 5) < 0) /* allow 5 requests to queue up */ 
	{
		error("ERROR on listen");
	}
	clientlen = sizeof(clientaddr);

	/* 
	* main loop: wait for a connection request, parse HTTP,
	* serve requested content, close connection.
	*/

	while (1) {
	
		printf("\n+++++++ Waiting for new connection ++++++++\n\n");

		/* wait for a connection request */
		childfd = accept(parentfd, (struct sockaddr *) &clientaddr, &clientlen);
		if (childfd < 0) 
		{
			error("ERROR on accept");
		}
		

		/* Send and receive messages */
		/* open the child socket descriptor as a stream */
		if ((stream = fdopen(childfd, "r+")) == NULL)
		{
			error("ERROR on fdopen");
		}		


		/* get the HTTP request line */
		fgets(buf, BUFSIZE, stream);
		printf("%s", buf);
		sscanf(buf, "%s %s %s\n", method, uri, version);

		/* tiny only supports the GET method */
		if (strcasecmp(method, "GET")) 
		{
			cerror(stream, method, "501", "Not Implemented", "Tiny does not implement this method");
			fclose(stream);
			close(childfd);
			continue;
		}

		/* read (and ignore) the HTTP headers */
		fgets(buf, BUFSIZE, stream);
		printf("%s", buf);

		while(strcmp(buf, "\r\n")) 
		{
			fgets(buf, BUFSIZE, stream);
			printf("%s", buf);
		}

		/* parse the uri [crufty] */
		if (!strstr(uri, "cgi-bin")) 
		{ 
			/* static content */
			is_static = 1;
			strcpy(cgiargs, "");
			strcpy(filename, ".");
			strcat(filename, uri);
			if (uri[strlen(uri)-1] == '/')
			{
				strcat(filename, "bydeafault.html");
			} 
			
		}
		else 
		{ /* dynamic content */
			is_static = 0;
			p = index(uri, '?');
			if (p) 
			{
				strcpy(cgiargs, p+1);
				*p = '\0';
			}
			else 
			{
				strcpy(cgiargs, "");
			}
			strcpy(filename, ".");
			strcat(filename, uri);
		}
				

		/* make sure the file exists*/ 
		if (stat(filename, &sbuf) < 0) 
		{
			cerror(stream, filename, "404", "Not found","Tiny couldn't find this file");
			fclose(stream);
			close(childfd);
			continue;
		}

		/* serve static content */
		if (is_static) 
		{
			if (strstr(filename, ".html"))
			strcpy(filetype, "text/html");
			else if (strstr(filename, ".gif"))
			strcpy(filetype, "image/gif");
			else if (strstr(filename, ".jpg"))
			strcpy(filetype, "image/jpg");
			else 
			strcpy(filetype, "text/plain");
		

			/* print response header */
			fprintf(stream, "HTTP/1.1 200 OK\n");
			fprintf(stream, "Server: Tiny Web Server\n");
			fprintf(stream, "Content-length: %d\n", (int)sbuf.st_size);
			fprintf(stream, "Content-type: %s\n", filetype);
			fprintf(stream, "\r\n"); 
			fflush(stream);

			/* Use mmap to return arbitrary-sized response body */
			fd = open(filename, O_RDONLY);
			p = mmap(0, sbuf.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
			fwrite(p, 1, sbuf.st_size, stream);
			munmap(p, sbuf.st_size);
		}

		/* serve dynamic content */
		else 
		{
			/*make sure file is a regular executable file*/ 
			if (!(S_IFREG & sbuf.st_mode) || !(S_IXUSR & sbuf.st_mode)) 
			{
				cerror(stream, filename, "403", "Forbidden", 
				       "You are not allow to access this item");
				fclose(stream);
				close(childfd);
				continue;
			}


			/* print first part of response header */
			sprintf(buf, "HTTP/1.1 200 OK\n");
			write(childfd, buf, strlen(buf));
			sprintf(buf, "Server: Tiny Web Server\n");
			write(childfd, buf, strlen(buf));

			/* create and run the thread or child CGI process so that all child
			 output to stdout and stderr goes back to the client via the
			 childfd socket descriptor */

		}
		

		printf("\n------------------message sent-------------------\n");

		/* clean up */
		fclose(stream);
		/*Close the socket*/
		close(childfd);

	}
}
