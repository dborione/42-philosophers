/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dborione <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 10:39:08 by dborione          #+#    #+#             */
/*   Updated: 2023/09/11 10:39:09 by dborione         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int   ft_is_dead(t_philo *p)
{
    size_t current_time;

    current_time = ft_get_time_mil();
    pthread_mutex_lock(&p->t->death);
    if (current_time - p->last_meal_time > p->t->time_to_die
		|| p->t->total_meals_nbr >= p->t->time_philo_must_eat)
    {
        ft_print_msg(DEAD, p);
        pthread_mutex_unlock(&p->t->death);
		ft_end_sim(p->t);
        return (1);
    }
    pthread_mutex_unlock(&p->t->death);
    return (0);
}

void    ft_think(t_philo *p)
{
    ft_print_msg(THINKING, p);
}

void    ft_sleep(t_philo  *p)
{
    ft_print_msg(SLEEPING, p);
    ft_usleep(p->t->time_to_sleep); //->gettimeofday - starttime
}

void    ft_eat(t_philo  *p)
{
	// exception if only one philo
    pthread_mutex_lock(p->left_fork);
    //DEAD VERIF
    ft_print_msg(PICKING_FORK, p);
    pthread_mutex_lock(p->right_fork);
    // pthread_mutex_lock(&(p->meal_mutex));
    ft_print_msg(PICKING_FORK, p);
    p->t->total_meals_nbr++;
    //DEAD VERIF
    ft_print_msg(EATING, p);
    //ft_print_msg(6, p);
    p->last_meal_time = ft_get_time_mil();
    ft_usleep(p->t->time_to_eat);
    pthread_mutex_unlock(p->left_fork);
    pthread_mutex_unlock(p->right_fork);
   // pthread_mutex_unlock(&(p->meal_mutex));
}

void    *ft_routine(void *philo)
{
    t_philo  *p;

    p = (t_philo *)philo;
    if ((p->id % 2) == 0)
        ft_usleep(100);
    while (!ft_is_dead(p))
    {
        ft_eat(p);
        ft_is_dead(p);
        ft_sleep(p);
        ft_think(p);
    }
    return (NULL);
}
