//#include <sys/socket.h>
//#include <stdio.h>
//#include <fcntl.h>
//#include <unistd.h>
//
//int main()
//{
//	int sd1, sd2;
//	int fd1, fd2;
//
//	sd1 = socket(PF_INET, SOCK_STREAM, 0);
//	fd1 = open("test", O_RDONLY);
//	sd2 = socket(PF_INET, SOCK_STREAM, 0);
//	fd2 = open("test2", O_RDONLY | O_CREAT);
//
//	printf("sd1 : %d, fd1 : %d, sd2 : %d, fd2 : %d\n", sd1, fd1, sd2, fd2);
//	close(sd1);
//	close(fd1);
//	close(sd2);
//	close(fd2);
//
//	return 0;
//}