/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmeter <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 19:16:18 by vmeter            #+#    #+#             */
/*   Updated: 2021/07/14 20:24:02 by vmeter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	int	i;
	int	y;

	i = 0;
	y = 0;
	while (i <= nb)
	{
		i++;
		if (nb % i == 0)
			y = y + 1;
	}
	if (y == 2)
		return (1);
	else
		return (0);
}

int	ft_find_next_prime(int nb)
{
	while (ft_is_prime(nb) == 0)
		nb = nb + 1;
	return (nb);
}
