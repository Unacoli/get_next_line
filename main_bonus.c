#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int main()
{
	char *line;
	int fd1;
	int fd2;
	int fd3;
	int gnl = 0;

	fd1 = open("./txt1", O_RDONLY);
	fd2 = open("./txt2", O_RDONLY);
	fd3 = open("./txt3", O_RDONLY);
	if (fd1 == -1 || fd2 == -1 || fd3 == -1)
		return (42);
	get_next_line(fd1, &line);
	printf("%s\n", line);
	free(line);
	get_next_line(fd3, &line);
	printf("%s\n", line);
	free(line);
	get_next_line(fd2, &line);
	printf("%s\n", line);
	free(line);
	get_next_line(fd3, &line);
	printf("%s\n", line);
	free(line);
	get_next_line(fd3, &line);
	printf("%s\n", line);
	free(line);
	get_next_line(fd1, &line);
	printf("%s\n", line);
	free(line);
	if (gnl == 0)
		printf("gg quel bg\n");
	if (gnl == -1)
		printf("cha marche pas lol\n");
	close(fd1);
	close(fd2);
	close(fd3);
	system("leaks a.out");
}	
