#include "get_next_line.h"

int main()
{
	char *line;
	int fd;
	int gnl;

	fd = open("./txt", O_RDONLY);
	if (fd == -1)
		return (42);
	while ((gnl = get_next_line(fd, &line)) == 1)
	{
		printf("[main] %d : %s\n==================\n", gnl, line);
		free(line);
	}
	if (gnl == 0)
		printf("gg quel bg\n");
	if (gnl == -1)
		printf("ta mere la pute\n");
	close (fd);
}	
