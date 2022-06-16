/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmeter <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 14:56:37 by vmeter            #+#    #+#             */
/*   Updated: 2021/07/19 19:01:04 by vmeter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	ft_display_file(char *sil)
{
	int		fd;
	char	q;

	fd = open(sil, O_RDONLY);
	if (fd == -1)
		ft_putstr("Cannot read file.\n");
	while (read(fd, &q, 1) > 0)
		ft_putchar(q);
	if (close(fd) == -1)
		return (-1);
	return (0);
}

int	main (int argc, char **argv)
{
	if (argc == 2)
		ft_display_file(argv[1]);
	else if (argc > 2)
		ft_putstr("Too many arguments.\n");
	else if (argc < 2)
		ft_putstr("File name missing.\n");
}
