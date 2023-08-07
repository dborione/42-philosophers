#include "../includes/philo.h"

void    *ft_routine()
{
    printf("Hello from thread\n");
}

int main(int argc, char **argv)
{
    t_philo philo;
    philo.nbr = ft_atoi(argv[1]);
    int i = 0;

    pthread_t   threads[philo.nbr];
    while (i < philo.nbr)
    {
        if (pthread_create(threads + i, NULL, &ft_routine, NULL) != 0) {
            return 1;
        }
        i++;
    }
    i = 0;
    while (i < philo.nbr)
    {
        if (pthread_join(threads[i], NULL) != 0) {
            return 2;
        }
        i++;
        printf("Thread %d has ended\n", i);
    }
    return (0);
}