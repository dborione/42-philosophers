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

int   ft_is_dead(t_philo *p)
{
    size_t time;

    time = ft_get_time();
   pthread_mutex_lock(&p->t->death);
//    if (time - p->last_meal_time >= p->t->time_to_die)
//       return (1);
   if (p->meal_nbr >= p->t->time_philo_must_eat)
   {
      pthread_mutex_unlock(&p->t->death);
      return (1);
   }
   //usleep(100);
   pthread_mutex_unlock(&p->t->death);
   return (0);
}

int  ft_think(t_philo *p)
{
   while (!ft_is_dead(p))
   {
      ft_print_msg(THINKING, p);
      return (1);
   }
   return (0);
}

int ft_sleep(t_philo  *p)
{
   while (!ft_is_dead(p))
   {
      ft_print_msg(SLEEPING, p);
      usleep(p->t->time_to_sleep); //->gettimeofday - starttime
      return (1);
   }
   return (0);
}

int   ft_eat(t_philo  *p)
{
   while (!ft_is_dead(p))
   {
      pthread_mutex_lock(&(p->t->forks[p->id - 1]));
      ft_print_msg(PICKING_FORK, p);
      // exception if only one philo
      pthread_mutex_lock(&(p->t->forks[p->id]));
      pthread_mutex_lock(&(p->meal_mutex));
      ft_print_msg(PICKING_FORK, p);
      p->meal_nbr++;
      ft_print_msg(EATING, p);
      //ft_print_msg(6, p);
      usleep(p->t->time_to_eat);
      p->last_meal_time = ft_get_time();
      pthread_mutex_unlock(&(p->t->forks[p->id - 1]));
      pthread_mutex_unlock(&(p->t->forks[p->id]));
      pthread_mutex_unlock(&(p->meal_mutex));
      return (1);
   }
   return(0);
}

t_philo   *ft_print_dead(t_philo *p)
{
    ft_print_msg(DEAD, p);
    return (p); 
}

void    *ft_routine(void *philo)
{
   t_philo  *p;

   p = philo;
   if ((p->id % 2) == 0)
      usleep(200);
   if(!ft_eat(p))
        return (ft_print_dead(p));
   if (!ft_sleep(p))
        return (ft_print_dead(p));
   if (!ft_think(p))
        return (ft_print_dead(p));
   //ft_print_msg(DEAD, p);
   // ft_end_sim(p);
   return (p);
}
