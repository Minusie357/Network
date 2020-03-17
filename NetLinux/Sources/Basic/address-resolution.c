//#include <stdio.h>
//#include <sys/socket.h>	
//#include <netinet/in.h>
//#include <arpa/inet.h>
//
//typedef struct sockaddr_in sockaddr_in;
//typedef struct sockaddr sockaddr;
//
//void print_address(sockaddr_in* address)
//{
//	int port;
//	char ip_str[INET_ADDRSTRLEN];
//	port = ntohs(address->sin_port);
//
//	inet_ntop(AF_INET, &(((sockaddr_in*)address)->sin_addr), ip_str, sizeof(sockaddr_in));
//	printf("IP : %s, Port : %d\n", ip_str, port);
//	printf("IP : %s, Port : %d\n", ip_str, address->sin_port);
//}
//
//int main(int argc, char** argv)
//{
//	char* ip_loopback = "127.0.0.1";
//	int port = 9002;
//	
//	sockaddr_in sockaddr1, sockaddr2, sockaddr3;
//	
//	sockaddr1.sin_family = AF_INET;
//	sockaddr1.sin_addr.s_addr = inet_addr(ip_loopback);
//	sockaddr1.sin_port = htons(port);
//
//	sockaddr2.sin_family = AF_INET;
//	inet_aton(ip_loopback, &(sockaddr2.sin_addr));
//	sockaddr2.sin_port = htons(port);
//
//	sockaddr3.sin_family = AF_INET;
//	inet_pton(AF_INET, ip_loopback, &(sockaddr3.sin_addr));
//	sockaddr3.sin_port = htons(port);
//
//	print_address(&sockaddr1);
//	print_address(&sockaddr2);
//	print_address(&sockaddr3);
//
//	printf("=======================ntoa=====================\n");
//	printf("IP : %s\n", inet_ntoa(sockaddr1.sin_addr));
//	printf("IP : %s\n", inet_ntoa(sockaddr2.sin_addr));
//	printf("IP : %s\n", inet_ntoa(sockaddr3.sin_addr));
//
//	return 0;
//}