/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmeter <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 21:40:37 by vmeter            #+#    #+#             */
/*   Updated: 2021/07/14 14:00:16 by vmeter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	sp;

	sp = 1;
	if (power == 0)
		sp = 1;
	if (power < 0)
		sp = 0;
	while (power > 0)
	{
		sp = sp * nb;
		power--;
	}
	return (sp);
}
