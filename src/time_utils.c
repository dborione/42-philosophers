#include "../includes/philo.h"

size_t ft_get_time_mil(void)
{
	struct timeval tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void ft_usleep(size_t time)
{
	size_t start_time;

	start_time = ft_get_time_mil();
	while (ft_get_time_mil() < start_time + time)
		usleep(100);
}