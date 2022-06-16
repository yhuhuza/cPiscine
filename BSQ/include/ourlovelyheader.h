#ifndef OURLOVELYHEADER_H
# define OURLOVELYHEADER_H

# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <stdlib.h>
# include <fcntl.h>

int		g_chars_count;
int		g_lines_count;
char	g_obstacle_c;
char	g_empty_c;
char	g_full_c;

void	ft_putstr(char *str);
void	get_map_from_input(void);
void	fill_matrix(int **matrix, char *buf, int *y, int *x);
void	read_map(int **matrix, int firstlinelength, char *mapname);
void	get_line_count(char *buf, int linelength);
void	map_get_info(char *mapname, int firstlinelength);
int		ft_change_matrix(int **matrix, int ylen, int xlen);
int		**create_matrix(int ylen, int xlen);
int		ft_change_element(int **matrix, int y, int x);
int		check_map(char c, int *yaxis, int *xaxis);
int		map_validation(char *mapname, int firstlinelength);
int		get_firstlinelength(char *mapname);

#endif
