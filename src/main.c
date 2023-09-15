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

int main(int argc, char **argv)
{
    t_table t;

    if (!ft_check_args(argc, argv))
        return (ft_print_error(ERROR_PARSING));
    if (!ft_init_table(argc, argv, &t))
        return (ft_print_error(ERROR_INIT_TABLE));
    if (!ft_init_mutex(&t))
        return (ft_print_error(ERROR_MUTEX));
    if(!ft_init_philos(&t))
        return (ft_print_error(ERROR_INIT_PHILO));
    if (t.dead_nbr == 1)
        printf("philo died");
    ft_end_sim(&t);
    ft_free_all(&t);
    if (t.dead_nbr == 1)
        printf("%zu ms %d died\n", t.dead_philo_time, t.dead_philo_id);
    return (0);
}
