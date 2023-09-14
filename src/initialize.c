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

void    ft_mutex_init(pthread_mutex_t *mutex, t_table *t)
{
    if (pthread_mutex_init(mutex, NULL))
    {
        printf("error with mutex initialisation\n");
        ft_free_and_exit(t);
    }
}

void    ft_init_all_mutex(t_table *t)
{
    size_t i;

    i = 0;
    ft_mutex_init(&t->death, t);
    ft_mutex_init(&t->msg, t);
    while (i < t->philo_nbr)
    {
        ft_mutex_init(&t->forks[i], t);
        i++;
    }
}

void    ft_init_philos(t_table *t)
{
    size_t i;

    i = 0; 
    while (i < t->philo_nbr)
    {
        t->philos[i].t = t;
        t->philos[i].id = i + 1;
        t->philos[i].last_meal_time = t->start_time;
        t->philos[i].left_fork = &t->forks[i];
        if (t->philos[i].id == 1)
            t->philos[i].right_fork = &t->forks[t->philo_nbr - 1];
        else
            t->philos[i].right_fork = t->philos[i - 1].left_fork;
        if (pthread_create(&t->philos[i].thread, NULL, &ft_routine, &t->philos[i]) != 0)
            ft_end_sim(t);
        i++;
    }
}

void    ft_init_table(char **argv, t_table *t)
{
    t->philo_nbr = ft_atoi(argv[1]); //protec
    t->time_to_die = ft_atoi(argv[2]);
    t->time_to_eat = ft_atoi(argv[3]);
    t->time_to_sleep = ft_atoi(argv[4]);
    t->time_philo_must_eat = ft_atoi(argv[5]);
    t->total_meals_nbr = 0;
    t->philos = malloc(sizeof(*t->philos) * t->philo_nbr); //protec
    if (!t->philos)
        ft_free_and_exit(t);
    t->forks = malloc(sizeof(*t->forks) * t->philo_nbr);//protec
    if (!t->forks)
        ft_free_and_exit(t);
    ft_init_all_mutex(t);
    t->start_time = ft_get_time_mil();
}