//#include <stdio.h>
//#include <string.h>
//#include <sys/types.h>
//#include <netinet/in.h>
//#include <arpa/inet.h>
//
//#include "Common/resource.h"
//#include "Common/errorproc.h"
//
//
//int main(int argc, char** argv)
//{
//	if (argc != 4)
//	{
//		fprintf(stderr, "Usage : %s [server_address] [server_port] [client_port]", argv[0]);
//		return -1;
//	}
//
//	resource_manager rm;
//	init_manager_auto(&rm);
//
//	int client_socket;
//	client_socket = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
//	if (client_socket == -1)
//		error_processing(&rm, "socket\n");
//	bind_descriptor(&rm, client_socket);
//	printf("SYSTEM::start udp process by creating socket\n");
//	
//
//	struct sockaddr_in client_addr;
//	memset(&client_addr, 0, sizeof(client_addr));
//	client_addr.sin_family = AF_INET;
//	client_addr.sin_addr.s_addr = htonl(INADDR_ANY);
//	client_addr.sin_port = htons(atoi(argv[3]));
//	int bind_result = bind(client_socket, (struct sockaddr*) & client_addr, sizeof(client_addr));
//	if (bind_result == -1)
//		error_processing(&rm, "bind\n");
//	
//	struct sockaddr_in server_addr;
//	size_t len_svraddr;
//	memset(&server_addr, 0, sizeof(server_addr));
//	server_addr.sin_family = AF_INET;
//	server_addr.sin_addr.s_addr = inet_addr(argv[1]);
//	server_addr.sin_port = htons(atoi(argv[2]));
//	len_svraddr = sizeof(server_addr);
//
//	char buffer[BUFSIZ] = { 0 };
//	size_t tx_size;
//	ssize_t sendto_result;
//	while (1)
//	{
//		fgets(buffer, BUFSIZ - 1, stdin);
//		tx_size = strlen(buffer);
//		sendto_result = sendto(client_socket, buffer, tx_size, 0, (struct sockaddr*) & server_addr, len_svraddr);
//		if (sendto_result == -1)
//			error_processing(&rm, "sendto\n");
//
//		printf("SYSTEM::%zd ytes were sent\n", sendto_result);
//	}
//
//	release_manager(&rm);
//	return 0;
//}