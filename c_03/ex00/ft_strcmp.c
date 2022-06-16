/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmeter <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 11:04:48 by vmeter            #+#    #+#             */
/*   Updated: 2021/07/11 20:25:43 by vmeter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	unsigned int	q;
	unsigned int	n;

	q = 0;
	n = 0;
	while (s1[q] != '\0' && s2[q] != '\0')
	{
		if (s1[q] == s2[q])
			n = 0;
		if (s1[q] > s2[q] || s1[q] < s2[q])
		{
			n = s1[q] - s2[q];
			break ;
		}
		q++;
	}
	return (n);
}