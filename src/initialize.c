#include "../includes/philo.h"

void ft_join(t_philo *philo)
{
    if (pthread_join(philo->thread, NULL) != 0)
        exit(0);     
}

void ft_join_philo(t_table *table, t_philo *philo)
{
    int i ;

    i = 0;
    while(i < table->philo_nbr)
    {
        ft_join(&philo[i]);
        i++;
    }
}

void    ft_create_philo(int i, t_philo *philo)
{
    philo = malloc(sizeof(*philo));
    // if (!philo)
        // ft_free_and_exit();
    philo->id = i + 1;
    philo->status = IDLE;
    if (pthread_create(&philo->thread, NULL, &ft_routine, philo) != 0) {
            //return 1;
        exit(3);
    }
    if (pthread_join(philo->thread, NULL) != 0)
        exit(0);   

}

void    ft_init_philos(t_table *table, t_philo **philo)
{  
    int     i;

    i = 0;
    while (i < table->philo_nbr)
    {
        ft_create_philo(i, philo[i]);
        i++;
    }
}

void    ft_init_table(char **argv, t_table *table)
{
    table->philo_nbr = ft_atoi(argv[1]);
    table->time_to_die = 0;
    table->time_to_eat = 0;
    table->time_to_sleep = 0;
}

void    ft_init_sim(char **argv)
{
    t_table table;
    t_philo *philo;

    ft_init_table(argv, &table);
    ft_init_philos(&table, &philo);
}