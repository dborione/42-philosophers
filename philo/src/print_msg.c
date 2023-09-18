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

void    ft_print_dead(t_philo *p, size_t time)
{
    pthread_mutex_lock(&p->t->msg);
    time = time - p->t->start_time;
    printf("%zu ms %zu died\n", time, p->id);
    pthread_mutex_unlock(&p->t->msg);
}

void ft_print_msg(int status, t_philo *p)
{
	size_t	time;

	pthread_mutex_lock(&(p->t->msg));
	time = ft_get_time_mil() - p->t->start_time;
	if (status == PICKING_FORK)
		printf("%zu ms %zu has taken a fork\n", time, p->id);
	if (status == EATING)
	{
		printf("%zu ms %zu is eating\n", time, p->id);
		//printf("%zu \n", p->last_meal_time - p->t->start_time);
	}
	if (status == SLEEPING)
		printf("%zu ms %zu is sleeping\n", time, p->id);
	if (status == THINKING)
		printf("%zu ms %zu is thinking\n", time, p->id);
	pthread_mutex_unlock(&(p->t->msg));
}
