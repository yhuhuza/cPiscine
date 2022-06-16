/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_create_node.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmeter <vmeter@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 21:09:14 by vmeter            #+#    #+#             */
/*   Updated: 2021/07/23 23:12:56 by vmeter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"
#include <stdlib.h>

t_btree 	*btree_create_node(void *item)
{
	t_btree	*dest;

	dest = malloc(sizeof(t_btree));
	if (dest)
	{	
		dest->item = item;
		dest->right = NULL;
		dest->left = NULL;
	}
	return (dest);
}
