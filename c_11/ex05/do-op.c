/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do-op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmeter <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 21:00:13 by vmeter            #+#    #+#             */
/*   Updated: 2021/07/21 22:14:14 by vmeter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_atoi(char *str);
void	ft_putnbr(int nb);
void	ft_putchar(char c);

void	ft_div(int a, int b)
{
	if (b == 0)
	{
		write(1, "Stop : division by zero", 23);
		ft_putchar('\n');
	}
	else
		ft_putnbr(a / b);
}

void	ft_mod(int a, int b)
{
	if (b == 0)
	{
		write(1, "Stop : modulo by zero", 23);
		ft_putchar('\n');
	}
	else
		ft_putnbr(a % b);
}

int	main(int argc, char **argv)
{
	int	x;
	int	y;

	x = ft_atoi(argv[1]);
	y = ft_atoi(argv[3]);
	if (argc != 4)
		return (0);
	if (*argv[2] == '+')
		ft_putnbr(x + y);
	else if (*argv[2] == '-')
		ft_putnbr(x - y);
	else if (*argv[2] == '*')
		ft_putnbr(x * y);
	else if (*argv[2] == '%')
		ft_mod(x, y);
	else if (*argv[2] == '/')
		ft_div(x, y);
	else if (*argv[2] != '-' && *argv[2] != '+' && *argv[2] != '*'\
			&& *argv[2] != '/' && *argv[2] != '%')
			write(1, "0", 1);
	write(1, "\n", 1);
}
