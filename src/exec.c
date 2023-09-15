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

int ft_is_dead(t_philo *p)
{
    size_t current_time;

    pthread_mutex_lock(&p->t->death);
    current_time = ft_get_time_mil();
    if (current_time - p->last_meal_time > p->t->time_to_die || p->t->total_meals_nbr >= p->t->time_philo_must_eat)
    {
        pthread_mutex_unlock(&p->t->death);
        return (1);
    }
    pthread_mutex_unlock(&p->t->death);
    return (0);
}

void ft_think(t_philo *p)
{
    ft_print_msg(THINKING, p);
}

void ft_sleep(t_philo *p)
{
    ft_print_msg(SLEEPING, p);
    ft_usleep(p->t->time_to_sleep); //->gettimeofday - starttime
}

void ft_eat(t_philo *p)
{
    // exception if only one philo
    pthread_mutex_lock(&p->t->forks[p->id - 1]);
    ft_print_msg(PICKING_FORK, p);
    if (p->id == p->t->philo_nbr)
        pthread_mutex_lock(&p->t->forks[0]);
    pthread_mutex_lock(&p->t->forks[p->id]);
    ft_print_msg(PICKING_FORK, p);
    ft_print_msg(EATING, p);
    p->t->total_meals_nbr++;
    p->last_meal_time = ft_get_time_mil();
    ft_usleep(p->t->time_to_eat);
    pthread_mutex_unlock(&p->t->forks[p->id - 1]);
    if (p->id == p->t->philo_nbr)
        pthread_mutex_unlock(&p->t->forks[0]);
    pthread_mutex_unlock(&p->t->forks[p->id]);
}

void *ft_routine(void *philo)
{
    t_philo *p;

    p = (t_philo *)philo;
    if ((p->id % 2) == 0)
        ft_usleep(p->t->time_to_eat / 2);
    ft_eat(p);
    ft_sleep(p);
    ft_think(p);
    ft_end_sim(p->t);
    return (NULL);
}
