#ifndef PHILO_H
# define PHILO_H

# include <unistd.h> //NULL
# include <pthread.h>
# include <stdio.h>
# include <sys/time.h> //gettimeofday
# include <stdlib.h> //exit

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

typedef struct s_table  t_table;

typedef struct s_philo {
    size_t          id;
    pthread_t       thread;
    size_t          last_meal_time;
    pthread_mutex_t meal_mutex;
    size_t          meal_nbr;
    pthread_mutex_t *right_fork;
    pthread_mutex_t *left_fork;
    t_table         *t;
}   t_philo;

typedef struct s_table {
    //int             status;
    size_t          start_time;
    size_t          philo_nbr;
    size_t          time_to_die;
    size_t          time_to_sleep;
    size_t          time_to_eat;
    size_t          time_philo_must_eat;
    size_t          total_meals_nbr;
    pthread_mutex_t meal_mutex;;
    pthread_mutex_t death;
    pthread_mutex_t msg;
    pthread_mutex_t *forks;
    t_philo         *philos;
}   t_table;

// Parsing
int ft_check_args(int argc, char **argv);

// Initialisation
int ft_init_table(char **argv, t_table *t);
int	ft_atoi(const char *str);
int ft_init_mutex(t_table *t);
int ft_init_philos(t_table *table);

// Free
int    ft_free_all(t_table *t);

// Error
int ft_print_error(int error_code);

// Time
void ft_usleep(size_t time);

//Print
void	ft_print_msg(int status, t_philo *p);
void    ft_print_dead(t_philo *p, size_t time);


void    *ft_routine(void *philo);
size_t  ft_get_time_mil();
void    ft_join_threads(t_table *t);
void    ft_destroy_mutex(t_table *t);


void    ft_destroy_mutex(t_table *t);
void	ft_end_sim(t_table *t);
int    ft_parsing_error(int error_code);
int   ft_is_dead(t_philo *p);
#endif