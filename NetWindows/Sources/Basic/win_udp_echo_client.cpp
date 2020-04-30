//#include <vector>
//#include <stdio.h>
//#include <string.h>
//#include <WinSock2.h>
//#include <WS2tcpip.h>
//using namespace std;
//
//#include "Common/errorproc.h"
//
//int main(int argc, char* argv[])
//{
//	if (argc != 3)
//	{
//		fprintf(stderr, "Usage : %s [Address] [Port]\n", argv[0]);
//		return -1;
//	}
//	vector<SOCKET> sockets;
//	
//	WSAData wsaData;
//	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
//		neterror_processing(sockets);
//	
//	SOCKET client_socket;
//	client_socket = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
//	if (client_socket == INVALID_SOCKET)
//		neterror_processing(sockets);
//	sockets.push_back(client_socket);
//	printf("SYSTEM::socket created..\n");
//
//	SOCKADDR_IN client_addr;
//	ZeroMemory(&client_addr, sizeof(client_addr));
//	client_addr.sin_family = AF_INET;
//	inet_pton(AF_INET, argv[1], &client_addr.sin_addr);
//	client_addr.sin_port = htons(atoi(argv[2]));
//	int client_size = sizeof(client_addr);
//
//	char buffer[BUFSIZ];
//	char addr_buffer[BUFSIZ];
//	size_t string_length;
//	int byte_size;
//	while(1)
//	{
//		printf("CHAT >>	");
//		fgets(buffer, BUFSIZ - 1, stdin);
//		
//		string_length = strlen(buffer);
//		byte_size = sendto(client_socket, buffer, string_length, 0, (SOCKADDR*)&client_addr, client_size);
//		if (byte_size == -1)
//			neterror_processing(sockets);
//		print
//		byte_size = recvfrom(client_socket, buffer, BUFSIZ - 1, 0, (SOCKADDR*)&client_addr, &client_size);
//		if (byte_size == -1)
//			neterror_processing(sockets);
//		else if (byte_size >= 0)
//			buffer[byte_size] = '\0';
//		
//		printf("MESSAGE::%s\n", buffer);
//		if (strcmp(buffer, "end") == 0)
//			break;
//	}
//
//	for (auto& it : sockets)
//		closesocket(it);
//	return 0;
//}