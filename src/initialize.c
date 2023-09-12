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

void    ft_join_threads(t_table *t)
{
    size_t i;

    i = 0;
    while (i < t->philo_nbr)
    {
        if (pthread_join(t->philos[i].thread, NULL) != 0)
            exit(2);
        // free(t->philos[i]);
        i++;
    }
}

void    ft_init_mutex(t_table *t)
{
    size_t i;

    i = 0;
    pthread_mutex_init(&t->death, NULL); //protec
    pthread_mutex_init(&t->msg, NULL); //protec
    while (i < t->philo_nbr)
    {
        pthread_mutex_init(&t->forks[i], NULL);
        i++;
    }
}

void    ft_destroy_mutex(t_table *t)
{
    size_t i;

    i = 0;
    pthread_mutex_destroy(&t->death);
    pthread_mutex_destroy(&t->msg);
    while (i < t->philo_nbr)
    {
        pthread_mutex_destroy(&t->forks[i]);
        i++;
    }
}

void    ft_init_philos(t_table *t)
{
    size_t i;

    i = 0;
    while (i < t->philo_nbr)
    {
        t->philos[i].meal_nbr = 0;
        t->philos[i].t = t; 
        t->philos[i].id = i + 1;
        if (pthread_create(&t->philos[i].thread, NULL, &ft_routine, &t->philos[i]) != 0)
            exit(3);
        i++;
    }
}

void    ft_init_table(char **argv, t_table *t)
{
    t->start_time = 0;
    t->philo_nbr = ft_atoi(argv[1]); //protec
    t->time_to_die = ft_atoi(argv[2]);
    t->time_to_eat = ft_atoi(argv[3]);
    t->time_to_sleep = ft_atoi(argv[4]);
    t->time_philo_must_eat = ft_atoi(argv[5]);
    t->philos = malloc(sizeof(*t->philos) * t->philo_nbr); //protec
    if (!t->philos)
        exit(6);
    t->forks = malloc(sizeof(*t->forks) * t->philo_nbr);//protec
    if (!t->forks)
        exit(7);
}