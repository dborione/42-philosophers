#include "../includes/philo.h"

static int ft_atoi_convert(const char *str, int i, int sign, unsigned long res)
{
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (res > __LONG_MAX__ && sign == -1)
			return (0);
		else if (res > __LONG_MAX__)
			return (-1);
		res = res * 10 + (str[i++] - '0');
	}
	return (res * sign);
}

int ft_atoi(const char *str)
{
	unsigned long long res;
	int sign;
	int count;
	int i;

	res = 0;
	count = 0;
	sign = 1;
	i = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\r' || str[i] == '\v' || str[i] == '\f' || str[i] == ' ')
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
		count++;
	}
	if (count > 1)
		return (0);
	return (ft_atoi_convert(str, i, sign, res));
}
