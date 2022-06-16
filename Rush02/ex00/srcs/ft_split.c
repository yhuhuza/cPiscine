#include <stdlib.h>

int	is_split_char(char c, char *charset)
{
	int	i;

	i = -1;
	while (charset[++i] != '\0')
		if (c == charset[i])
			return (1);
	return (0);
}

int	substrs_num(char *str, char *charset)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (str[++i] != '\0')
	{
		if (is_split_char(str[i], charset)
			&& !is_split_char(str[i - 1], charset))
			count++;
	}
	if (!is_split_char(str[i - 1], charset))
		count++;
	return (count);
}

char	*create_substr(char *str, int start, int end)
{
	char	*substr;
	int		size;
	int		i;

	size = end - start;
	substr = malloc(sizeof(*substr) * (size + 1));
	if (!substr)
		return (0);
	i = 0;
	while (start < end)
	{
		substr[i] = str[start];
		i++;
		start++;
	}
	substr[size] = '\0';
	return (substr);
}

void	copy_splitted_strs(char **arr, char *str, char *charset)
{
	int	i;
	int	start_i;
	int	arr_i;

	start_i = -1;
	i = -1;
	arr_i = 0;
	while (str[++i] != '\0')
	{
		if (start_i == -1 && !is_split_char(str[i], charset))
			start_i = i;
		if (start_i != -1 && is_split_char(str[i], charset))
		{
			arr[arr_i] = create_substr(str, start_i, i);
			arr_i++;
			start_i = -1;
		}
	}
	if (start_i != -1 && str[i] == '\0')
		arr[arr_i] = create_substr(str, start_i, i);
}

char	**ft_split(char *str, char *charset)
{
	char	**arr;
	int		size;

	size = substrs_num(str, charset);
	arr = malloc(sizeof(*arr) * (size + 1));
	if (!arr)
		return (0);
	arr[size] = 0;
	copy_splitted_strs(arr, str, charset);
	return (arr);
}
