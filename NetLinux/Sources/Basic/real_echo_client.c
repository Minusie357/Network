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
//	if (argc != 3)
//	{
//		fprintf(stderr, "Usage : %s [Address] [Port]\n", argv[0]);
//		return -1;
//	}
//	resource_manager rm;
//	init_manager_auto(&rm);
//
//	int client_socket;
//	client_socket = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
//	if (client_socket == -1)
//		error_processing(&rm, "socket");
//	bind_descriptor(&rm, client_socket);
//	printf("SYSTEM::socket has created..\n");
//
//	struct sockaddr_in client_addr;
//	size_t client_size;
//	memset(&client_addr, 0, sizeof(client_addr));
//	client_addr.sin_family = AF_INET;
//	client_addr.sin_addr.s_addr = inet_addr(argv[1]);
//	client_addr.sin_port = htons(atoi(argv[2]));
//	client_size = sizeof(client_addr);
//
//	char buffer[BUFSIZ] = { 0 };
//	size_t string_length;
//	ssize_t byte_size;
//	while (1)
//	{
//		printf("CHAT >> ");
//		fgets(buffer, BUFSIZ - 1, stdin);
//		string_length = strlen(buffer);
//		
//		byte_size = sendto(client_socket, buffer, string_length, 0, (struct sockaddr*) & client_addr, client_size);
//		if (byte_size == -1)
//			error_processing(&rm, "sendto");
//		
//		printf("MESSAGE::%s", buffer);
//
//		byte_size = recvfrom(client_socket, buffer, BUFSIZ - 1, 0, (struct sockaddr*) & client_addr, &client_size);
//		if (byte_size == -1)
//			error_processing(&rm, "recvfrom");
//		else if (byte_size >= 0)
//			buffer[byte_size] = '\0';
//
//		printf("FROMSRV::%s\n", buffer);
//		if (strcmp(buffer, "end") == 0)
//			break;
//	}
//	
//	release_manager(&rm);
//	return 0;
//}
