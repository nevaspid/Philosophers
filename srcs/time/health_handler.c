/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   health_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gloms <rbrendle@student.42mulhouse.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 19:22:01 by gloms             #+#    #+#             */
/*   Updated: 2023/11/03 17:46:55 by gloms            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

int	death_check(t_philo *philo, t_gestion *monitor)
{
	monitor->start_time = get_time();
	while (philo->amidead == 0)
		philo = philo->next;
	return (1);
}
