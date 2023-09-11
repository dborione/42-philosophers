/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dborione <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 10:39:08 by dborione          #+#    #+#             */
/*   Updated: 2023/09/11 10:39:09 by dborione         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

// void     *ft_eating()
// {
//    //if forks are unlocked
//       //philo takes the forks
//       //time = time + time_to_eat
//       //fork is unlocked
//    //else philo thinks
//       //time = time + time to think
//    //else philo sleeps
//       //time = time + time to sleep
//    //if time >= time_to_die
//       //philo status = dead
//       //->end simulation

// }

   //mutex lock : bloque la fork si utilisee ailleurs
   //I use the fork
   //mutex unlock
//    if ((((t_philo *)philo)->status) == 0)
//         printf(" idle\n");
void  *ft_eat(t_philo  *p)
{
   pthread_mutex_lock(p->forks[0]);
   ft_print_msg(0, p->id);
   pthread_mutex_lock(p->forks[1]);
   ft_print_msg(0, p->id);
   ft_print_msg(1, p->id);
   pthread_mutex_unlock(p->forks[0]);
   pthread_mutex_unlock(p->forks[1]);

}

void    *ft_routine(void *philo)
{
   t_philo  *p;
   t_table  *t;

   p = ((t_philo *)philo);
   t = p->table;
   //printf("I am philo %d, i am %s and time is %d\n", p->id, p->status, t->start_time);
   ft_eat(p);
   return (p);
}
