#include "ourlovelyheader.h"

int	ft_change_element(int **matrix, int y, int x)
{
	int	delta;

	delta = matrix[y][x - 1];
	if (matrix[y][x - 1] > matrix[y - 1][x])
		delta = matrix[y - 1][x];
	else if (matrix[y][x - 1] > matrix[y - 1][x - 1])
		delta = matrix[y - 1][x - 1];
	return (matrix[y][x] + delta);
}

void	ft_imdonewiththisproject(int **matrix, int max, int y, int x)
{
	int	i;
	int	j;

	i = y - max + 1;
	while (i < y + 1)
	{
		j = x - max + 1;
		while (j < x + 1)
		{
			matrix[i][j] = max;
			j++;
		}
		i++;
	}
}

void	ft_change_square(int **matrix, int max, int ylen, int xlen)
{
	int	x;
	int	y;
	int	count;

	count = 0;
	y = 0;
	while (y < ylen)
	{
		x = 0;
		while (x < xlen)
		{
			if (matrix[y][x] == max && count == 0)
			{
				ft_imdonewiththisproject(matrix, max, y, x);
				count++;
			}
			else if (matrix[y][x] == max)
				matrix[y][x] = -1;
			x++;
		}
		y++;
	}
}

void	insideofdachangematrix(int **matrix, int y, int x, int *max)
{
	if (x != 0 && y != 0)
	{
		if (matrix[y][x] != 0)
		{
			matrix[y][x] = ft_change_element(matrix, y, x);
			if (*max < matrix[y][x])
				*max = matrix[y][x];
		}
	}
}

int	ft_change_matrix(int **matrix, int ylen, int xlen)
{
	int	max;
	int	x;
	int	y;

	y = 0;
	max = 1;
	while (y < ylen)
	{
		x = 0;
		while (x < xlen)
		{
			insideofdachangematrix(matrix, y, x, &max);
			x++;
		}
		y++;
	}
	ft_change_square(matrix, max, ylen, xlen);
	return (max);
}
