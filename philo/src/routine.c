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

static void    ft_get_death_infos(t_philo *p, size_t time)
{
    p->t->dead_nbr = 1;
    p->t->dead_philo_id = p->id;
    p->t->dead_philo_time = time;
}

int ft_is_dead(t_philo *p)
{
    size_t time;

    pthread_mutex_lock(&p->t->death);
    time = ft_get_time_mil();
    // printf("%d ", p->t->dead_nbr);
    // printf("%zu, ", p->id);
    // printf("%zu, ", time);
    // printf("%zu: ", p->last_meal_time);
    // printf("%zu\n", time - p->last_meal_time);
    if (time - p->last_meal_time >= p->t->time_to_die)
    {
        //printf("fjkds\n");
        ft_get_death_infos(p, time);
        pthread_mutex_unlock(&p->t->death);
        return (TRUE);
    }
    pthread_mutex_unlock(&p->t->death);
    if (p->meal_nbr >= p->t->time_philo_must_eat)
        return (TRUE);
    return (FALSE);
}

static void ft_sleep(t_philo *p)
{
    ft_print_msg(SLEEPING, p);
    ft_usleep(p->t->time_to_sleep);
}

static int ft_eat(t_philo *p)
{
    if (p->t->dead_nbr == 1)
        return (0);
    pthread_mutex_lock(p->left_fork);
    ft_print_msg(PICKING_FORK, p);
    if (p->t->philo_nbr == 1)
    {
        pthread_mutex_unlock(p->left_fork);
        return (0);
    }
    pthread_mutex_lock(p->right_fork);
    ft_print_msg(PICKING_FORK, p);
    ft_print_msg(EATING, p);
    p->meal_nbr++;
    ft_usleep(p->t->time_to_eat);
    p->last_meal_time = ft_get_time_mil();
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
    //printf("%zu\n", p->last_meal_time);
    //printf("%zu\n", p->t->start_time);
    while (!ft_is_dead(p))
    {
        if (ft_is_dead(p))
            return (NULL);
        if (!ft_eat(p))
            return (NULL);
        if (ft_is_dead(p))
            return (NULL);
        ft_sleep(p);
        if (ft_is_dead(p))
            return (NULL);
        ft_print_msg(THINKING, p);
    }
    return (NULL);
}
