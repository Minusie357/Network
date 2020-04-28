//#include <stdio.h>
//#include <string.h>
//#include <stdlib.h>	
//#include <sys/types.h>
//#include <netinet/in.h>	
//#include <arpa/inet.h>
//
//#include "Common/resource.h"
//#include "Common/errorproc.h"
//
//int main(int argc, char** argv)
//{
//	if (argc != 2)
//	{
//		fprintf(stderr, "Usage : %s [Port]\n", argv[0]);
//		return -1;
//	}
//	resource_manager rm;
//	init_manager_auto(&rm);
//
//	int source_socket, cp;
//	source_socket = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
//	if (source_socket == -1)	error_processing(&rm, "socket");
//	bind_descriptor(&rm, source_socket);
//	fprintf(stdout, "socket has created\n");
//	
//	struct sockaddr_in source_socket_addr;
//	memset(&source_socket_addr, 0, sizeof(source_socket_addr));
//	source_socket_addr.sin_family = AF_INET;
//	source_socket_addr.sin_addr.s_addr = htonl(INADDR_ANY);
//	source_socket_addr.sin_port = htons(atoi(argv[1]));
//	if(bind(source_socket, (struct sockaddr*) & source_socket_addr, sizeof(source_socket_addr)) == - 1)
//		error_processing(&rm, "bind");
//	fprintf(stdout, "socket has been bind\n");
//	
//	struct sockaddr_in dest_socket_addr;
//	size_t dest_addr_len = sizeof(dest_socket_addr);
//
//	char buffer[BUFSIZ] = { 0 };
//	ssize_t recv_size;
//	while (1)
//	{
//		recv_size = recvfrom(source_socket, buffer, BUFSIZ - 1, 0,
//			(struct sockaddr*) & dest_socket_addr, &dest_addr_len);
//		if (recv_size == -1)	error_processing(&rm, "recvfrom = -1");
//		printf("%zd bytes have received\n", recv_size);
//	}
//
//	release_manager(&rm);
//	return 0;
//}