//#define _XOPEN_SOURCE 200
//#include <stdio.h>
//#include <signal.h>
//#include <stdlib.h>
//
//int main(int argc, char** argv)
//{
//	struct sigaction new_action, old_action;
//
//	new_action.sa_handler = SIG_IGN;
//	sigemptyset(&new_action.sa_mask);
//	new_action.sa_flags = 0;
//
//	sigaction(SIGINT, &new_action, &old_action);
//
//	int i = 5;
//	while (1)
//	{
//		printf("%d : sleep and awake\n", i--);
//		sleep(1);
//		if (i == 0)
//			break;
//	}
//
//	return 1;
//}