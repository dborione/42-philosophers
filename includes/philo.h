#ifndef PHILO_H
# define PHILO_H

# include <unistd.h> //NULL
# include <pthread.h>
# include <stdio.h>
# include <sys/time.h> //gettimeofday
# include <stdlib.h> //exit

# define IDLE 0
# define SLEEPING 1
# define THINKING 2
# define EATING 3
# define DEAD 4

typedef struct s_node
{
	pthread_t       t;
	struct s_node	*next;
}	t_node;

typedef struct s_table {
    int philo_nbr;
    int time_to_die;
    int time_to_sleep;
    int time_to_eat;
}   t_table;

typedef struct s_philo {
    int             id;
    int             status;
    pthread_t       thread;
    struct s_philo  *next;
}   t_philo;

int	ft_atoi(const char *str);
void    *ft_routine(void *philo);
void    ft_init_sim(char **argv);
void    ft_init_table(char **argv, t_table *table);
void    ft_init_philos(t_table *table, t_philo **philo);
void    ft_create_philo(int i, t_philo *philo);

#endif