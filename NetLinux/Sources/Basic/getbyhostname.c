//#include <stdio.h>
//#include <arpa/inet.h>
//#include <netdb.h>
//#include <string.h>
//#include <errno.h>
//#include <stdlib.h>
//
//typedef struct hostent hostent;
//typedef struct in_addr in_addr;
//
//// function forward declaraions
//void error_process(const char*);
//
//int main(int argc, char** argv)
//{
//	hostent* host_entry;
//	in_addr** addr_lists;
//
//
//	// error if arg count is not valid
//	if (argc != 2)
//	{
//		fprintf(stderr, "Usage : %s <hostname>", argv[0]);
//		return -1;
//	}
//
//	host_entry = gethostbyname(argv[1]);
//	if (host_entry == NULL)
//		error_process("gethostbyname");
//
//	addr_lists = (in_addr**)host_entry->h_addr_list;
//	printf("hostname : %s\n", host_entry->h_name);
//	for(int i = 0; addr_lists[i] != NULL; ++i)
//		printf("- ip address : %s\n", inet_ntoa(*addr_lists[i]));
//	
//	return 0;
//}
//
//void error_process(const char* str)
//{
//	fprintf(stderr, "%s : %s\n", str, strerror(errno));
//	exit(errno);
//}