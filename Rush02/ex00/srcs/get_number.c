#include <stdlib.h>
#include "../includes/ft_lib.h"

char	*get_number(char *str, int	mbfree)
{
	int		i;
	int		j;
	char	*number;

	i = 0;
	while (str[i] == ' ' || str[i] == 9)
		i++;
	if (str[i] == '+')
		i++;
	j = i;
	while (str[j] >= '0' && str[j] <= '9')
		j++;
	number = malloc(sizeof(char) * (j - i + 1));
	j = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		number[j] = str[i];
		i++;
		j++;
	}
	number[j] = '\0';
	if (mbfree)
		free(str);
	return (number);
}
