#include "../includes/philo.h"

// void    ft_get_start_time()
// {
//     gettimeofday();
// }

void    *ft_routine()
{
    printf("I am a philo\n");
}

void    ft_create_threads(t_philo *philo, pthread_t threads)
{
    int i;
    
    i = 0;
    while (i < philo->nbr)
    {
        if (pthread_create(threads + i, NULL, &ft_routine, NULL) != 0) {
            //return 1;
            exit(0);
        }
        i++;
    }
}

void    ft_destroy_threads(t_philo *philo, pthread_t threads)
{
    int i;
    
    i = 0;
    while (i < philo->nbr)
    {
        if (pthread_join(threads[i], NULL) != 0) {
            //return 2;
            exit(0);
        }
        i++;
        printf("Thread %d has ended\n", i);
    }
}



int main(int argc, char **argv)
{
    t_philo philo;
    philo.nbr = ft_atoi(argv[1]);


    pthread_t   threads[philo.nbr];

    ft_create_threads(&philo, &threads);
    ft_destroy_threads(&philo, &threads);

    return (0);
}