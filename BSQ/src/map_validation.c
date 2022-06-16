#include "ourlovelyheader.h"

extern int	g_chars_count;
extern int	g_lines_count;
extern char	g_obstacle_c;
extern char	g_empty_c;
extern char	g_full_c;

void	get_lines_count(char *buf, int linelength)
{
	char	*num;
	int		i;

	num = NULL;
	num = (char *)malloc(sizeof(char) * (linelength - 2));
	i = 0;
	while (i < linelength - 3)
	{
		num[i] = buf[i];
		i++;
	}
	num[i] = 0;
	i = 0;
	if (num[i] == 43 || (num[i] > 47 && num[i] < 58))
	{	
		if (num[i] == 43)
			i++;
		while (num[i] > 47 && num[i] < 58)
		{
			g_lines_count = g_lines_count * 10 + (num[i] - 48);
			i++;
		}
	}
	free(num);
}

void	map_get_info(char *mapname, int firstlinelength)
{
	int		fd;
	char	*buf;

	if (firstlinelength > 3)
	{
		buf = NULL;
		buf = (char *)malloc(sizeof(char) * firstlinelength);
		fd = open(mapname, O_RDONLY);
		if (fd != -1)
		{
			read(fd, buf, firstlinelength);
			g_full_c = buf[firstlinelength - 1];
			g_obstacle_c = buf[firstlinelength - 2];
			g_empty_c = buf[firstlinelength - 3];
			get_lines_count(buf, firstlinelength);
			close(fd);
		}
		free(buf);
	}
}

int	check_map(char c, int *yaxis, int *xaxis)
{
	if (c != g_obstacle_c && c != g_empty_c && c != '\n' && c != 0)
		return (1);
	else
	{
		if (c == '\n')
		{
			if (*yaxis == 0)
			{
				g_chars_count = *xaxis;
			}
			else
				if (*xaxis != g_chars_count)
					return (2);
			*yaxis = *yaxis + 1;
			*xaxis = 0;
		}
		else
			*xaxis = *xaxis + 1;
		if (*yaxis == g_lines_count && *xaxis > 0)
			return (1);
	}
	return (0);
}

int	map_validation(char *mapname, int firstlinelength)
{
	char	buf[1];
	int		fd;
	int		x;
	int		y;
	int		i;

	fd = open(mapname, O_RDONLY);
	if (fd != -1)
	{
		i = read(fd, buf, 1);
		y = -1;
		x = 0;
		while (i)
		{
			if (i > firstlinelength)
				if (check_map(buf[0], &y, &x) != 0)
					return (1);
			i++;
			i *= read(fd, buf, 1);
		}
		close(fd);
		if (y != g_lines_count)
			return (1);
	}
	return (0);
}
