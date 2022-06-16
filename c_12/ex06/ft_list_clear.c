/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmeter <vmeter@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 23:10:11 by vmeter            #+#    #+#             */
/*   Updated: 2021/07/22 23:34:51 by vmeter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

void	ft_list_clear(t_list *begin, void(*free_fct)(void *))
{
	t_list	*tmp;
	t_list	*src;

	src = begin;
	while (src)
	{
		tmp = src->next;
		if (src->data)
			free_fct(src->data);
		free(src);
		src = tmp;
	}
}
