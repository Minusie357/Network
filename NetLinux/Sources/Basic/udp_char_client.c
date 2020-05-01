//#include <stdio.h>
//#include <string.h>
//#include <sys/types.h>
//#include <stdlib.h>	
//#include <unistd.h>
//#include <signal.h>
//#include <sys/socket.h>
//#include <netinet/in.h>
//#include <arpa/inet.h>	
//
//#include "Common/resource.h"
//#include "Common/errorproc.h"
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
//	int client_socket = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
//	if (client_socket == -1)
//		error_processing(&rm, "socket");
//	bind_descriptor(&rm, client_socket);
//	printf("SYSTEM::socket created..\n");
//	
//	struct sockaddr_in server_addr;
//	socklen_t server_size = sizeof(server_addr);
//	memset(&server_addr, 0, sizeof(server_addr));
//	server_addr.sin_family = AF_INET;
//	server_addr.sin_addr.s_addr = inet_addr(argv[1]);
//	server_addr.sin_port = htons(atoi(argv[2]));
//	printf("SYSTEM::socket has bound..\n");
//	
//	pid_t pid = fork();
//
//	char buffer[BUFSIZ];
//	size_t string_length;
//	ssize_t byte_size;
//
//	if (pid < 0)
//		error_processing(&rm, "fork");
//	else if (pid == 0)
//	{
//		while (1)
//		{
//			byte_size = recvfrom(client_socket, buffer, BUFSIZ - 1, 0, (struct sockaddr*) & server_addr, &server_size);
//			if (byte_size == -1)
//				error_processing(&rm, "recvfrom");
//			buffer[byte_size] = '\0';
//			printf("%s");
//		}
//	}
//	else
//	{
//		while (1)
//		{
//			fgets(buffer, BUFSIZ - 1, stdin);
//			string_length = strlen(buffer);
//
//			byte_size = sendto(client_socket, buffer, string_length, 0, (struct sockaddr*) & server_addr, server_size);
//			if (byte_size == -1)
//				error_processing(&rm, "sendto");
//			if (strcmp(buffer, "end\r") == 0)
//				break;
//		}
//		kill(pid, SIGTERM);
//	}
//	return 0;
//}