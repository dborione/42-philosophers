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


int main(int argc, char **argv)
{
    // ft_check args
    ft_init_sim(argv);
    return (0);
}