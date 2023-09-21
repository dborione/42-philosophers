/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dborione <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 13:53:18 by dborione          #+#    #+#             */
/*   Updated: 2023/09/21 15:07:25 by dborione         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <pthread.h>
# include <stdio.h>
# include <sys/time.h>
# include <stdlib.h>
# include <stdatomic.h>

# define TRUE 1
# define FALSE 0

# define RUNNING 1
# define DONE 0

# define DEAD 0
# define SLEEPING 1
# define THINKING 2
# define EATING 3
# define PICKING_FORK 4
# define IDLE 5

# define ERROR_PARSING 1
# define ERROR_INIT_TABLE 2
# define ERROR_MUTEX 3
# define ERROR_INIT_PHILO 4

typedef struct s_table	t_table;

typedef struct s_philo {
	size_t			id;
	pthread_t		thread;
	atomic_size_t	last_meal_time;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*left_fork;
	atomic_int		meal_nbr;
	t_table			*t;
}	t_philo;

typedef struct s_table {
	size_t			philo_nbr;
	size_t			time_to_die;
	size_t			time_to_sleep;
	size_t			time_to_eat;
	size_t			time_philo_must_eat;
	atomic_int		full_philos_nbr;
	atomic_int		dead_nbr;
	atomic_int		sim_status;
	atomic_size_t	start_time;
	pthread_mutex_t	death;
	pthread_mutex_t	msg;
	pthread_mutex_t	*forks;
	t_philo			*philos;
}	t_table;

// Parsing
int		ft_check_args(int argc, char **argv);
int		ft_atoi(const char *str);

// Initialisation
int		ft_init_table(int argc, char **argv, t_table *t);
int		ft_init_mutex(t_table *t);
int		ft_init_philos(t_table *table);

// Error
int		ft_print_error(int error_code);

// Time
size_t	ft_get_time_mil(void);
int		ft_usleep(t_philo *p, size_t time);

//Print
int		ft_print_msg(atomic_int status, t_philo *p);

// Exec
void	*ft_routine(void *philo);
int		ft_is_dead(t_philo *p);

// Free and exit
int		ft_free_all(t_table *t);
void	ft_end_sim(t_table *t);

#endif
