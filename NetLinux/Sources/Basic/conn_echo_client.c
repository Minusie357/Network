//#include <stdio.h>
//#include <string.h>	
//#include <sys/types.h>
//#include <sys/socket.h>	
//#include <netinet/in.h>	
//#include <arpa/inet.h>
//#include <unistd.h>
//
//#include "Common/errorproc.h"
//#include "Common/resource.h"
//
//int main(int argc, char** argv)
//{
//	if (argc != 4)
//	{
//		fprintf(stderr, "Usage : %s [Address] [Port1] [Port2]\n", argv[0]);
//		return -1;
//	}
//
//	resource_manager rm;
//	init_manager_auto(&rm);
//
//	int client_socket;
//	client_socket = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
//	if (client_socket == -1)
//		error_processing(&rm, "socket");
//	bind_descriptor(&rm, client_socket);
//	printf("SYSTEM::client starts..\n");
//
//	struct sockaddr_in server_addr1;
//	memset(&server_addr1, 0, sizeof(server_addr1));
//	server_addr1.sin_family = AF_INET;
//	server_addr1.sin_addr.s_addr = inet_addr(argv[1]);
//	server_addr1.sin_port = htons(atoi(argv[2]));
//	
//	struct sockaddr_in server_addr2;
//	size_t len_servaddr2 = sizeof(server_addr2);
//	memset(&server_addr2, 0, sizeof(server_addr2));
//	server_addr2.sin_family = AF_INET;
//	server_addr2.sin_addr.s_addr = inet_addr(argv[1]);
//	server_addr2.sin_port = htons(atoi(argv[3]));
//
//	if (connect(client_socket, (struct sockaddr*) & server_addr1, sizeof(server_addr1)) == -1)
//		error_processing(&rm, "connect");
//	printf("SYSTEM::connect udp socket\n");
//
//	char buffer[BUFSIZ];
//	size_t buffer_size;
//	ssize_t tx_size, rx_size;
//	while (1)
//	{
//		//connected UDP
//		fgets(buffer, BUFSIZ - 1, stdin);
//		buffer_size = strlen(buffer);
//
//		tx_size = write(client_socket, buffer, buffer_size);
//		if (tx_size == -1)
//			error_processing(&rm, "write");
//		printf("%d bytes were sent\n", buffer_size);
//
//		rx_size = read(client_socket, buffer, BUFSIZ - 1);
//		if (rx_size == -1)
//			error_processing(&rm, "read");
//		buffer[rx_size] = '\0';
//		printf("Server1 : %s", buffer);
//
//		//unconnected UDP
//		fgets(buffer, BUFSIZ - 1, stdin);
//		buffer_size = strlen(buffer);
//		
//		tx_size = sendto(client_socket, buffer, buffer_size, 0, (struct sockaddr*) & server_addr2, len_servaddr2);
//		if (tx_size == -1)
//			error_processing(&rm, "sendto");
//		printf("%d bytes were sent\n", buffer_size);
//
//		rx_size = recvfrom(client_socket, buffer, BUFSIZ - 1, 0, (struct sockaddr*) & server_addr2, &len_servaddr2);
//		if (rx_size == -1)
//			error_processing(&rm, "recvfrom");
//		printf("Server2 : %s", buffer);
//	}
//	
//	return 0;
//}