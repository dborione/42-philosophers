#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>

typedef struct s_node
{
	pthread_t       t;
	struct s_node	*next;
}	t_node;

typedef struct s_philo {
    int nbr;
    int time_to_die;
    int time_to_sleep;
    int time_to_eat;
} t_philo;

int	ft_atoi(const char *str);


#endif