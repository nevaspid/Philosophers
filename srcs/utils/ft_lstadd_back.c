/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gloms <rbrendle@student.42mulhouse.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 14:47:36 by gloms             #+#    #+#             */
/*   Updated: 2023/10/17 19:09:12 by gloms            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

t_philo	*ft_lstadd_back(t_philo *philo, int who_is_he)
{
	if (who_is_he == 0)
	{
		philo = ft_lstnew(who_is_he);
		return (philo);
	}
	while (philo->next)
		philo = philo->next;
	philo->next = ft_lstnew(who_is_he);
	return (0);
}
