gcc -Wall -Wextra -Werror get_number_t.c ../../srcs/get_number.c ../../srcs/ft_strlen.c

echo "Expected: 123"
./a.out 123
echo 

echo "Expected: 1234567890"
./a.out 1234567890
echo 

echo "Expected: 155"
./a.out +155
echo 

echo "Expected: 155"
./a.out +155
echo

echo "Expected: 201"
./a.out "        +201      "