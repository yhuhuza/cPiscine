#ifndef FT_LIB_H
# define FT_LIB_H

void	ft_putstr(char *str);
int		ft_strlen(char *str);
char	*find_number(char	*number);
int		cmp(char	*s1, char	*s2);
char	**ft_split(char *str, char *charset);
char	*ft_strjoin(int	size, char	**strs, char	*sep);

#endif
