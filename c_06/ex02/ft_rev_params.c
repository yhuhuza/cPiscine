/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmeter <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 17:02:24 by vmeter            #+#    #+#             */
/*   Updated: 2021/07/15 17:05:15 by vmeter           ###   ########.fr       */
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

	i = argc - 1;
	while (i > 0)
	{
		ft_putstr(argv[i]);
		i--;
	}
}
