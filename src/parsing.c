/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dborione <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 10:39:29 by dborione          #+#    #+#             */
/*   Updated: 2023/09/11 10:39:30 by dborione         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void    ft_parsing_error(int error)
{
    if (error == 1)
    {
        printf("args must be:");
        printf(" number_of_philosophers time_to_die time_to_eat"); 
        printf("time_to_sleep [number_of_times_each_philosopher_must_eat]\n");
        exit(error);
    }
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

int ft_check_args(int argc, char **argv)
{
    int i;
    int j;

    i = 0;
    j = -1;
    if (argc < 5 || argc > 6)
        return (0);
    while (argv[++i])
    {
        while (argv[i][++j])
        {
            if (!ft_isdigit(argv[i][j]))
                return (0);
        }
        j = -1;
    }
    // verif if one arg is 0
    return (1);
}
