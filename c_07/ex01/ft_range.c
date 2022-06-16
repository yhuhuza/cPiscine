/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmeter <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 22:40:18 by vmeter            #+#    #+#             */
/*   Updated: 2021/07/16 22:49:01 by vmeter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	r;
	int	*arr;

	r = 0;
	arr = malloc((max - min) * sizeof(int));
	if (arr == NULL || min > max)
		return (NULL);
	while (min < max)
	{
		arr[r] = min;
		min++;
		r++;
	}
	return (arr);
}
 