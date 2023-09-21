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

static int	ft_print_death(t_philo *p, atomic_size_t time)
{
	p->t->sim_status = DONE;
	if (p->t->dead_nbr == 1)
		printf("%zu %zu died\n", time, p->id);
	pthread_mutex_unlock(&p->t->msg);
	return (0);
}

int	ft_print_msg(atomic_int status, t_philo *p)
{
	atomic_size_t	time;

	pthread_mutex_lock(&p->t->msg);
	//printf("%d\n", p->t->dead_nbr);
	if (p->t->sim_status == DONE)
	{
		pthread_mutex_unlock(&p->t->msg);
		return (0);
	}
	time = ft_get_time_mil() - p->t->start_time;
	if (status == DEAD || ft_is_dead(p))
		return (ft_print_death(p, time));
	if (status == PICKING_FORK && p->meal_nbr < p->t->time_philo_must_eat)
		printf("%zu %zu has taken a fork\n", time, p->id);
	if (status == EATING && p->meal_nbr < p->t->time_philo_must_eat)
		printf("%zu %zu is eating\n", time, p->id);
	if (status == SLEEPING)
		printf("%zu %zu is sleeping\n", time, p->id);
	if (status == THINKING)
		printf("%zu %zu is thinking\n", time, p->id);
	pthread_mutex_unlock(&p->t->msg);
	return (1);
}
