#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "../includes/ft_lib.h"
#include <stdio.h>

#define ARG_ERROR "Error\n"

int		number_validate(char *str);
char	*read_input(void);
char	*get_number(char *str, int	mbfree);

char	*check_args(int argc, char *argv[])
{
	char	*arg;

	if (argc > 3)
	{
		ft_putstr("Too many arguments.\n");
		return (0);
	}
	if (argc == 1)
		arg = read_input();
	else
		arg = argv[argc - 1];
	if (number_validate(arg))
	{
		if (argc == 1)
			free(arg);
		ft_putstr(ARG_ERROR);
		return (0);
	}
	return (get_number(arg, argc == 1));
}

int	number_validate(char *str)
{
	int	i;
	int	numbers_ended;

	i = 0;
	while ((str[i] == ' ' || (str[i] >= 9 && str[i] <= 13)) && str[i] != '\0')
		i++;
	if (str[i] == '+')
		i++;
	numbers_ended = 0;
	while (str[i] != '\0')
	{
		if (str[i] == ' ' || str[i] == 9)
			numbers_ended = 1;
		else if (str[i] >= '0' && str[i] <= '9' && numbers_ended)
			return (1);
		else if (str[i] < '0' || str[i] > '9')
			return (1);
		i++;
	}
	return (0);
}

char	*read_input(void)
{
	int		i;
	int		k;
	int		file_desc;
	char	buffer;
	char	*string;

	file_desc = open("input_buffer", O_RDWR | O_CREAT | O_TRUNC, 0644);
	k = 0;
	while (read(0, &buffer, 1))
	{
		write(file_desc, &buffer, 1);
		if (buffer == '\n')
			break ;
		k++;
	}
	close(file_desc);
	file_desc = open("input_buffer", O_RDWR | O_CREAT, 0644);
	string = (char *)malloc (k + 1);
	i = -1;
	while (++i < k)
		read(file_desc, (string + i), 1);
	string[i] = '\0';
	return (string);
}
