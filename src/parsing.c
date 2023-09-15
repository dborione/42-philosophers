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

static int	ft_isdigit(int c)
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
        if (ft_atoi(argv[i]) == 0)
            return (0);
        j = -1;
    }
    return (1);
}
