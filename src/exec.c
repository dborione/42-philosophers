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

int   ft_is_dead(t_philo *p)
{
   //mutex_lock(death)
   //if time >= time_to_die && meal_nbr == 0
   //or if 
      //return (1)
   // if ((p->t->start_time - ft_get_time) >= p->t->time_to_die)
   //    return (0);
   // return (1);
}

void  ft_think(t_philo *p)
{
   ft_print_msg(THINKING, p);
}

void  ft_sleep(t_philo  *p)
{
   ft_print_msg(SLEEPING, p);
   usleep(p->table->time_to_sleep); //->gettimeofday - starttime
}

int   ft_eat(t_philo  *p)
{
   pthread_mutex_lock(p->left_fork);
   ft_print_msg(PICKING_FORK, p);
   pthread_mutex_lock(p->right_fork);
   ft_print_msg(PICKING_FORK, p);
   p->meal_nbr++;
   ft_print_msg(EATING, p);
   usleep(p->table->time_to_eat);
   pthread_mutex_unlock(p->left_fork);
   pthread_mutex_unlock(p->right_fork);
   return (1);
}

void    *ft_routine(void *philo)
{
   t_philo  *p;
   t_table  *t;

   p = ((t_philo *)philo);
   t = p->table;
   t->start_time = ft_get_time();
   if (p->id % 2 != 0)
      usleep(100);
   //while (!ft_is_dead)
      ft_eat(p);
      ft_sleep(p);
      ft_think(p);
   //ft_end_sim
   return (p);
}
