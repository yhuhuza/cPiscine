#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "ourlovelyheader.h"

void	matrix_cycle(char *mapname);

void	get_map_from_input(void)
{
	int		k;
	int		file;
	char	buff;

	k = 0;
	file = open("buffer_file", O_RDWR | O_CREAT | O_TRUNC, 0644);
	while (read(0, &buff, 1))
	{
		write(file, &buff, 1);
		k++;
	}
	close(file);
	matrix_cycle("buffer_file");
}
