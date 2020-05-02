//#include <stdio.h>
//#include <signal.h>
//
//int global_count = 10;
//
//void sigint_handler(int sig)
//{
//	if (sig == SIGINT)
//		printf("Received SIGINT... %d Lives Left\n", global_count -= 1);
//	
//	if(global_count > 0)
//		signal(SIGINT, sigint_handler);
//}
//
//int main(int argc, char** argv)
//{
//	int i = 0;
//	signal(SIGINT, sigint_handler);
//	while (1)
//	{
//		printf("%d : sleep and awake \n", ++i);
//		sleep(3);
//	}
//
//	return 1;
//}