//#include <WinSock2.h>
//#include <WS2tcpip.h>
//#include <vector>
//#include <stdio.h>
//#include <string.h>
//#include <vector>
//#include "errorproc.h"
//using namespace std;
//
//int main(int argc, char* argv[])
//{
//	if (argc != 2)
//	{
//		printf("Usage : %s [port]\n", argv[0]);
//		return -1;
//	}
//	vector<SOCKET> sockets;
//
//	WSADATA wsa;
//	if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0)
//		neterror_processing(sockets);
//	printf("SYSTEM::Server starts...\n");
//
//	SOCKET server_socket;
//	SOCKADDR_IN server_addr;
//	server_socket = socket(AF_INET, SOCK_STREAM, 0);
//	if (server_socket == INVALID_SOCKET)
//		neterror_processing(sockets);
//	printf("SYSTEM::Socket was created...\n");
//
//	sockets.push_back(server_socket);
//	ZeroMemory(&server_addr, sizeof(server_addr));
//	server_addr.sin_family = AF_INET;
//	server_addr.sin_port = htons(atoi(argv[1]));
//	server_addr.sin_addr.S_un.S_addr = htonl(INADDR_ANY);
//	if(bind(server_socket, reinterpret_cast<SOCKADDR*>(&server_addr), sizeof(server_addr)) == SOCKET_ERROR)
//		neterror_processing(sockets);
//	printf("SYSTEM::Socket was bound...\n");
//
//	while (true)
//	{
//		if (listen(server_socket, SOMAXCONN) == SOCKET_ERROR)
//			neterror_processing(sockets);
//		printf("SYSTEM::Socket is listening...\n");
//
//		SOCKET client_socket;
//		SOCKADDR_IN client_addr;
//		int client_addr_len = sizeof(client_addr);
//
//		client_socket = accept(server_socket, reinterpret_cast<SOCKADDR*>(&client_addr), &client_addr_len);
//		if (client_socket == INVALID_SOCKET)
//			neterror_processing(sockets);
//		char addr_buffer[BUFSIZ];
//		inet_ntop(AF_INET, &client_addr.sin_addr, addr_buffer, sizeof(addr_buffer));
//		printf("SYSTEM::Client has connected!\n");
//		printf("NOTICE::Client Address : %s(%d)\n", addr_buffer, ntohs(client_addr.sin_port));
//
//		sockets.push_back(client_socket);
//		size_t read_len;
//		char read_buffer[BUFSIZ + 1] = { 0 };
//		while (true)
//		{
//			read_len = recv(client_socket, read_buffer, BUFSIZ, 0);
//			if (read_len == SOCKET_ERROR)
//			{
//				neterror_processing(sockets);
//				break;
//			}
//			else if (read_len == 0)
//				break;
//			else if (read_len == BUFSIZ)
//				read_len -= 1;
//
//			read_buffer[read_len] = '\0';
//			printf("SYSTEM::[Recv(%d)] : %s\n", ntohs(client_addr.sin_port), read_buffer);
//
//			send(client_socket, read_buffer, strlen(read_buffer), 0);
//		}
//		closesocket(client_socket);
//		printf("SYSTEM::Client has disconnected\n");
//	}
//	closesocket(server_socket);
//	WSACleanup();
//	printf("SYSTEM::Server is shutdowning...\n");
//
//	return 0;
//}