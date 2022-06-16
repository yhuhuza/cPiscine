/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmeter <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 17:16:26 by vmeter            #+#    #+#             */
/*   Updated: 2021/07/18 17:56:14 by vmeter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	rush01(int **arr);


char	ft_slo(char *slo)
{
	int q;
	int	*mas;

	q = 0;
	write(1, &slo, 1);
	while (slo[q] != '\0')
	{
		if (slo[q] > 47 && slo[q] < 58)
		{
			mas[i] = slo[q];
			i++;
		}
		q++;
	}
	mas = malloc(i * sizeof(int));
	





}

int main(int argc, argv **argv)
{
	int i;

	i = 0;
	if (argc != 2)
	{	
		write(1, "Error\n", 1);
		return (0);
	}
	while (argv[i] != '\0')
	{	
		ft_slo(argv[i]);
		i++;
	}
}
		


