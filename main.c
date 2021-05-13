#include "get_next_line.h"

int main()
{
	char *line;
	int fd;
	int gnl;

	fd = open("./txt", O_RDONLY);
	if (fd == -1)
		return (42);
	int i = 1;
	while ((gnl = get_next_line(fd, &line)) >= 0)
	{
		printf("[main][ligne %d] %d -> %s \n==================\n", i, gnl, line);
		free(line);
		if (gnl == 0)
			break;
		i++;
	}
	if (gnl == 0)
		printf("gg quel bg\n");
	if (gnl == -1)
		printf("ta mere la pute\n");
	close (fd);
	system("leaks a.out");
}	
