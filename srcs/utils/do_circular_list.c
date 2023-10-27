/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_circular_list.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gloms <rbrendle@student.42mulhouse.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 19:27:50 by gloms             #+#    #+#             */
/*   Updated: 2023/10/17 19:29:25 by gloms            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	do_circular_list(t_philo *philo)
{
	t_philo	*first;

	first = philo;
	while (philo->next)
		philo = philo->next;
	philo->next = first;
}
