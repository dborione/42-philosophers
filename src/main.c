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
        ft_parsing_error(1);
    ft_init_table(argv, &t);
    ft_init_philos(&t);
    ft_end_sim(&t);
    return (0);
}
