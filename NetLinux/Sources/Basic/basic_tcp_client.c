//#include <stdio.h>
//#include <unistd.h>
//#include <string.h>
//#include <errno.h>
//#include <netinet/in.h>
//#include <sys/socket.h>
//#include <arpa/inet.h>
//#include <malloc.h>
//
//typedef struct sockaddr sockaddr;
//typedef struct sockaddr_in sockaddr_in;
//int main()
//{
//	int result;
//	const uint16_t port = 2357;
//
//	int client_socket;
//	sockaddr_in client_address;
//
//	char* read_buffer;
//	char* write_buffer;
//
//	// create socket
//	client_socket = socket(PF_INET, SOCK_STREAM, 0);
//	if (client_socket == -1)
//	{
//		fprintf(stderr, "socket function failed : %s\n", strerror(errno));
//		return -1;
//	}
//
//	// initializes client address
//	memset(&client_address, 0, sizeof(client_address));
//	client_address.sin_family = AF_INET;
//	client_address.sin_addr.s_addr = inet_addr("192.168.56.101");
//	client_address.sin_port = htons(port);
//	
//	result = connect(client_socket, (sockaddr*)&client_address, sizeof(client_address));
//	if (result == -1)
//	{
//		fprintf(stderr, "connect function failed : %s\n", strerror(errno));
//		close(client_socket);
//		return result;
//	}
//
//
//
//	// write to server
//	ssize_t rw_size;
//	write_buffer = (char*)malloc(sizeof(char) * BUFSIZ);
//	if (write_buffer == NULL)
//	{
//		fprintf(stderr, "malloc to write_buffer failed : %s\n", strerror(errno));
//		close(client_socket);
//		return -1;
//	}
//	strcpy(write_buffer, "Connection Success\n");
//	rw_size = write(client_socket, write_buffer, strlen(write_buffer));
//	if (rw_size == -1)
//	{
//		fprintf(stderr, "write function failed : %s\n", strerror(errno));
//		free(write_buffer);
//		close(client_socket);
//		return -1;
//	}
//	printf("Send : %s\n", write_buffer);
//	free(write_buffer);
//
//
//	// read from server
//	read_buffer = (char*)malloc(sizeof(char) * BUFSIZ);
//	if (read_buffer == NULL)
//	{
//		fprintf(stderr, "malloc to read_buffer failed : %s\n", strerror(errno));
//		close(client_socket);
//		return -1;
//	}
//	rw_size = read(client_socket, read_buffer, sizeof(char) * BUFSIZ - 1);
//	if (rw_size == -1)
//	{
//		fprintf(stderr, "read function failed : %s\n", strerror(errno));
//		free(read_buffer);
//		close(client_socket);
//		return -1;
//	}
//	read_buffer[rw_size] = '\0';
//	printf("Received : %s\n", read_buffer);
//	
//	free(read_buffer);
//	close(client_socket);
//	return 0;
//}