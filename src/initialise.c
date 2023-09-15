/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dborione <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 10:39:14 by dborione          #+#    #+#             */
/*   Updated: 2023/09/11 10:39:18 by dborione         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int ft_init_mutex(t_table *t)
{
    size_t i;

    i = 0;
    if (pthread_mutex_init(&t->meal_mutex, NULL))
        return (ft_free_all(t));
    if (pthread_mutex_init(&t->death, NULL))
        return (ft_free_all(t));
    if (pthread_mutex_init(&t->msg, NULL))
        return (ft_free_all(t));
    while (i < t->philo_nbr)
    {
        if (pthread_mutex_init(&t->forks[i], NULL))
            return (ft_free_all(t));
        i++;
    }
    return (1);
}

int ft_init_philos(t_table *t)
{
    size_t i;

    i = 0;
    t->start_time = ft_get_time_mil();
    while (i < t->philo_nbr)
    {
        t->philos[i].t = t;
        t->philos[i].id = i + 1;
        t->philos[i].last_meal_time = t->start_time;
        t->philos[i].left_fork = &(t->forks[i]);
        if (t->philos[i].id == t->philo_nbr)
            t->philos[i].right_fork = &(t->forks[0]);
        else
            t->philos[i].right_fork = &(t->forks[i + 1]);
        if (pthread_create(&t->philos[i].thread, NULL, &ft_routine, &t->philos[i]) != 0)
            return (ft_free_all(t));
        i++;
    }
    return (1);
}

int ft_init_table(int argc, char **argv, t_table *t)
{
    //t->status = IDLE;
    t->philo_nbr = ft_atoi(argv[1]);
    t->time_to_die = ft_atoi(argv[2]);
    t->time_to_eat = ft_atoi(argv[3]);
    t->time_to_sleep = ft_atoi(argv[4]);
    if (argc == 6)
        t->time_philo_must_eat = ft_atoi(argv[5]);
    else
        t->time_philo_must_eat = -1;
    t->total_meals_nbr = 0;
    t->philos = malloc(sizeof(*t->philos) * t->philo_nbr);
    if (!t->philos)
        return (ft_free_all(t));
    t->forks = malloc(sizeof(*t->forks) * t->philo_nbr);
    if (!t->forks)
        return (ft_free_all(t));
    return (1);
}