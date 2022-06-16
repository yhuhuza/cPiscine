/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmeter <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 10:37:34 by vmeter            #+#    #+#             */
/*   Updated: 2021/07/20 21:45:18 by vmeter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#define BUFFER 1024

void	ft_putst(char *str)
{
	int	q;

	q = 0;
	while (str[q] != '\0')
	{
		write(2, &str[q], 1);
		q++;
	}
	write(1, "\n", 1);
}

void	err(char *arg)
{
	int	i;

	i = 0;
	write(2, "ft_cat: ", 8);
	while (arg[i] != '\0')
	{
		write(2, &arg[i], 1);
		i++;
	}
	write(2, ": ", 2);
}

int	ft_display_file(char *sil)
{
	int		fd;
	char	q;

	fd = open(sil, O_RDWR);
	if (fd == -1)
	{
		err(sil);
		ft_putst(strerror(errno));
	}		
	while (read(fd, &q, 1) > 0)
		ft_putchar(q);
	if (close(fd) == -1)
		return (-1);
	return (0);
}

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

int	main(int argc, char **argv)
{
	int		i;
	char	mak;
	int		q;

	i = 1;
	q = 0;
	while (ft_strcmp(argv[1], "-") == 0)
	{
		read(0, &mak, 1);
		ft_putchar(mak);
		q++;
	}
	if (argc >= 2)
	{
		while (argv[i] != '\0')
		{
			ft_display_file(argv[i]);
			i++;
		}
	}
	while (argc == 1)
	{
		read(0, &mak, 1);
		ft_putchar(mak);
	}		
}
