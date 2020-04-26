#include <WinSock2.h>
#include "errorproc.h"
using namespace std;

void neterror_processing(vector<SOCKET>& sockets)
{
	int error = WSAGetLastError();

	fprintf(stderr, "SYSTEM::Error was occured : %d\n", error);
	for (auto& it : sockets)
		closesocket(it);

	fprintf(stderr, "SYSTEM::Machine is shutdowning...\n");
	exit(-1);
}