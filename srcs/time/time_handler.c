/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gloms <rbrendle@student.42mulhouse.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 20:35:12 by gloms             #+#    #+#             */
/*   Updated: 2023/11/03 18:56:52 by gloms            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

long long int	get_time(void)
{
	static struct timeval	t;

	gettimeofday(&t, NULL);
	return ((t.tv_sec * 1000) + (t.tv_usec / 1000));
}

long long int	actual_time(t_gestion *monitor)
{
	return (get_time() - monitor->start_time);
}

void	ft_sleep(int t_eat, t_gestion *monitor)
{
	long long int	first_time;
	long long int	end_time;

	first_time = actual_time(monitor);
	end_time = first_time + t_eat;
	while (actual_time(monitor) < end_time)
		;
}
