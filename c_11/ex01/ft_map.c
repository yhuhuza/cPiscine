/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmeter <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 20:15:30 by vmeter            #+#    #+#             */
/*   Updated: 2021/07/20 20:27:46 by vmeter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_map(int *tab, int length, int(*f)(int))
{
	int	q;
	int	*mas;

	q = 0;
	mas = (int *)malloc((length) * sizeof(int));
	while (q != length)
	{
		mas[q] = f(tab[q]);
		q++;
	}
	return (mas);
}
