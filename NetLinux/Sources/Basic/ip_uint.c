//#include <arpa/inet.h>
//#include <stdio.h>
//#include <unistd.h>
//
//int main(int argc, char** argv)
//{
//	uint32_t ipInInt;
//	char* ipInStr = "127.0.0.1";
//	ipInInt = inet_network(ipInStr);
//
//	printf("String : %s, Decimal : %u, Hex : %x\n",
//		ipInStr, ipInInt, ipInInt);
//
//	ipInInt = htonl(ipInInt);
//	printf("\nAfter htonl\n");
//	printf("Decimal : %u, Hex : %x\n", ipInInt, ipInInt);
//
//	return 0;
//}