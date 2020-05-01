//#include <stdio.h>
//#include <string.h>
//#include <sys/socket.h>	
//#include <netinet/in.h>
//#include <arpa/inet.h>	
//#include <stdlib.h>
//#include <unistd.h>
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
//
//	resource_manager rm;
//	init_manager_auto(&rm);
//
//	int clientSocket = socket(AF_INET, SOCK_STREAM, 0);
//	if (clientSocket == -1)
//		error_processing(&rm, "socket");
//	bind_descriptor(&rm, clientSocket);
//	printf("SYSTEM::socket is created..\n");
//
//	struct sockaddr_in clientAddr;
//	memset(&clientAddr, 0, sizeof(clientAddr));
//	clientAddr.sin_family = AF_INET;
//	clientAddr.sin_addr.s_addr = inet_addr(argv[1]);
//	clientAddr.sin_port = htons(atoi(argv[2]));
//	if (connect(clientSocket, (struct sockaddr*) & clientAddr, sizeof(clientAddr)) == -1)
//		error_processing(&rm, "connect");
//
//	char buffer[BUFSIZ];
//	size_t string_length;
//	ssize_t byte_size;
//	while (1)
//	{
//		fgets(buffer, BUFSIZ - 1, stdin);
//		string_length = strlen(buffer);
//		if (string_length < 2)
//			continue;
//
//		byte_size = write(clientSocket, buffer, string_length);
//		if (byte_size == -1)
//			error_processing(&rm, "write");
//		
//		byte_size = read(clientSocket, buffer, BUFSIZ);
//		if (byte_size == -1)
//			error_processing(&rm, "read");
//		buffer[byte_size] = '\0';
//		printf("SYSTEM::server >> %s\n", buffer);
//		if (strcmp(buffer, "end") == 0)
//			break;
//	}
//
//	release_manager(&rm);
//	return 0;
//}