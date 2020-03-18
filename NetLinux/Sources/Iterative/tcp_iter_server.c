#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <malloc.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include "Common/resource.h"



void error_processing(resource_manager* rm, const char* str)
{
	perror(str);
	release_manager(rm);
	exit(-1);
}

typedef struct sockaddr_in sockaddr_in;
typedef struct sockaddr sockaddr;
int main(int argc, char** argv)
{
	if (argc != 2)
	{
		fprintf(stderr, "Usage : %s [port] \n", argv[0]);
		return -1;
	}
	int result;
	resource_manager rm;
	init_manager_auto(&rm);
	
	int server_socket, client_socket;
	sockaddr_in server_address, client_address;
	socklen_t client_size = sizeof(client_address);


	// create socket
	server_socket = socket(PF_INET, SOCK_STREAM, 0);
	if (server_socket == -1)
		error_processing(&rm, "socket function failed : ");
	bind_descriptor(&rm, server_socket);
	printf("alarm::socket creation success...\n");

	// bind socket
	memset(&server_address, 0, sizeof(server_address));
	server_address.sin_family = AF_INET;
	server_address.sin_addr.s_addr = htonl(INADDR_ANY);
	server_address.sin_port = htons((uint16_t)atoi(argv[1]));
	result = bind(server_socket,(sockaddr*)&server_address, sizeof(server_address));
	if (result == -1)
		error_processing(&rm, "bind function failed : ");
	printf("alarm::socket binding success...\n");

	// listen socket
	const int max_listen = 5;
	int num_listen = 0;
	result = listen(server_socket, max_listen);
	if (result == -1)
		error_processing(&rm, "listen function failed : ");
	printf("alarm::listening...\n");
	
	// start iterating
	const size_t max_buffer = 512;
	char* read_buffer[max_listen];
	char* write_buffer[max_listen];
	ssize_t rw_size;

	int loop = 1;
	while (loop)
	{
		client_socket = accept(server_socket, (sockaddr*)&client_address, &client_size);
		if (client_socket == -1)
			error_processing(&rm, "accept function failed : ");

		int index = num_listen;
		if (num_listen < max_listen)
		{
			read_buffer[num_listen] = (char*)malloc(sizeof(char) * max_buffer);
			if (read_buffer[num_listen] == NULL)
				error_processing(&rm, "malloc to read buffer failed : ");
			bind_memory(&rm, read_buffer[num_listen]);
			
			write_buffer[num_listen] = (char*)malloc(sizeof(char) * max_buffer);
			if (write_buffer[num_listen] == NULL)
				error_processing(&rm, "malloc to write buffer failed : ");
			bind_memory(&rm, write_buffer[num_listen]);
			num_listen += 1;

			printf("**********************************************\n");
			printf("alarm::connect with client..!\n");
			printf("client <%s:%d>\n", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));
			printf("**********************************************\n\n");
			while (1)
			{
				// read from client
				rw_size = read(client_socket, read_buffer[index], sizeof(char) * max_buffer - 1);
				if (rw_size == -1)
					error_processing(&rm, "read function failed : ");
				read_buffer[index][rw_size] = '\0';
				printf("Recv : %s\n", read_buffer[index]);

				// write to client
				strcpy(write_buffer[index], read_buffer[index]);
				rw_size = write(client_socket, write_buffer[index], strlen(write_buffer[index]));
				if (rw_size == -1)
					error_processing(&rm, "write function failed : ");

				// escape condition
				if (strcmp(read_buffer[index], "exit") == 0)
				{
					loop = 0;
					break;
				}
			}
		}
	}

	release_manager(&rm);
	return 0;
}