#ifndef FT_MAP_H
# define FT_MAP_H

typedef struct s_map
{
	char	*key;
	char	*value;
}	t_map;

void	map_delete(void);
int		get_longest_number(void);

#endif
