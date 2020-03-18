//#include <malloc.h>
//#include <stdio.h>
//#include <errno.h>
//#include <string.h>
//#include <unistd.h>
//#include <stdlib.h>
//#include <sys/socket.h>
//#include <netinet/in.h>
//#include <arpa/inet.h>
//#include "Common/resource.h"
//
//void error_processing(resource_manager* rm, const char* str)
//{
//	perror(str);
//	release_manager(rm);
//	exit(-1);
//}
//
//typedef struct sockaddr_in sockaddr_in;
//typedef struct sockaddr sockaddr;
//int main(int argc, char** argv)
//{
//	if (argc != 3)
//	{
//		fprintf(stderr, "Usage : %s [IP Address] [Port] \n", argv[0]);
//		return -1;
//	}
//
//	int result;
//	resource_manager rm;
//	init_manager_auto(&rm);
//
//	int client_socket;
//	sockaddr_in client_address;
//
//
//	 
//	// create socket
//	client_socket = socket(PF_INET, SOCK_STREAM, 0);
//	if (client_socket == -1)
//		error_processing(&rm, "socket function failed : ");
//	bind_descriptor(&rm, client_socket);
//
//	memset(&client_address, 0, sizeof(client_address));
//	client_address.sin_family = AF_INET;
//	client_address.sin_addr.s_addr = inet_addr(argv[1]);
//	client_address.sin_port = htons((uint16_t)atoi(argv[2]));
//	result = connect(client_socket, (sockaddr*)&client_address, sizeof(client_address));
//	if (result == -1)
//		error_processing(&rm, "connect failed : ");
//
//	printf("**********************************************\n");
//	printf("connect with server..!\n");
//	printf("server <%s:%d>\n", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));
//	printf("**********************************************\n\n");
//
//	const size_t max_buffer = 512;
//	char* read_buffer;
//	char* write_buffer;
//	ssize_t rw_size;
//	read_buffer = (char*)malloc(sizeof(char) * max_buffer);
//	write_buffer = (char*)malloc(sizeof(char) * max_buffer);
//	bind_memory(&rm, read_buffer);
//	bind_memory(&rm, write_buffer);
//
//	int loop = 1;
//	while (loop)
//	{
//		// write to server 
//		// TODO : overflow available
//		printf("Echo : ");
//		fscanf(stdin, "%s", write_buffer);
//		rw_size = write(client_socket, write_buffer, strlen(write_buffer));
//		if (rw_size == -1)
//			error_processing(&rm, "write function failed : ");
//
//		// read from server
//		rw_size = read(client_socket, read_buffer, sizeof(char) * max_buffer - 1);
//		if (rw_size == -1)
//			error_processing(&rm, "read function failed : ");
//		read_buffer[rw_size] = '\0';
//		printf("Recv : %s\n", read_buffer);
//
//		// escape condition
//		if (strcmp(write_buffer, "exit") == 0)
//		{
//			loop = 0;
//			break;
//		}
//	}
//
//	release_manager(&rm);
//	return 0;
//}