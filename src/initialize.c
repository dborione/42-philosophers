#include "../includes/philo.h"

void ft_join(t_philo *philo)
{
    // if (pthread_join(philo->thread, NULL) != 0)
    //     exit(0);
    printf("philo %d is joined\n", philo->id);
}

void ft_join_philo(t_table *table, t_philo **philo)
{
    int i ;

    i = 0;
    while (i < table->philo_nbr)
    {
        //ft_join(philo[i]);
        printf("%d\n", philo[i]->id);
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
    //printf("%d\n", philo->id);

    // if (pthread_join(philo->thread, NULL) != 0)
    //     exit(0);   

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
    i = 0;
    while (i < t->philo_nbr)
    {
        if (pthread_join(t->philo[i].thread, NULL) != 0)
            exit(0);
        i++;
    }

}

void    ft_init_table(char **argv, t_table *t)
{
    t->philo_nbr = ft_atoi(argv[1]);
    t->time_to_die = 0;
    t->time_to_eat = 0;
    t->time_to_sleep = 0;
    t->philo = malloc(sizeof(*t->philo) * t->philo_nbr); //protec
}

void    ft_init_sim(char **argv)
{
    t_table t;

    ft_init_table(argv, &t);
    ft_init_philos(&t);
    //ft_join_philo(&table, &philo);
}