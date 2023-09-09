#include "../includes/philo.h"

void    ft_join_threads(t_table *t)
{
    int i;

    i = 0;
    while (i < t->philo_nbr)
    {
        if (pthread_join(t->philo[i].thread, NULL) != 0)
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
        t->philo[i].id = i + 1;
        t->philo[i].status = IDLE;
        if (pthread_create(&t->philo[i].thread, NULL, &ft_routine, &t->philo[i]) != 0)
            exit(3);
        i++;
    }
}

void    ft_init_table(char **argv, t_table *t)
{
    t->philo_nbr = ft_atoi(argv[1]); //protec
    t->time_to_die = 0;
    t->time_to_eat = 0;
    t->time_to_sleep = 0;
    t->philo = malloc(sizeof(*t->philo) * t->philo_nbr); //protec
    if (!t->philo)
        exit(6);
}

void    ft_init_sim(char **argv)
{
    t_table t;

    ft_init_table(argv, &t);
    ft_init_philos(&t);
    ft_join_threads(&t);
}