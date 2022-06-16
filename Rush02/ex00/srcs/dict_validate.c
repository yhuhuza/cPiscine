#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include "../includes/ft_map.h"
#include "../includes/ft_lib.h"

extern t_map	**g_map;
extern int		g_map_i;

int		copy_value(int length);
int		check_string(char *str);
int		check_key(char *str, int length);
int		cnt_(char	*dict_name);
char	*clean_value(char *str);
int		check_value(char *str);

int	dict_validate(char *dict_name)
{
	int		file_desc;
	int		buffer_file;
	char	c;
	int		k;

	k = 0;
	g_map = (t_map **)malloc(sizeof (t_map *) * (cnt_(dict_name) + 1));
	file_desc = open(dict_name, O_RDONLY);
	buffer_file = open("buffer_file", O_RDWR | O_TRUNC | O_CREAT, 0644);
	while (read(file_desc, &c, 1) > 0)
	{
		write(buffer_file, &c, 1);
		k++;
		if (c == '\n')
		{
			close(buffer_file);
			if (copy_value(k))
				return (1);
			buffer_file = open("buffer_file", O_RDWR | O_TRUNC, 0644);
			k = 0;
		}
	}
	close(buffer_file);
	close(file_desc);
	return (0);
}

int	cnt_(char	*dict_name)
{
	int		k;
	int		not_space;
	int		file_desc;
	char	c;

	not_space = 0;
	k = 0;
	file_desc = open(dict_name, O_RDONLY);
	if (file_desc < 0)
		return (-1);
	while (read(file_desc, &c, 1))
	{
		if (!(c == ' ' || (c >= 10 && c <= 13)))
			not_space = 1;
		if (c == '\n')
		{
			if (not_space)
				k++;
			not_space = 0;
		}
	}
	close(file_desc);
	return (k);
}

int	copy_value(int length)
{
	int		i;
	int		file_desc;
	char	*string;

	string = malloc(length + 1);
	file_desc = open("buffer_file", O_RDONLY);
	i = 0;
	while (read(file_desc, string + i, 1) > 0)
		i++;
	string[i] = '\0';
	i = check_string(string);
	free(string);
	close(file_desc);
	return (i);
}

int	check_string(char *str)
{
	int	i;
	int	not_space;

	not_space = 0;
	i = -1;
	while (str[++i])
	{
		if (!(str[i] == ' ' || (str[i] >= 10 && str[i] <= 13)))
			not_space = 1;
		if (str[i] == '\n' && !not_space)
			return (0);
	}
	i = -1;
	while (str[++i])
	{	
		if (str[i] == ':' && check_key(str, i))
			return (1);
		if (str[i] == ':')
			break ;
	}
	str = str + i + 1;
	if (check_value(str))
		return (1);
	g_map[g_map_i++]->value = clean_value(str);
	return (0);
}

char	*clean_value(char *str)
{
	int		i;
	char	charset[7];
	char	**split;
	char	*new_value;

	i = 9;
	while (i < 14)
	{
		charset[i - 9] = i;
		i++;
	}
	charset[i - 9] = ' ';
	split = ft_split(str, charset);
	i = 0;
	while (split[i])
		i++;
	new_value = ft_strjoin(i, split, " ");
	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
	return (new_value);
}
