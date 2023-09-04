#include "../includes/philo.h"

// void    ft_get_start_time()
// {
//     gettimeofday();
// }

void    *ft_routine(void *philo)
{
   printf("I am philo %d\n", ((t_philo *)philo)->id);
}

void    ft_create_threads(t_table *table, t_philo *philo)
{
    int i;

    i = 1;
    while (i <= table->philo_nbr)
    {
        philo->id = i;
        if (pthread_create(&philo->thread, NULL, &ft_routine, philo) != 0) {
            //return 1;
            exit(3);
        }

        i++;
    }
}

void    ft_destroy_threads(t_table *table, t_philo *philo)
{
    int i;
    
    i = 0;
    while (i < table->philo_nbr)
    {
        if (pthread_join(philo->thread, NULL) != 0) {
            //return 2;
            exit(0);
        }
        i++;
        printf("Thread %d has ended\n", philo->id);
    }
}

void    ft_create_philo(int i)
{
    t_philo *philo;
    
    philo = malloc(sizeof(*philo));
    // if (!philo)
        // ft_free_and_exit();
    philo->id = i;
    philo->status = IDLE;
    if (pthread_create(&philo->thread, NULL, &ft_routine, philo) != 0) {
            //return 1;
        exit(3);
    }
    if (pthread_join(philo->thread, NULL) != 0) {
            //return 2;
        exit(0);
    }

}

void    ft_init_table(t_table *table, char **argv)
{
    // ft_check_arg()
    int i;

    i = 1;
    table->philo_nbr = ft_atoi(argv[1]);
    while(i <= table->philo_nbr)
        ft_create_philo(i++);
    //ft_create_philo(1);
    
}

int main(int argc, char **argv)
{
    t_table table;
    //t_philo philo;
    
    ft_init_table(&table, argv);
    //ft_create_threads(&table, &philo);
   // ft_destroy_threads(&table, &philo);

    return (0);
}