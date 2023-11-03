/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   health_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gloms <rbrendle@student.42mulhouse.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 19:22:01 by gloms             #+#    #+#             */
/*   Updated: 2023/11/03 23:09:16 by gloms            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

int	death_check(t_philo *philo, t_gestion *monitor)
{
	pthread_mutex_t	time_mutex;

	pthread_mutex_lock(&time_mutex);
	monitor->start_time = get_time();
	pthread_mutex_unlock(&time_mutex);
	while (1)
	{
		if (philo->monitor->dead)
			return (1);
	}
	return (1);
}
