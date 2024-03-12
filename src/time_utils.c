/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dborione <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 14:12:37 by dborione          #+#    #+#             */
/*   Updated: 2023/09/18 14:13:08 by dborione         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

size_t	ft_get_time_mil(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

int	ft_usleep(t_philo *p, size_t time)
{
	atomic_size_t	start_time;

	start_time = ft_get_time_mil();
	while (ft_get_time_mil() < start_time + time)
	{
		if (ft_is_dead(p))
			return (0);
		usleep(100);
	}
	return (1);
}
