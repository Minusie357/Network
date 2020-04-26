#include "errorproc.h"
#include <stdio.h>

void error_processing(resource_manager* rm, const char* str)
{
	perror(str);
	release_manager(rm);
	exit(-1);
}