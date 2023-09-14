#include "../includes/philo.h"

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

void    ft_join_threads(t_table *t)
{
    size_t i;

    i = 0;
    while (i < t->philo_nbr)
    {
        pthread_join(t->philos[i].thread, NULL);//free mallocs
        i++;
    }
    ft_free_and_exit(t);
}

void    ft_free_and_exit(t_table *t)
{
    if (t->philos)
        free(t->philos);
    if (t->forks)
        free(t->forks);
    //printf error message
    exit(0);
}

void	ft_end_sim(t_table *t)
{
   	ft_destroy_mutex(t);
	ft_join_threads(t);
}

