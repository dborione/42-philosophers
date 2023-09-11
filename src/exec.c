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

void    *ft_routine2(void *table)
{
   t_table  *t;
   int      i;
                                      
   t = ((t_table *)table);
   i = 0;
   while (i < t->philo_nbr)
   {
      //pthread_mutex_lock(&t->forks[i]);
      printf("I am philo %d\n", t->philos[i].id);
     // pthread_mutex_unlock(&t->forks[i]);
      i++;
   }
   return (t);
   //mutex lock : bloque la fork si utilisee ailleurs
   //I use the fork
   //mutex unlock
//    if ((((t_philo *)philo)->status) == 0)
//         printf(" idle\n");
}


void    *ft_routine(void *philo)
{
   t_philo  *p;
   t_table  *t;

   p = ((t_philo *)philo);
   t = p->table;
   printf("I am philo %d and time is %d\n", p->id, t->start_time);
   
   return (p);
}
