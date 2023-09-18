#include "../includes/philo.h"

static int    ft_print_parsing_error(int error_code)
{
    printf("Args must be:\n");
    printf(" number_of_philosophers time_to_die time_to_eat "); 
    printf("time_to_sleep [number_of_times_each_philosopher_must_eat]\n");
    printf("They also must be numbers superior to 0.\n");
    return (error_code);
}

int ft_print_error(int error_code)
{
    if (error_code == ERROR_PARSING)
        return (ft_print_parsing_error(error_code));
    if (error_code == ERROR_INIT_TABLE)
        printf("Error with table initialisation\n");
    if (error_code == ERROR_MUTEX)
        printf("Error with mutex initialisation\n");
    if (error_code == ERROR_INIT_PHILO)
        printf("Error with thread creation\n");   
    return (error_code);
}