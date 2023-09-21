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

int	ft_print_msg(atomic_int status, t_philo *p)
{
	atomic_size_t	time;

	if (p->t->sim_status == DONE)
		return (0);
	pthread_mutex_lock(&p->t->msg);
	printf("%d\n", p->t->sim_status);
	time = ft_get_time_mil() - p->t->start_time;
	if (status == DEAD || ft_is_dead(p))
	{
		p->t->sim_status = DONE;
		printf("%zu %zu died\n", time, p->id);
		pthread_mutex_unlock(&p->t->msg);
		return (0);
	}
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
