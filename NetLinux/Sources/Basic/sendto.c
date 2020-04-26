//#include <stdio.h>
//#include <string.h>
//#include <stdlib.h>
//#include <sys/socket.h>
//#include <netinet/in.h>
//#include <arpa/inet.h>
//#include "Common/errorproc.h"
//
//int main(int argc, char** argv)
//{
//	if (argc != 3)
//	{
//		printf("[Usage] : %s [Address] [Port]\n", argv[0]);
//		return 0;
//	}
//
//	resource_manager rm;
//	init_manager_auto(&rm);
//
//	int peer_socket;
//	peer_socket = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
//	if (peer_socket == -1)
//		error_processing(&rm, "failed to create socket\n");
//	bind_descriptor(&rm, peer_socket);
//
//	struct sockaddr_in peer_addr;
//	size_t peer_addr_len;
//	memset(&peer_addr, 0, sizeof(peer_addr));
//	peer_addr.sin_family = AF_INET;
//	peer_addr.sin_addr.s_addr = inet_addr(argv[1]);
//	peer_addr.sin_port = htons(atoi(argv[2]));
//	peer_addr_len = sizeof(peer_addr);
//	printf("SYSTEM::[INFO] Address : %s, Port : %d\n", argv[1], ntohs(peer_addr.sin_port));
//	
//	char buffer[BUFSIZ] = { 0 };
//	size_t string_length = 0;
//	ssize_t send_len = 0;
//	while (1)
//	{
//		fgets(buffer, BUFSIZ - 1, stdin);
//		string_length = strlen(buffer);
//		
//		send_len = sendto(peer_socket, buffer, string_length, 0,
//			(struct sockaddr*)&peer_addr, peer_addr_len);
//		if (send_len == -1)
//			error_processing(&rm, "sendto = -1");
//
//		printf("%zd bytes were sent\n", send_len);
//	}
//
//	release_manager(&rm);
//	return 0;
//}