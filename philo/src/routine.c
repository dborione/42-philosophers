/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dborione <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 14:08:46 by dborione          #+#    #+#             */
/*   Updated: 2023/09/18 15:59:17 by dborione         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static void    *ft_one_philo(t_philo *p)
{
	printf("%zu %zu has taken a fork\n",
		ft_get_time_mil() - p->t->start_time, p->id);
	printf("%zu %zu died\n", p->t->time_to_die, p->id);
	return (NULL);
}

static int	ft_sleep(t_philo *p)
{
	if (p->t->sim_status == DONE)
		return (0);
	if (!ft_print_msg(SLEEPING, p))
		return (0);
	if (!ft_usleep(p, p->t->time_to_sleep))
        return (ft_print_msg(DEAD, p));
	return (1);
}

static int ft_unlock_forks(t_philo *p)
{
    pthread_mutex_unlock(p->left_fork);
	pthread_mutex_unlock(p->right_fork);
	return (0);
}

static int	ft_eat(t_philo *p)
{
	if (p->t->sim_status == DONE)
		return (0);
	pthread_mutex_lock(p->left_fork);
	if (!ft_print_msg(PICKING_FORK, p))
    {
	    pthread_mutex_unlock(p->left_fork);
		return (0);
    }
	pthread_mutex_lock(p->right_fork);
	p->last_meal_time = ft_get_time_mil();
	if (!ft_print_msg(PICKING_FORK, p))
        return (ft_unlock_forks(p));
	if (!ft_print_msg(EATING, p))
        return (ft_unlock_forks(p));
	p->meal_nbr++;
	if (p->t->time_philo_must_eat > 0 
		&& p->meal_nbr == p->t->time_philo_must_eat)
		p->t->full_philos_nbr--;
	if (!ft_usleep(p, p->t->time_to_eat))
    {
        ft_unlock_forks(p);
		return (ft_print_msg(DEAD, p));
    }
    ft_unlock_forks(p);
	return (1);
}

void	*ft_routine(void *philo)
{
	t_philo	*p;

	p = philo;
	if (p->t->philo_nbr == 1)
        return (ft_one_philo(p));
	if ((p->id % 2) == 0)
		ft_usleep(p, p->t->time_to_eat / 2);
	while (p->t->sim_status != DONE)
	{
		if (!ft_eat(p))
			return (NULL);
		if (!ft_sleep(p))
			return (NULL);
		if (p->t->sim_status == DONE)
			return (NULL);
		if (!ft_print_msg(THINKING, p))
			return (NULL);
	}
	return (NULL);
}
