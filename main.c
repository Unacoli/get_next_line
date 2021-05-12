#include "get_next_line.h"

int main()
{
	char *line;
	int fd;
	int gnl;

	fd = open("./txt", O_RDONLY);
	if (fd == -1)
		return (42);
	gnl = get_next_line(fd, &line);
	printf("%d : %s\n", gnl, line);
}	
