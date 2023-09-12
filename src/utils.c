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

void	ft_print_msg(int status, t_philo *p)
{
	size_t	time;

	time = ft_get_time() - p->t->start_time;
   	pthread_mutex_lock(&(p->t->msg));
	if (status == PICKING_FORK)
		printf("%zu %d has taken a fork\n", time, p->id);
	if (status == EATING)
		printf("%zu %d is eating\n", time, p->id);
	if (status == SLEEPING)
		printf("%zu %d is sleeping\n", time, p->id);
	if (status == THINKING)
		printf("%zu %d is thinking\n", time, p->id);
	if (status == DEAD)
		printf("%zu %d died\n", time, p->id);
   	pthread_mutex_unlock(&(p->t->msg));
}

size_t    ft_get_time()
{
	struct timeval tv;

    gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
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
