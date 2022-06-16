/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_strs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmeter <vmeter@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 17:11:32 by vmeter            #+#    #+#             */
/*   Updated: 2021/07/22 22:10:44 by vmeter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

t_list	*ft_list_push_strs(int size, char **strs)
{
	int		q;
	t_list	*temp;
	t_list	*list;

	list = ft_create_elem(strs[0]);
	temp = list;
	q = 0;
	if (size == 0)
		return (NULL);
	while (q < size)
	{
		list = ft_create_elem(strs[q]);
		list->next = temp;
		temp = list;
		q++;
	}
	return (temp);
}
