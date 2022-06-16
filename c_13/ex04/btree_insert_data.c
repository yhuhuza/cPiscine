/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_insert_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmeter <vmeter@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 22:58:12 by vmeter            #+#    #+#             */
/*   Updated: 2021/07/23 23:31:15 by vmeter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void	btree_insert_data(t_btree **root, void *item, int (*cmpf)
	(void *, void *))
{
	t_btree	*dest;

	if (root)
	{
		dest = *root;
		if (cmpf(item, dest->item) < 0)
		{
			if (dest->left)
				btree_insert_data(&dest->left, item, cmpf);
			else
				dest->left = btree_create_node(item);
		}
		else
		{
			if (dest->right)
				btree_insert_data(&dest->right, item, cmpf);
			else
				dest->right = btree_create_node(item);
		}
	}
	else
	{
		*root = btree_create_node(item);
	}
}
