/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_front.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmeter <vmeter@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 16:41:18 by vmeter            #+#    #+#             */
/*   Updated: 2021/07/22 22:39:21 by vmeter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_push_front(t_list **begin_list, void *data)
{
	t_list	*che;

	if (*begin_list)
	{
		che = ft_create_elem(data);
		che->next = *begin_list;
		*begin_list = che;
	}
	else
		*begin_list = ft_create_elem(data);
}
