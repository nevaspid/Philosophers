/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   health_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gloms <rbrendle@student.42mulhouse.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 19:22:01 by gloms             #+#    #+#             */
/*   Updated: 2023/10/30 14:25:44 by gloms            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

int	death_check(t_philo *philo, t_gestion *monitor)
{
	monitor->start_time = get_time();
	while (philo->amidead == 0)
		philo = philo->next;
	printf("philo %d is DEAD\n", philo->whoami);
	return (1);
}
