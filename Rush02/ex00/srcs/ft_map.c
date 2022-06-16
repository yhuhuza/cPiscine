#include <stdlib.h>
#include "../includes/ft_map.h"

char	*find_number(char	*number);

extern t_map	**g_map;

void	map_delete(void)
{
	int	i;

	i = 0;
	while (g_map[i])
	{
		if (g_map[i]->key != NULL)
			free(g_map[i]->key);
		if (g_map[i]->value != NULL)
			free(g_map[i]->value);
		free(g_map[i]);
		i++;
	}
	free(g_map);
}

char	*zeroes_word(int cnt_zero)
{
	char	*num_zero;
	int		i;

	i = 1;
	num_zero = (char *) malloc (cnt_zero + 2);
	num_zero[0] = '1';
	while (i < cnt_zero + 1)
	{
		num_zero[i] = '0';
		i++;
	}
	num_zero[i] = '\0';
	return (num_zero);
}

int	get_longest_number(void)
{
	int		zero;
	char	*zerow;

	zero = 3;
	zerow = zeroes_word(zero);
	while (find_number(zerow))
	{
		free(zerow);
		zero += 3;
		zerow = zeroes_word(zero);
	}
	free(zerow);
	return (zero);
}
