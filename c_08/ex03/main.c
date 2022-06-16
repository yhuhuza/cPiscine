#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include "ft_stock_str.h"

struct s_stock_str *ft_strs_to_tab(int ac, char **av);

int test(int id, char **a, int len)
{
	int					i;
	struct s_stock_str	*tab;

	tab = ft_strs_to_tab(len, a);
	i = 0;
	while (i < len)
	{
		if (tab[i].str != a[i])
		{
			printf("test %d failed! (->str does not contains address of original string)\n", id);
			return (1);
		}
		if (strcmp(tab[i].copy, a[i]))
		{
			printf("test %d failed! (->copy is differs from original string)\n", id);
			return (1);
		}
		if (tab[i].copy == a[i])
		{
			printf("test %d failed! (copy is not a copy)\n", id);
			return (1);
		}
		if (tab[i].size != (int) strlen(a[i]))
		{
			printf("test %d failed! (size does not match)\n", id);
			return (1);
		}
		free(tab[i].copy);
		i++;
	}
	if (tab[i].str != NULL)
	{
		printf("test %d failed! (last ->str must be set to 0)\n", id);
		return (1);
	}
	free(tab);
	return (0);
}

int main()
{
	int i = 0;
	char **a;

	// test 1
	a = (char **)(char *[30]){"hello", "world"};
	i += test(1, a, 2);

	// test 2
	a = (char **)(char *[30]){};
	i += test(2, a, 0);


	// test 3
	a = (char **)(char *[30]){"h", "world\n", ""};
	i += test(3, a, 3);

	// idk
	//a = (char **)(char *[30]){"h", NULL, ""};
	//assert(ft_strs_to_tab(3, a) != NULL);

	if (i == 0)
		puts("ok");
}
