#include "../includes/philo.h"

int ft_free_all(t_table *t)
{
    if (t->philos)
        free(t->philos);
    if (t->forks)
        free(t->forks);
    return (0);
}

static void ft_destroy_mutex(t_table *t)
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

static void ft_join_threads(t_table *t)
{
    size_t i;

    i = 0;
    while (i < t->philo_nbr)
    {
        pthread_join(t->philos[i].thread, NULL);
        i++;
    }
}

void ft_end_sim(t_table *t)
{
    ft_join_threads(t);
    ft_destroy_mutex(t);
}
