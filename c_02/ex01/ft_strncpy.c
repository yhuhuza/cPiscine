/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmeter <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 21:09:22 by vmeter            #+#    #+#             */
/*   Updated: 2021/07/10 22:17:41 by vmeter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <string.h>

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	int	q;

	q = 0;
	while (src[q] != '\0')
	{
		if (q < n)
		{
			dest[q] = src[q];
			q++;
		}
		else
		{	
			dest[q] = '\0';
			return (dest);
		}
	}	
}
