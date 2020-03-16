//#include <stdio.h>
//#include <fcntl.h>
//#include <unistd.h>
//
//int main(int argc, char** argv)
//{
//	int fd;
//	ssize_t write_len, read_len;
//	char read_buf[BUFSIZ];
//
//	// check arguments
//	if (argc != 2)
//	{
//		fprintf(stderr, "Usage : %s [Filename] \n", argv[0]);
//		return 0;
//	}
//
//	read_len = read(0, read_buf, BUFSIZ - 1);
//	if (read_len == -1)
//	{
//		fprintf(stderr, "Read error\n");
//		return 0;
//	}
//
//	printf("Total reading data : %d\n", read_len);
//	read_buf[read_len] = '\0';
//
//
//
//	fd = open(argv[1], O_WRONLY | O_CREAT | O_TRUNC);
//	if (fd == -1)
//	{
//		fprintf(stderr, "Cannot open\n");
//		return 0;
//	}
//
//	write_len = write(fd, read_buf, (size_t)read_len);
//	if (write_len == -1)
//	{
//		fprintf(stderr, "Write error\n");
//		return 0;
//	}
//
//	printf("Total writing data : %d\n", write_len);
//	close(fd);
//	return 0;
//
//}