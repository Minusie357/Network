//#include <stdio.h>
//#include <stdlib.h>
//#include <unistd.h>
//#include <sys/wait.h>
//#include <sys/types.h>
//
//int main(int argc, char** argv)
//{
//	int count = 0;
//	int status;
//	pid_t pid = fork();
//	if (pid == 0)
//	{
//		printf("A child process is generated\n");
//		count = count + 1;
//		printf("Child Process count = %d\n", count);
//		sleep(4);
//		return 3;
//	}
//	else if (pid < 0)
//	{
//		perror_processing("fork");
//	}
//	else
//	{
//		wait(&status);
//		if (WIFEXITED(status))
//			printf("Chile process returns = %d\n", WEXITSTATUS(status));
//		printf("This is a parent process.\n");
//		printf("Parent Process Count = %d\n", count);
//	}
//	return 0;
//}