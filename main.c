#include "get_next_line.h"
#include "stdio.h"
#include <fcntl.h>

int	main(void)
{
	int		fd;
	char	*nextline;

	fd = open("example.txt", O_RDONLY);
	nextline = get_next_line(fd);
	while (nextline)
	{
		printf("%s", nextline);
		free(nextline);
		nextline = get_next_line(fd);
	}
	close(fd);
	return (0);
}
