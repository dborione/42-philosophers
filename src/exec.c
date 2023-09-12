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
   pthread_mutex_lock(&p->t->death);
   // if ((p->last_meal_time + p->t->start_time) >= p->t->time_to_die)
   //    return (1);
   if (p->meal_nbr >= p->t->time_philo_must_eat)
   {
      pthread_mutex_unlock(&p->t->death);
      return (1);
   }
   pthread_mutex_unlock(&p->t->death);
   return (0);
}

void  ft_think(t_philo *p)
{
   ft_print_msg(THINKING, p);
}

void  ft_sleep(t_philo  *p)
{
   ft_print_msg(SLEEPING, p);
   usleep(p->t->time_to_sleep); //->gettimeofday - starttime
}

int   ft_eat(t_philo  *p)
{
   pthread_mutex_lock(&(p->t->forks[p->id - 1]));
   ft_print_msg(PICKING_FORK, p);
   // exception if only one philo
   pthread_mutex_lock(&(p->t->forks[p->id]));
   ft_print_msg(PICKING_FORK, p);
   p->meal_nbr++;
   ft_print_msg(EATING, p);
   usleep(p->t->time_to_eat);
   p->last_meal_time = ft_get_time();
   pthread_mutex_unlock(&(p->t->forks[p->id - 1]));
   pthread_mutex_unlock(&(p->t->forks[p->id]));
   return (1);
}

void    *ft_routine(void *philo)
{
   t_philo  *p;
   t_table  *t;

   p = ((t_philo *)philo);
   t = p->t;
   t->start_time = ft_get_time();
   if (p->id % 2 != 0)
      usleep(200);
   while (!ft_is_dead(p))
   {
      ft_eat(p);
      ft_sleep(p);
      ft_think(p);
   }
   ft_join_threads(t);
   ft_destroy_mutex(t);
   return (p);
}
