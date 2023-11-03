/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gloms <rbrendle@student.42mulhouse.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 21:51:23 by gloms             #+#    #+#             */
/*   Updated: 2023/11/03 23:09:35 by gloms            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	do_i_start(t_philo *philo)
{
	while (1)
	{
		pthread_mutex_lock(&philo->monitor->start_time_mutex);
		if (philo->monitor->start_time != -1)
		{
			pthread_mutex_unlock(&philo->monitor->start_time_mutex);
			break ;
		}
		pthread_mutex_unlock(&philo->monitor->start_time_mutex);
		usleep(100);
	}
	if (philo->whoami % 2 != 0)
		ft_sleep(philo->monitor->time_to_eat, philo->monitor);
}

int	philo_eating(t_philo *philo)
{
	pthread_mutex_lock(&philo->fork);
	if (philo->monitor->dead != 1)
		printf("%lld %d has taken a fork\n", actual_time(philo->monitor),
			philo->whoami);
	pthread_mutex_lock(&philo->next->fork);
	if (philo->monitor->dead != 1)
		printf("%lld %d has taken a fork\n", actual_time(philo->monitor),
			philo->whoami);
	ft_sleep(philo->monitor->time_to_eat, philo->monitor);
	if (actual_time(philo->monitor)
		- philo->last_meal_time > philo->monitor->time_to_die)
	{
		philo->amidead = 1;
		pthread_mutex_lock(&philo->monitor->deadd);
		philo->monitor->dead = 1;
		printf("%lld %d died\n", actual_time(philo->monitor),
			philo->whoami);
		pthread_mutex_unlock(&philo->fork);
		return (1);
	}
	philo->last_meal_time = actual_time(philo->monitor);
	pthread_mutex_unlock(&philo->next->fork);
	pthread_mutex_unlock(&philo->fork);
	return (0);
}

void	philo_sleep(t_philo *philo)
{	
	if (philo->monitor->dead != 1)
		printf("%lld %d is sleeping\n", actual_time(philo->monitor),
			philo->whoami);
	ft_sleep(philo->monitor->time_to_sleep, philo->monitor);
}

void	philo_think(t_philo *philo)
{
	if (philo->monitor->dead != 1)
		printf("%lld %d is thinking\n", actual_time(philo->monitor),
			philo->whoami);
}

void	*philo_routine(void *param)
{
	t_philo	*philo;

	philo = param;
	do_i_start(philo);
	while (philo->amidead != 1)
	{
		if(philo_eating(philo))
			return (NULL);
		philo_sleep(philo);
		philo_think(philo);
	}
	return (NULL);
}
