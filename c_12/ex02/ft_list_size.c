#include <stdlib.h>
#include "ft_list.h"

int	ft_list_size(t_list *begin_list)
{
	t_list	*temp;
	int		i;

	i = 0;
	temp = begin_list;
	while (temp != NULL)
	{
		temp = temp->next;
		i++;
	}
	return (i);
}
