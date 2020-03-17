//#include <stdio.h>
//#include <unistd.h>
//#include <netinet/in.h>
//#include <sys/socket.h>
//#include <string.h>
//#include <errno.h>
//#include <malloc.h>
//
//typedef struct sockaddr sockaddr;
//typedef struct sockaddr_in sockaddr_in;
//int main()
//{
//	int result;
//	uint16_t port = 2357;
//	
//	int server_socket, client_socket;
//	sockaddr_in server_address, client_address;
//
//	char* read_buffer;
//	char* write_buffer;
//
//	// create socket
//	server_socket = socket(PF_INET, SOCK_STREAM, 0);
//	if (server_socket == -1)
//	{
//		fprintf(stderr, "socket function failed : %s\n", strerror(errno));
//		return -1;
//	}
//	printf("server::socket...success\n");
//	
//	// initializes server address info
//	memset(&server_address, 0, sizeof(server_address));
//	server_address.sin_family = AF_INET;
//	server_address.sin_addr.s_addr = htonl(INADDR_ANY);
//	server_address.sin_port = htons((uint16_t)port);
//
//	// bind socket
//	result = bind(server_socket, (sockaddr*)&server_address, (socklen_t)sizeof(server_address));
//	if (result == -1)
//	{
//		fprintf(stderr, "bind function failed : %s\n", strerror(errno));
//		close(server_socket);
//		return result;
//	}
//	printf("server::bind...success\n");
//
//	// listen socket
//	int num_listen = 5;
//	result = listen(server_socket, num_listen);
//	if (result == -1)
//	{
//		fprintf(stderr, "listen function failed : %s\n", strerror(errno));
//		close(server_socket);
//		return result;
//	}
//	printf("server::listen...\n");
//
//	// accept to connect client socket
//	socklen_t client_size = sizeof(client_address);
//	client_socket = accept(server_socket, (sockaddr*)&client_address, &client_size);
//	if (client_socket == -1)
//	{
//		fprintf(stderr, "accept function failed : %s\n", strerror(errno));
//		close(server_socket);
//		return -1;
//	}
//	printf("server::client accept..!\n\n");
//
//
//
//	// read from client
//	read_buffer = (char*)malloc(sizeof(char) * BUFSIZ);
//	if (read_buffer == NULL)
//	{
//		fprintf(stderr, "malloc to read_buffer failed : %s\n", strerror(errno));
//		close(server_socket);
//		close(client_socket);
//		return -1;
//	}
//	ssize_t rw_size;
//	rw_size = read(client_socket, read_buffer, sizeof(char) * BUFSIZ - 1);
//	if (rw_size == -1)
//	{
//		fprintf(stderr, "read function failed : %s\n", strerror(errno));
//		free(read_buffer);
//		close(server_socket);
//		close(client_socket);
//		return -1;
//	}
//	read_buffer[rw_size] = '\0';
//	printf("Received : %s\n", read_buffer);
//	free(read_buffer);
//
//
//
//	// write to client
//	write_buffer = (char*)malloc(sizeof(char) * BUFSIZ);
//	if (write_buffer == NULL)
//	{
//		fprintf(stderr, "malloc to write_buffer failed : %s\n", strerror(errno));
//		close(server_socket);
//		close(client_socket);
//		//return -1;
//	}
//	strcpy(write_buffer,"Received Success\n");
//	rw_size = write(client_socket, write_buffer, strlen(write_buffer));
//	if (rw_size == -1)
//	{
//		fprintf(stderr, "write function failed : %s\n", strerror(errno));
//		free(write_buffer);
//		close(server_socket);
//		close(client_socket);
//		return -1;
//	}
//	printf("Send : %s\n", write_buffer);
//	free(write_buffer);
//
//	close(server_socket);
//	close(client_socket);
//
//	return 0;
//}