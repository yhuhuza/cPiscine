#include "ourlovelyheader.h"

int	g_firstlinelength;

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		write(1, &str[i++], 1);
}

int	**create_matrix(int ylen, int xlen)
{
	int	**matrix;
	int	y;

	y = 0;
	matrix = (int **)malloc(sizeof(int *) * ylen);
	while (y < ylen)
	{
		matrix[y] = (int *)malloc(sizeof(int) * xlen);
		y++;
	}
	return (matrix);
}

void	fill_matrix(int **matrix, char *buf, int *y, int *x)
{
	int	i;

	i = 0;
	while (buf[i])
	{
		if (i < g_firstlinelength && *y < 1)
			i++;
		else
		{
			if (buf[i] != '\n')
			{
				if (buf[i] == g_obstacle_c)
					matrix[*y][*x] = 0;
				else
					matrix[*y][*x] = 1;
				*x = *x + 1;
			}	
			else
			{
				*x = 0;
				*y = *y + 1;
			}
			i++;
		}
	}
}

void	read_map(int **matrix, int firstlinelength, char *mapname)
{
	char	buf[4096];
	int		i;
	int		fd;
	int		x;
	int		y;

	fd = open(mapname, O_RDONLY);
	if (fd != -1)
	{
		g_firstlinelength = 0;
		g_firstlinelength = firstlinelength;
		y = -1;
		x = 0;
		i = 1;
		while (i)
		{
			i = read(fd, buf, 4096);
			buf[i] = 0;
			fill_matrix(matrix, buf, &y, &x);
		}
		close(fd);
	}
}
