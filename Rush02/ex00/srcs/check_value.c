int	check_value(char *str)
{
	int	i;
	int	j;

	i = 0;
	if (str[i] == '\0')
		return (1);
	while ((str[i] == ' ' || (str[i] >= 9 && str[i] <= 13)) && str[i] != '\0')
		i++;
	j = i;
	while (str[i] >= 32 && str[i] < 127 && str[i] != '\0')
		i++;
	if (j == i)
		return (1);
	while ((str[i] == ' ' || (str[i] >= 9 && str[i] <= 13)) && str[i] != '\0')
		i++;
	if (str[i] != '\0')
		return (1);
	return (0);
}
