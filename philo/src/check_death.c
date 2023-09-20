/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_death.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dborione <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 16:01:18 by dborione          #+#    #+#             */
/*   Updated: 2023/09/20 16:01:21 by dborione         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ft_is_dead(t_philo *p)
{
	atomic_size_t	time;

	time = ft_get_time_mil();
	if (time - p->last_meal_time >= p->t->time_to_die)
    {
        p->status = DEAD;
		return (TRUE);
    }
	if (p->meal_nbr >= p->t->time_philo_must_eat)
		return (TRUE);
	return (FALSE);
}
