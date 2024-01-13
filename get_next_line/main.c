
#include "get_next_line.h"

int	main(void)
{
	int		fd;
	char	*line;

	// int fd = open("text.txt" , O_CREAT | O_RDWR);
	// int byte_write = write(fd, "Hi!\nboys!\n", 10);
	// close (fd);
	// printf("bytewrite is : %d\n", byte_write);
	// printf("fd is : %d\n", fd);
	// char *Buffer = ft_calloc(4, 1);
	// int byteread = read(fd, Buffer, 3);
	// printf("byteread is : %d\n", byteread);
	// printf("Buffer is :%s\n", Buffer);
	fd = open("text.txt", O_CREAT | O_RDWR);
	line = NULL;

	line = get_next_line(fd);
	printf("Buffer is :%s", line);
	free(line);

	line = get_next_line(fd);
	printf("Buffer is :%s", line);
	free(line);

	line = get_next_line(fd);
	printf("Buffer is :%s", line);
	free(line);

	line = get_next_line(fd);
	printf("Buffer is :%s", line);
	free(line);

	line = get_next_line(fd);
	printf("Buffer is :%s", line);
	free(line);

	line = get_next_line(fd);
	printf("Buffer is :%s", line);
	free(line);

	close(fd);
	// system("leaks -q a.out");
	return (0);
}
