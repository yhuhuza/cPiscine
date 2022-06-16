/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmeter <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 10:17:01 by vmeter            #+#    #+#             */
/*   Updated: 2021/07/15 21:14:18 by vmeter           ###   ########.fr       */
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
	if (argc > 0)
		ft_putstr(argv[0]);
}
