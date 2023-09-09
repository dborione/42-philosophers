#include "../includes/philo.h"

void    ft_join_threads(t_table *t)
{
    int i;

    i = 0;
    while (i < t->philo_nbr)
    {
        if (pthread_join(t->philos[i].thread, NULL) != 0)
            exit(2);
        i++;
    }
}

void    ft_init_philos(t_table *t)
{
    int i;

    i = 0;
    while (i < t->philo_nbr)
    {
        t->philos[i].id = i + 1;
        t->philos[i].status = IDLE;
        if (pthread_create(&t->philos[i].thread, NULL, &ft_routine, &t->philos[i]) != 0)
            exit(3);
        i++;
    }
}

void    ft_init_table(char **argv, t_table *t)
{
    t->start_time = 0;
    t->philo_nbr = ft_atoi(argv[1]); //protec
    t->time_to_die = 0;
    t->time_to_eat = 0;
    t->time_to_sleep = 0;
    t->philos = malloc(sizeof(*t->philos) * t->philo_nbr); //protec
    if (!t->philos)
        exit(6);
    t->forks = malloc(sizeof(*t->forks) * t->philo_nbr);//protec
    if (!t->forks)
        exit(7);
}

void    ft_init_sim(char **argv)
{
    t_table t;

    ft_init_table(argv, &t);
    ft_init_philos(&t);
    ft_join_threads(&t);
}