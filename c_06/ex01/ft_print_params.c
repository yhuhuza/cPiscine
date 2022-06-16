/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmeter <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 12:34:29 by vmeter            #+#    #+#             */
/*   Updated: 2021/07/15 16:57:57 by vmeter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char abv)
{
	write(1, &abv, 1);
}

void	ft_putstr(char *str)
{
	int	q;

	q = 0;
	while (str[q] != '\0')
	{
		ft_putchar(str[q]);
		q++;
	}
	write(1, "\n", 1);
}

int	main (int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		ft_putstr(argv[i]);
		i++;
	}
}
