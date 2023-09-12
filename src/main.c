/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dborione <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 10:39:22 by dborione          #+#    #+#             */
/*   Updated: 2023/09/11 10:39:24 by dborione         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void    ft_error(int error)
{
    if (error == 1)
    {
        printf("args must be:");
        printf(" number_of_philosophers time_to_die time_to_eat"); 
        printf("time_to_sleep [number_of_times_each_philosopher_must_eat]\n");
        exit(1);
    }
}

int main(int argc, char **argv)
{
    t_table t;

    if (!ft_check_args(argc, argv))
        ft_error(1);
    ft_init_table(argv, &t);
    ft_init_mutex(&t);
    ft_init_philos(&t);
    return (0);
}
