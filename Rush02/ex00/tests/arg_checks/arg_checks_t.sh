gcc -Wall -Wextra -Werror arg_checks_t.c ../../srcs/arg_checks.c ../../srcs/ft_putstr.c

echo "||| 1 - One valid argument |||"
./a.out 123

echo "||| 2 - Two valid argument |||"
./a.out 123 456

echo "||| 3 - One invalid argument - ERROR |||"
./a.out 12.4

echo "||| 4 - One invalid argument - ERROR |||"
./a.out "  12 2   "

echo "||| 5 - Two invalid argument - ERROR |||"
./a.out -123 .45

echo "||| 6 - Too many arguments - ERROR |||"
./a.out 123 456 789