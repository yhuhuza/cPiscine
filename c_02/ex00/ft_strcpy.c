/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmeter <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 15:06:27 by vmeter            #+#    #+#             */
/*   Updated: 2021/07/10 17:20:48 by vmeter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <string.h>

char	*ft_strcpy(char	*dest, char	*src)
{
	int	q;

	q = 0;
	while (src[q] != '\0')
	{
		dest[q] = src[q];
		q++;
	}
	return (dest);
}
