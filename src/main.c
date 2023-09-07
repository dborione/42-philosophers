#include "../includes/philo.h"

// void    ft_get_start_time()
// {
//     gettimeofday();
// }

void    *ft_routine(void *philo)
{
   printf("I am philo %d\n", ((t_philo *)philo)->id);
//    if ((((t_philo *)philo)->status) == 0)
//         printf(" idle\n");
}

// void    ft_destroy_threads(t_table *table, t_philo *philo)
// {
//     int i;
    
//     i = 0;
//     while (philo[i])
//     {
//         if (pthread_join(philo->thread, NULL) != 0) {
//             //return 2;
//             exit(0);
//         }
//         i++;
//         printf("Thread %d has ended\n", philo->id);
//     }
// }


int main(int argc, char **argv)
{
    //t_philo philo;
    //pthread_mutex_t  *forks;

    //check input args
    //initialize table
    //launch threads
    ft_init_sim(argv);
   // ft_join_threads();
    //ft_create_threads(&table, &philo);
    //ft_destroy_threads(&table, &philo);

    return (0);
}