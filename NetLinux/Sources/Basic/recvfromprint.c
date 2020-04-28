//#include <stdio.h>
//#include <string.h>
//#include <sys/types.h>
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
//		fprintf(stderr, "Usage : %s [port]", argv[0]);
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
//	printf("SYSTEM::socket has created\n");
//
//	struct sockaddr_in server_addr;
//	memset(&server_addr, 0, sizeof(server_addr));
//	server_addr.sin_family = AF_INET;
//	server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
//	server_addr.sin_port = htons(atoi(argv[1]));
//	int bind_result = bind(server_socket, (struct sockaddr*) & server_addr, sizeof(server_addr));
//	if (bind_result == -1)
//		error_processing(&rm, "bind");
//	printf("SYSTEM::socket has bound\n");
//
//	struct sockaddr_in client_addr;
//	size_t len_cliaddr = sizeof(client_addr);
//
//	char buffer[BUFSIZ];
//	ssize_t rx_size;
//
//	char* addr_string;
//	while (1)
//	{
//		rx_size = recvfrom(server_socket, buffer, BUFSIZ - 1, 0, (struct sockaddr*) & client_addr, &len_cliaddr);
//		if (rx_size == -1)
//			error_processing(&rm, "recvfrom");
//		else if (rx_size == 0)
//			buffer[rx_size] = '\0';
//		else if (rx_size > 0)
//			buffer[rx_size - 1] = '\0';
//
//		addr_string = inet_ntoa(client_addr.sin_addr);
//		printf("SYSTEM::%s:%d >> %s\n", addr_string, ntohs(client_addr.sin_port), buffer);
//	}
//	release_manager(&rm);
//	return 0;
//}