#include "../includes/ft_lib.h"
#include <stdio.h>

char	*find_number(char	*number);

int	print_ten(char	*ten, char	hun)
{
	char	t[3];

	if (hun != '0')
		ft_putstr(" ");
	if (ten[0] < '2')
	{
		ft_putstr(find_number(ten));
		return (1);
	}
	t[0] = ten[0];
	t[1] = '0';
	t[2] = '\0';
	ft_putstr(find_number(t));
	return (0);
}

void	print_one(char	one, char	ten, char	han)
{
	char	n[2];

	n[0] = one;
	n[1] = '\0';
	if (ten != '0' || han != '0')
		ft_putstr(" ");
	ft_putstr(find_number(n));
}

void	print_hun(char	hun)
{
	char	h[2];

	h[0] = hun;
	h[1] = '\0';
	ft_putstr(find_number(h));
	ft_putstr(" ");
	ft_putstr(find_number("100"));
}
