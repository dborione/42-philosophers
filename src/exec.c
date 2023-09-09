#include "../includes/philo.h"

void    *ft_routine(void *philo)
{
   printf("I am philo %d\n", ((t_philo *)philo)->id);
   //mutex lock : bloque la fork si utulisee ailleurs
   //I use the fork
   //mutex unlock
//    if ((((t_philo *)philo)->status) == 0)
//         printf(" idle\n");
}
