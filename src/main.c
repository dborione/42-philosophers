#include "../includes/philo.h"

// void    ft_get_start_time()
// {
//     gettimeofday();
// }

void    *ft_routine(void *philo)
{
   printf("I am philo %d\n", ((t_philo *)philo)->id);
   //mutex lock : bloque la fork si utulisee ailleurs
   //I use the fork
   //mutex unlock
//    if ((((t_philo *)philo)->status) == 0)
//         printf(" idle\n");
}


int main(int argc, char **argv)
{
    // ft_check args
    ft_init_sim(argv);
    // ft_get_start_time
    // ft_init_mutex
    // ft_destroy_mutex
    return (0);
}