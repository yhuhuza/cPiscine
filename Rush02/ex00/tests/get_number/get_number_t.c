#include <stdlib.h>
#include <unistd.h>
#include "../../includes/ft_map.h"
#include "../../includes/arg_checks.h"
#include "../../includes/get_number.h"
#include "../../includes/ft_lib.h"
#include <stdio.h>

int	main(int argc, char *argv[])
{
	argc += 0;
	printf("Got: %s\n", get_number(argv[1]));
	return (0);
}
