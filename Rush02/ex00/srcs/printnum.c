#include "../includes/ft_map.h"
#include "../includes/ft_lib.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

extern t_map	**g_map;

int		ft_strlen(char	*str);
void	ft_putstr(char	*str);
void	print_hun(char	hun);
void	print_one(char	one, char	ten, char	han);
int		print_ten(char	*ten, char	hun);
int		cmp(char	*s1, char *s2);
char	*find_number(char	*number);
int		get_longest_number(void);

void	zero_word(int cnt_zero)
{
	char	*num_zero;
	int		i;
	char	*word;

	i = 1;
	if (cnt_zero == 0)
		return ;
	num_zero = (char *) malloc (cnt_zero + 2);
	num_zero[0] = '1';
	while (i < cnt_zero + 1)
	{
		num_zero[i] = '0';
		i++;
	}
	num_zero[i] = '\0';
	word = find_number(num_zero);
	ft_putstr(" ");
	ft_putstr(word);
	free(num_zero);
}

void	print_3_number(char	*number, int	zero)
{
	int		len;
	char	num[4];

	len = ft_strlen(number);
	num[0] = (len == 3) * number[0] + (len != 3) * '0';
	num[1] = (len != 1) * number[len - 2] + (len == 1) * '0';
	num[2] = number[len - 1];
	num[3] = '\0';
	if (num[0] != '0')
		print_hun(num[0]);
	if (num[1] != '0')
	{
		if (print_ten(num + 1, num[0]))
		{
			zero_word(zero);
			return ;
		}
	}
	if (num[2] != '0')
		print_one(num[2], num[1], num[0]);
	zero_word(zero);
}

void	print_number(char	*number, int	zero)
{
	int		len;
	char	end_num[4];

	if (number[0] == '0' && number[1] == '\0' && zero == 0)
		ft_putstr(find_number("0"));
	len = ft_strlen(number);
	if (len == 0)
		return ;
	if (len <= 3)
	{
		print_3_number(number, zero);
		return ;
	}
	end_num[0] = number[len - 3];
	end_num[1] = number[len - 2];
	end_num[2] = number[len - 1];
	end_num[3] = '\0';
	number[len - 3] = '\0';
	print_number(number, zero + 3);
	if (cmp(end_num, "000") == 0)
		return ;
	ft_putstr(" ");
	print_3_number(end_num, zero);
}

void	print_number_start(char	*number)
{
	while (*number == '0' && number[1] != '\0')
		number++;
	if (ft_strlen(number) > get_longest_number())
	{
		ft_putstr("Dict Error");
		return ;
	}
	print_number(number, 0);
	free(number);
}
