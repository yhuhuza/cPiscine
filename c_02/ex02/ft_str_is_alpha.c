/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmeter <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 22:19:40 by vmeter            #+#    #+#             */
/*   Updated: 2021/07/10 23:36:41 by vmeter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <string.h>

int	ft_str_is_alpha(char *str)
{
	int	q;
	char	n;	
	
	q = 0;
	while (str[q] != 0)
	{
		if (!(('a' <= str[q] <= 'z') || ('A' <= str[q] <= 'Z')))
		{
			return (0);
		}
		q++;
	}
	return (1);
}

int main()
{
	char u[ ] = "Hello World!";
	
	ft_str_is_alpha(u);
}
