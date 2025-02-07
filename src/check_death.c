/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_death.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dborione <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 16:01:18 by dborione          #+#    #+#             */
/*   Updated: 2023/09/21 15:06:37 by dborione         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ft_is_dead(t_philo *p)
{
	atomic_size_t	time;

	pthread_mutex_lock(&p->t->death);
	time = ft_get_time_mil();
	if (time - p->last_meal_time >= p->t->time_to_die)
	{
		p->t->dead_nbr = 1;
		pthread_mutex_unlock(&p->t->death);
		return (TRUE);
	}
	if (p->t->full_philos_nbr == 0)
	{
		pthread_mutex_unlock(&p->t->death);
		return (TRUE);
	}
	pthread_mutex_unlock(&p->t->death);
	return (FALSE);
}
