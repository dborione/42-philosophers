/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dborione <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 14:07:37 by dborione          #+#    #+#             */
/*   Updated: 2023/09/18 15:52:57 by dborione         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ft_is_dead(t_philo *p)
{
	atomic_size_t	time;

	time = ft_get_time_mil();
	if (time - p->last_meal_time >= p->t->time_to_die)
    {
        p->t->dead_nbr = 1;
		return (TRUE);
    }
	if (p->meal_nbr >= p->t->time_philo_must_eat)
		return (TRUE);
	return (FALSE);
}

int	ft_print_msg(int status, t_philo *p)
{
	atomic_size_t	time;

	if (p->t->dead_nbr == 1)
		return (0);
	pthread_mutex_lock(&p->t->msg);
	pthread_mutex_lock(&p->t->death);
	time = ft_get_time_mil() - p->t->start_time;
	if (status == DEAD || ft_is_dead(p))
	{
		printf("%zu %zu died\n", time, p->id);
		pthread_mutex_unlock(&p->t->death);
		pthread_mutex_unlock(&p->t->msg);
		return (0);
	}
	pthread_mutex_unlock(&p->t->death);
	if (status == PICKING_FORK)
		printf("%zu %zu has taken a fork\n", time, p->id);
	if (status == EATING)
		printf("%zu %zu is eating\n", time, p->id);
	if (status == SLEEPING)
		printf("%zu %zu is sleeping\n", time, p->id);
	if (status == THINKING)
		printf("%zu %zu is thinking\n", time, p->id);
	pthread_mutex_unlock(&p->t->msg);
	return (1);
}
