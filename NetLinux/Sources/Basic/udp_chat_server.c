//#include <stdio.h>
//#include <string.h>
//#include <unistd.h>
//#include <stdlib.h>
//#include <sys/types.h>
//#include <sys/socket.h>	
//#include <netinet/in.h>
//#include <arpa/inet.h>
//
//#include "Common/errorproc.h"
//#include "Common/resource.h"
//#define MAX_CLIENT 10
//
//int check_socket_list(struct sockaddr_in* entry, struct sockaddr_in* list, int count)
//{
//	struct sockaddr_in* current_ptr;
//	int i = 0;
//	for (; i < count; ++i)
//	{
//		current_ptr = list + i;
//		if(memcmp(entry, current_ptr, sizeof(struct sockaddr_in)) == 0)
//			return i;
//	}
//	return i;
//}
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
//	int server_socket = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
//	if (server_socket == -1)
//		error_processing(&rm, "socket");
//	bind_descriptor(&rm, server_socket);
//	printf("SYSTEM::socket created..\n");
//	
//	struct sockaddr_in server_addr;
//	memset(&server_addr, 0, sizeof(server_addr));
//	server_addr.sin_family = AF_INET;
//	server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
//	server_addr.sin_port = htons(atoi(argv[1]));
//	if (bind(server_socket, (struct sockaddr*) & server_addr, sizeof(server_addr)) == -1)
//		error_processing(&rm, "bind");
//	printf("SYSTEM::socket has bound..\n");
//
//	struct sockaddr_in clients_addr[MAX_CLIENT];
//	memset(clients_addr, 0, sizeof(clients_addr[0]) * MAX_CLIENT);
//	size_t num_clients = 0;
//
//	struct sockaddr_in client_addr;
//	socklen_t client_size = sizeof(client_addr);
//	
//	char id_buffer[BUFSIZ];
//	char buffer[BUFSIZ];
//	size_t string_length;
//	ssize_t byte_size;
//	while (1)
//	{
//		byte_size = recvfrom(server_socket, buffer, BUFSIZ - 1, 0, (struct sockaddr*) & client_addr, &client_size);
//		if (byte_size == -1)
//			error_processing(&rm, "recvfrom");
//		buffer[byte_size] = '\0';
//		string_length = strlen(buffer);
//		
//		int client_id = check_socket_list(&client_addr, clients_addr, (int)num_clients);
//		if (client_id == num_clients)
//		{
//			// limit max client
//			if (client_id == MAX_CLIENT)
//				continue;
//
//			memcpy(&clients_addr[client_id], &client_addr, sizeof(client_addr));
//			num_clients++;
//		}
//		printf("SYSTEM::current num clients : %d\n", num_clients);
//		printf("SYSTEM::%s(%d) >> %s", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port), buffer);
//		sprintf(id_buffer, "CHAT::%s(%d) : ", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));
//
//		for (int i = 0; i < num_clients; ++i)
//		{
//			if (i == client_id)	continue;
//
//			byte_size = sendto(server_socket, id_buffer, strlen(id_buffer), 0, (struct sockaddr*) & clients_addr[i], client_size);
//			if (byte_size == -1)
//				error_processing(&rm, "sendto : id_buffer");
//			byte_size = sendto(server_socket, buffer, string_length, 0, (struct sockaddr*) & clients_addr[i], client_size);
//			if (byte_size == -1)
//				error_processing(&rm, "sendto : buffer");
//		}
//	}
//
//	return 0;
//}