//#include <stdio.h>
//#include <string.h>
//#include <stdlib.h>
//#include <sys/types.h>
//#include <sys/socket.h>
//#include <netinet/in.h>
//#include <arpa/inet.h>
//#include <unistd.h>
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
//	int serverSocket;
//	serverSocket = socket(AF_INET, SOCK_STREAM, 0);
//	if (serverSocket == -1)
//		error_processing(&rm, "socket");
//	bind_descriptor(&rm, serverSocket);
//	printf("SYSTEM::socket created..\n");
//	
//	struct sockaddr_in serverSockaddr;
//	memset(&serverSockaddr, 0, sizeof(serverSockaddr));
//	serverSockaddr.sin_family = AF_INET;
//	serverSockaddr.sin_addr.s_addr = htonl(INADDR_ANY);
//	serverSockaddr.sin_port = htons(atoi(argv[1]));
//	if (bind(serverSocket, (struct sockaddr*) & serverSockaddr, sizeof(serverSockaddr)) == -1)
//		error_processing(&rm, "bind");
//	printf("SYSTEM::socket has bound..\n");
//
//	if (listen(serverSocket, 5) < 0)
//		error_processing(&rm, "listen");
//	printf("SYSTEM::socket is listening..\n");
//
//	struct sockaddr_in clientSockaddr;
//	socklen_t clientSocksize = sizeof(clientSockaddr);
//	while (1)
//	{
//		int clientSocket = accept(serverSocket, (struct sockaddr*) & clientSockaddr, &clientSocksize);
//		if (clientSocket == -1)
//		{
//			perror("accept");
//			continue;
//		}
//		bind_descriptor(&rm, clientSocket);
//		printf("SYSTEM::%s(%d) is connected..\n", inet_ntoa(clientSockaddr.sin_addr), ntohs(clientSockaddr.sin_port));
//
//		char buffer[BUFSIZ];
//		ssize_t byte_size;
//		
//		pid_t pid = fork();
//		if (pid == 0)
//		{
//			release_descriptor(&rm, serverSocket);
//			while (1)
//			{
//				byte_size = read(clientSocket, buffer, BUFSIZ - 1);
//				if (byte_size < 0)
//					error_processing(&rm, "read");
//				else if (byte_size == 0)
//					buffer[byte_size] = '\0';
//				else
//					buffer[byte_size - 1] = '\0';
//				printf("SYSTEM::%s(%d) >> %s\n", inet_ntoa(clientSockaddr.sin_addr), ntohs(clientSockaddr.sin_port), buffer);
//
//				byte_size = write(clientSocket, buffer, strlen(buffer));
//				if (byte_size == -1)
//					error_processing(&rm, "write");
//
//				if (strcmp(buffer, "end") == 0)
//					break;
//			}
//
//			printf("SYSTEM::%s(%d) is disconnected\n", inet_ntoa(clientSockaddr.sin_addr), ntohs(clientSockaddr.sin_port));
//			release_manager(&rm);
//			return 0;
//		}
//		else if (pid < 0)
//			error_processing(&rm, "fork");
//		else
//			release_descriptor(&rm, clientSocket);
//	}
//
//	release_manager(&rm);
//	return 0;
//}