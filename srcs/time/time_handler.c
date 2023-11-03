/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gloms <rbrendle@student.42mulhouse.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 20:35:12 by gloms             #+#    #+#             */
/*   Updated: 2023/10/30 17:47:22 by gloms            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

int	get_time(void)
{
	static struct timeval	t;

	gettimeofday(&t, NULL);
	return ((t.tv_sec * 1000) + (t.tv_usec / 1000));
}

int	time_since_start(t_gestion *monitor)
{
	return (get_time() - monitor->start_time);
}

void	ft_sleep(int t_eat)
{
	long long int	first_time;
	long long int	end_time;

	first_time = actual_time();
	end_time = first_time + t_eat;
	while (actual_time() < end_time)
		;
}
