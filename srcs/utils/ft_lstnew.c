/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gloms <rbrendle@student.42mulhouse.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 14:58:49 by gloms             #+#    #+#             */
/*   Updated: 2023/10/17 15:31:37 by gloms            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

t_philo *ft_lstnew(int who_is_he)
{
	t_philo *philo;

	philo = malloc(sizeof(t_philo));
	philo->whoami = who_is_he;
	philo->meals_eaten = 0;
	philo->next = NULL;
	return (philo);
}
