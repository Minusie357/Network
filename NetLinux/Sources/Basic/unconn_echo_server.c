//#include <stdio.h>
//#include <string.h>
//#include <sys/types.h>
//#include <sys/socket.h>
//#include <netinet/in.h>
//#include <arpa/inet.h>	
//
//#include "Common/errorproc.h"
//#include "Common/resource.h"
//
//int main(int argc, char** argv)
//{
//	if (argc != 2)
//	{
//		fprintf(stderr, "Usage : %s [Port]\n", argv[0]);
//		return -1;
//	}
//
//	resource_manager rm;
//	init_manager_auto(&rm);
//
//	int server_socket;
//	server_socket = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
//	if (server_socket == -1)
//		error_processing(&rm, "socket");
//	bind_descriptor(&rm, server_socket);
//	printf("SYSTEM::server starts..\n");
//	
//	struct sockaddr_in server_addr;
//	size_t len_servaddr = sizeof(server_addr);
//	memset(&server_addr, 0, sizeof(server_addr));
//	server_addr.sin_family = AF_INET;
//	server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
//	server_addr.sin_port = htons(atoi(argv[1]));
//	if (bind(server_socket, (struct sockaddr*) & server_addr, len_servaddr) == -1)
//		error_processing(&rm, "bind");
//	printf("SYSTEM::socket has bound..\n");
//	
//	struct sockaddr_in client_addr;
//	size_t  len_clieaddr = sizeof(client_addr);
//
//	char buffer[BUFSIZ];
//	size_t buffer_size;
//	ssize_t tx_size, rx_size;
//	while (1)
//	{
//		rx_size = recvfrom(server_socket, buffer, BUFSIZ - 1, 0, (struct sockaddr*) & client_addr, &len_clieaddr);
//		if (rx_size == -1)
//			error_processing(&rm, "recvfrom");
//		else if (rx_size == 0)
//			buffer[rx_size] = '\0';
//		else if (rx_size > 0)
//			buffer[rx_size - 1] = '\0';
//
//		printf("SYSTEM::%s(%d) > %s\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port), buffer);
//
//		size_t len_string = strlen(buffer);
//		buffer_size = len_string >= BUFSIZ ? BUFSIZ - 1 : len_string - 1;
//		tx_size = sendto(server_socket, buffer, buffer_size, 0, (struct sockaddr*) & client_addr, len_clieaddr);
//		if (tx_size == -1)
//			error_processing(&rm, "sendto");
//	}
//	
//	release_manager(&rm);
//	return 0;
//}