//#include <WinSock2.h>
//#include <WS2tcpip.h>
//#include <vector>
//#include <stdio.h>
//#include <string.h>
//using namespace std;
//
//#include "Common/errorproc.h"
//
//int main(int argc, char* argv[])
//{
//	if (argc != 2)
//	{
//		fprintf(stderr, "Usage : %s [Port]\n", argv[0]);
//		return -1;
//	}
//	vector<SOCKET> sockets;
//
//	WSADATA wsaData;
//	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
//		neterror_processing(sockets);
//
//	SOCKET server_socket;
//	server_socket = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
//	if (server_socket == SOCKET_ERROR)
//		neterror_processing(sockets);
//	sockets.push_back(server_socket);
//	printf("SYSTEM::socket created..\n");
//
//	SOCKADDR_IN server_addr;
//	int server_size;
//	ZeroMemory(&server_addr, sizeof(server_addr));
//	server_addr.sin_family = AF_INET;
//	server_addr.sin_addr.S_un.S_addr = htonl(INADDR_ANY);
//	server_addr.sin_port = htons(atoi(argv[1]));
//	server_size = sizeof(server_addr);
//	if(bind(server_socket, (SOCKADDR*)&server_addr, server_size) == SOCKET_ERROR)
//		neterror_processing(sockets);
//	printf("SYSTEM::socket has bound..\n");
//
//	char buffer[BUFSIZ];
//	char addr_buffer[BUFSIZ];
//	size_t string_length;
//	int byte_size;
//	while (1)
//	{
//		byte_size = recvfrom(server_socket, buffer, BUFSIZ - 1, 0, (SOCKADDR*)&server_addr, &server_size);
//		if (byte_size == SOCKET_ERROR)
//			neterror_processing(sockets);
//		else if (byte_size == 0)
//			buffer[byte_size] = '\0';
//		// delete new line character
//		else if (byte_size > 0)
//			buffer[byte_size - 1] = '\0';
//	
//		inet_ntop(AF_INET, &server_addr.sin_addr, addr_buffer, sizeof(addr_buffer));
//		printf("SYSTEM::%s(%d) >> %s\n", addr_buffer, ntohs(server_addr.sin_port), buffer);
//		string_length = strlen(buffer);
//		byte_size = sendto(server_socket, buffer, string_length, 0, (SOCKADDR*)&server_addr, server_size);
//		if (byte_size == SOCKET_ERROR)
//			neterror_processing(sockets);
//	}
//
//	for (auto& it : sockets)
//		closesocket(it);
//	return 0;
//}