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
    size_t time;

    pthread_mutex_lock(&p->t->death);
    pthread_mutex_lock(&p->t->meal_mutex);
    time = ft_get_time_mil();
    size_t death_time = time - p->t->start_time;
    if (time - p->last_meal_time >= p->t->time_to_die)
    {
        pthread_mutex_lock(&p->t->dead_nbr_mutex);
        p->t->dead_nbr = 1;
        p->t->dead_philo_id = p->id;
        p->t->dead_philo_time = death_time;
        pthread_mutex_unlock(&p->t->dead_nbr_mutex);
        pthread_mutex_unlock(&p->t->death);
        pthread_mutex_unlock(&p->t->meal_mutex);
        return (1);
    }
    if ()
    pthread_mutex_unlock(&p->t->death);
    pthread_mutex_unlock(&p->t->meal_mutex);
    return (0);
}

static void ft_think(t_philo *p)
{
    ft_print_msg(THINKING, p);
}

static void ft_sleep(t_philo *p)
{
    ft_print_msg(SLEEPING, p);
    ft_usleep(p->t->time_to_sleep);
}

static int ft_eat(t_philo *p)
{
    pthread_mutex_lock(p->left_fork);
    ft_print_msg(PICKING_FORK, p);
    if (p->t->philo_nbr == 1)
    {
        pthread_mutex_unlock(p->left_fork);
       // ft_print_dead(p, ft_get_time_mil());
        return (0);
    }
    if (p->t->dead_nbr == 1)
    {
        pthread_mutex_unlock(p->left_fork);
        pthread_mutex_lock(&p->t->dead_nbr_mutex);
        p->t->dead_nbr = 1;
        pthread_mutex_unlock(&p->t->dead_nbr_mutex);
        return (0);
    }
    pthread_mutex_lock(p->right_fork);
    ft_print_msg(PICKING_FORK, p);
    ft_print_msg(EATING, p);
    pthread_mutex_lock(&p->t->meal_mutex);
    if (p->t->total_meals_nbr < p->t->time_philo_must_eat)
        p->t->total_meals_nbr++;
    pthread_mutex_unlock(&p->t->meal_mutex);
    p->last_meal_time = ft_get_time_mil();
    ft_usleep(p->t->time_to_eat);
    pthread_mutex_unlock(p->left_fork);
    pthread_mutex_unlock(p->right_fork);
    return (1);
}

void *ft_routine(void *philo)
{
    t_philo *p;

    p = philo;
    if ((p->id % 2) == 0)
        ft_usleep(p->t->time_to_eat / 2);
    while (!ft_is_dead(p))
    {
        if (!ft_eat(p))
            return (NULL);
        if (ft_is_dead(p))
            return (NULL);
        ft_sleep(p);
        if (ft_is_dead(p))
            return (NULL);
        ft_think(p);
    }
    return (NULL);
}
