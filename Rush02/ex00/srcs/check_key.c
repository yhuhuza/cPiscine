#include <stdlib.h>
#include "../includes/ft_map.h"
#include "../includes/ft_lib.h"

char	*create_null_char(void);
char	*clean_string(char *str, int length);
int		was_key(char *key_string, int l);
int		cmp(char	*s1, char *s2);

int				g_map_i;
extern t_map	**g_map;

int	check_key(char *str, int length)
{
	char	*key_string;

	key_string = clean_string(str, length);
	if (was_key(key_string, g_map_i))
		return (1);
	g_map[g_map_i] = malloc (sizeof (t_map));
	g_map[g_map_i]->key = key_string;
	return (0);
}

int	was_key(char	*key_string, int	l)
{
	int	i;

	i = 0;
	while (i < l)
	{
		if (cmp(key_string, g_map[i]->key) == 0)
			return (1);
		i++;
	}
	return (0);
}

char	*clean_string(char *str, int length)
{
	int		i;
	int		j;
	char	*res;

	i = 0;
	while ((str[i] == ' ' || (str[i] >= 9 && str[i] <= 13)) && i < length)
		i++;
	if (str[i] == '+')
		i++;
	if (i == length || (str[i] < '0' || str[i] > '9'))
		return (create_null_char());
	str = str + i;
	length -= i;
	i = -1;
	while (++i < length)
		if (str[i] < '0' || str[i] > '9')
			break ;
	res = malloc(i + 1);
	res[i] = '\0';
	j = -1;
	while (++j < i)
		res[j] = str[j];
	return (res);
}

char	*create_null_char(void)
{
	char	*str;

	str = malloc(2);
	str[0] = '0';
	str[1] = '\0';
	return (str);
}
