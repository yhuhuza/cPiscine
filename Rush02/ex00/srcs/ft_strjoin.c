#include <stdlib.h>

int	ft_strlen(char	*s);

void	ft_plussep(char	*s, int	*len, char	*sep)
{
	int	k;

	k = 0;
	while (sep[k])
	{
		s[*len] = sep[k];
		(*len)++;
		k++;
	}
}

int	ft_len(int	size, char	**strs)
{
	int	i;
	int	len;
	int	j;

	j = 0;
	len = 0;
	i = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j])
		{
			len++;
			j++;
		}
		i++;
	}
	return (len);
}

char	*vo_(void)
{
	char	*s;

	s = (char *) malloc (1);
	s[0] = '\0';
	return (s);
}

char	*ft_strjoin(int	size, char	**strs, char	*sep)
{
	int		len;
	int		i;
	int		j;
	char	*s;

	i = -1;
	j = 0;
	len = 0;
	if (size <= 0)
		return (vo_());
	s = (char *) malloc (ft_len(size, strs) + ft_strlen(sep) * (size - 1) + 1);
	while (++i < size)
	{
		j = 0;
		while (strs[i][j])
		{
			s[len] = strs[i][j];
			j++;
			len++;
		}
		if (i != size - 1)
			ft_plussep(s, &len, sep);
	}
	s[len] = '\0';
	return (s);
}
