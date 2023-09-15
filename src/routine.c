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

void    ft_print_dead2(t_philo *p, size_t time)
{
    pthread_mutex_lock(&p->t->msg);
    time = time - p->t->start_time;
    printf("%zu ms %zu died\n", time, p->id);
    pthread_mutex_unlock(&p->t->msg);
}

int ft_is_dead(t_philo *p)
{
    size_t time;

    pthread_mutex_lock(&p->t->death);
    time = ft_get_time_mil();
    if (time - p->last_meal_time > p->t->time_to_die 
        || p->t->total_meals_nbr >= p->t->time_philo_must_eat)
    {
        ft_print_dead2(p, time);
        pthread_mutex_unlock(&p->t->death);
        return (1);
    }
    pthread_mutex_unlock(&p->t->death);
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

static void ft_eat(t_philo *p)
{
    // exception if only one philo
    pthread_mutex_lock(p->left_fork);
    ft_print_msg(PICKING_FORK, p);
    pthread_mutex_lock(p->right_fork);
    ft_print_msg(PICKING_FORK, p);

    ft_print_msg(EATING, p);
    p->t->total_meals_nbr++;
    p->last_meal_time = ft_get_time_mil();
    ft_usleep(p->t->time_to_eat);

    pthread_mutex_unlock(p->left_fork);
    pthread_mutex_unlock(p->right_fork);
}

void *ft_routine(void *philo)
{
    t_philo *p;

    p = philo;
    if ((p->id % 2) == 0)
        ft_usleep(p->t->time_to_eat / 2);
    while (!ft_is_dead(p))
    {
        ft_eat(p);
        ft_sleep(p);
        ft_think(p);
    }
    ft_print_msg(DEAD, p);
    return (p);
}
