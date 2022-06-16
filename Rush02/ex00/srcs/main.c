#include "../includes/check_args.h"
#include "../includes/dict_validate.h"
#include "../includes/ft_map.h"
#include "../includes/ft_lib.h"
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

void	print_number_start(char	*number);

t_map		**g_map;
extern int	g_map_i;

int	cmp(char	*s1, char *s2)
{
	int	i;

	i = 0;
	while (1)
	{
		if (s1[i] == '\0' && s2[i] == '\0')
			return (0);
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
}

char	*find_number(char	*number)
{
	int	i;

	i = 0;
	while (g_map[i])
	{
		if (cmp(g_map[i]->key, number) == 0)
			return (g_map[i]->value);
		i++;
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	char	*arg;
	char	*name_dict;

	g_map_i = 0;
	name_dict = "../numbers.dict";
	if (argc == 3)
		name_dict = argv[1];
	if (close(open(name_dict, O_RDONLY)) < 0 || dict_validate(name_dict))
	{
		ft_putstr("Dict Error\n");
		return (0);
	}
	arg = check_args(argc, argv);
	if (arg == 0)
		return (0);
	g_map[g_map_i] = 0;
	print_number_start(arg);
	ft_putstr("\n");
	map_delete();
	return (0);
}
