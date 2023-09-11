/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dborione <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 10:39:35 by dborione          #+#    #+#             */
/*   Updated: 2023/09/11 10:39:36 by dborione         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	ft_print_msg(int i, int id)
{
	if (i == 0)
		printf("time_stamp %d has taken a fork\n", id);
	if (i == 1)
		printf("time_stamp %d is eating\n", id);
	if (i == 2)
		printf("time_stamp %d is sleeping\n", id);
	if (i == 3)
		printf("time_stamp %d is thinking\n", id);
	if (i == 4)
		printf("time_stamp %d died\n", id);

}

void    ft_get_start_time(t_table *t)
{
	struct timeval tv;

    gettimeofday(&tv, NULL);
	t->start_time = ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

static int	ft_convert(const char *str, int i, int sign, unsigned long res)
{
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (res > 9223372036854775807 && sign == -1)
			return (0);
		else if (res > 9223372036854775807)
			return (-1);
		res = res * 10 + (str[i++] - '0');
	}
	return (res * sign);
}

int	ft_atoi(const char *str)
{
	unsigned long long		res;
	int						sign;
	int						count;
	int						i;

	res = 0;
	count = 0;
	sign = 1;
	i = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\r'
		|| str[i] == '\v' || str[i] == '\f' || str[i] == ' ')
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
	return (ft_convert(str, i, sign, res));
}
