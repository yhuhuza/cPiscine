#include "ourlovelyheader.h"

extern int	g_chars_count;
extern int	g_lines_count;
extern char	g_obstacle_c;
extern char	g_empty_c;
extern char	g_full_c;

void	print_matrix(int **matrix, int ylen, int xlen, int max)
{
	int	y;
	int	x;

	y = 0;
	while (y < ylen)
	{
		x = 0;
		while (x < xlen)
		{
			if (matrix[y][x] == max)
				write(1, &g_full_c, 1);
			else if (matrix[y][x] != 0)
				write (1, &g_empty_c, 1);
			else
				write (1, &g_obstacle_c, 1);
			x++;
		}
		ft_putstr("\n");
		y++;
	}
}

void	free_matrix(int **matrix, int ylen)
{
	int	y;

	y = 0;
	while (y < ylen)
	{
		free(matrix[y]);
		y++;
	}
	free(matrix);
}

int	get_firstlinelength(char *mapname)
{
	int		fd;
	int		ret;
	int		bufsize;
	char	buf[1024];

	bufsize = 0;
	fd = open(mapname, O_RDONLY);
	if (fd != -1)
	{
		ret = read(fd, buf, 1023);
		buf[ret] = 0;
		while (buf[bufsize] != '\n' && buf[bufsize])
			bufsize++;
		close(fd);
	}
	if (bufsize > 25)
		return (0);
	else
		return (bufsize);
}

void	matrix_cycle(char *mapname)
{
	int	firstlinelength;
	int	**matrix;
	int	max;

	firstlinelength = get_firstlinelength(mapname);
	map_get_info(mapname, firstlinelength);
	if (map_validation(mapname, firstlinelength) == 1 || g_lines_count < 1)
		ft_putstr("map error\n");
	else
	{
		matrix = create_matrix(g_lines_count, g_chars_count);
		read_map(matrix, firstlinelength, mapname);
		max = ft_change_matrix(matrix, g_lines_count, g_chars_count);
		print_matrix(matrix, g_lines_count, g_chars_count, max);
		free_matrix(matrix, g_lines_count);
	}
}

int	main(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc == 1)
		get_map_from_input();
	else
	{
		while (i < argc)
		{
			g_full_c = 0;
			g_empty_c = 0;
			g_obstacle_c = 0;
			g_chars_count = 0;
			g_lines_count = 0;
			matrix_cycle(argv[i]);
			i++;
		}
	}
	return (0);
}
