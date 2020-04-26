//#include <WinSock2.h>
//#include <WS2tcpip.h>
//#include <vector>
//#include <stdio.h>
//#include <stdlib.h>
//#include "errorproc.h"
//using namespace std;
//
//int main(int argc, char* argv[])
//{
//	if (argc != 3)
//	{
//		printf("Usage : %s [IP Address] [Port]\n", argv[0]);
//		return -1;
//	}
//	vector<SOCKET> sockets;
//
//	WSADATA wsa;
//	if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0)
//		neterror_processing(sockets);
//	printf("SYSTEM::Client starts...\n");
//
//	SOCKET client_socket;
//	client_socket = socket(AF_INET, SOCK_STREAM, 0);
//	if (client_socket == INVALID_SOCKET)
//		neterror_processing(sockets);
//	
//	sockets.push_back(client_socket);
//	SOCKADDR_IN client_addr;
//	ZeroMemory(&client_addr, sizeof(client_addr));
//	client_addr.sin_family = AF_INET;
//	client_addr.sin_port = htons(atoi(argv[2]));
//	inet_pton(AF_INET, argv[1], &client_addr.sin_addr);
//	if(connect(client_socket, reinterpret_cast<SOCKADDR*>(&client_addr), 
//		sizeof(client_addr)) == SOCKET_ERROR)
//		neterror_processing(sockets);
//	printf("SYSTEM::Server has connected!\n");
//	
//	char read_buffer[BUFSIZ + 1] = { 0 };
//	char write_buffer[BUFSIZ + 1] = { 0 };
//	size_t read_len, write_len, input_len;
//	while (true)
//	{
//		fgets(write_buffer, BUFSIZ, stdin);
//		input_len = strlen(write_buffer);
//		if (input_len <= 1)
//			break;
//		// remove new-line character
//		write_buffer[--input_len] = '\0';
//		
//		write_len = send(client_socket, write_buffer, input_len, 0);
//		if (write_len == SOCKET_ERROR)
//			neterror_processing(sockets);
//		
//		read_len = recv(client_socket, read_buffer, BUFSIZ, 0);
//		if (read_len == 0)
//			break;
//		else if (read_len == BUFSIZ)
//			read_len -= 1;
// 		read_buffer[read_len] = '\0';
//
//		printf("SYSTEM::[Recv] %s\n", read_buffer);
//		if (strcmp(write_buffer, "exit") == 0
//			|| strcmp(write_buffer, "end") == 0
//			|| strcmp(write_buffer, "quit") == 0)
//			break;
//	}
//	closesocket(client_socket);
//	printf("SYSTEM::Server has disconnected\n");
//	printf("SYSTEM::Application is shutdowning...\n");
//
//	WSACleanup();
//
//	return 0;
//}
//
//
