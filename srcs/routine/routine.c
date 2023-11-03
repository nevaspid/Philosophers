/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gloms <rbrendle@student.42mulhouse.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 21:51:23 by gloms             #+#    #+#             */
/*   Updated: 2023/11/03 16:45:10 by gloms            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

int	do_i_start(t_philo *philo)
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
}

void philo_eating(t_philo *philo)
{
	pthread_mutex_lock(&philo->fork);
	printf("%lld %d has taken a fork\n", time_since_start, philo->whoami);
	pthread_mutex_lock(&philo->next->fork);
	printf("%lld %d has taken a fork\n", time_since_start, philo->whoami);
	ft_sleep(philo->monitor->time_to_eat);
	pthread_mutex_unlock(&philo->next->fork);
	pthread_mutex_unlock(&philo->fork);
}

void philo_sleep(t_philo *philo)
{

}

void philo_think(t_philo *philo)
{

}

void	*philo_routine(void *param)
{
	t_philo	*philo;

	philo = param;

	do_i_start(philo);

	while (1)
	{
		philo_eating(philo);
		philo_sleep(philo);
		philo_think(philo);
	}
}
