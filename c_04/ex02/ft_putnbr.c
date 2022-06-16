/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmeter <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 10:44:10 by vmeter            #+#    #+#             */
/*   Updated: 2021/07/13 19:53:09 by vmeter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char f)
{
	write(1, &f, 1);
}

void	ft_putnbr(int nb)
{	
	if (0 <= nb && nb <= 9)
		ft_putchar(nb + '0');
	else if (nb == -2147483648)
	{
		ft_putchar('-');
		ft_putchar('2');
		ft_putnbr(147483648);
	}
	else if (nb > 9)
	{
		ft_putnbr (nb / 10);
		ft_putchar ((nb % 10) + '0');
	}
	else
	{
		ft_putchar('-');
		ft_putnbr(nb * -1);
	}
}
