/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gloms <rbrendle@student.42mulhouse.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 13:05:12 by gloms             #+#    #+#             */
/*   Updated: 2023/10/27 17:49:47 by gloms            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*philo_routine(void *param)
{
	t_philo *philo;
	philo = param;
	usleep(100000);
	printf("hi ! i am %d !\n", philo->whoami);
	printf("%d", gettimeofday());
	return (NULL);
}

void	init_philos(t_philo *philo, char **av)
{
	int			i;
	pthread_t	*philo_threads;

	i = 0;
	philo_threads = malloc(sizeof(pthread_t) * ft_atoi(av[1]));
	while (++i < ft_atoi(av[1]))
		ft_lstadd_back(philo, i);
	do_circular_list(philo);
	i = 0;
	while (i < ft_atoi(av[1]))
	{
		pthread_create(&philo_threads[i], NULL, philo_routine, (void *)philo);
		pthread_join(philo_threads[i], NULL);
		philo = philo->next;
		i++;
	}
}

int	main(int ac, char **av)
{
	t_philo		*philo;

	philo = NULL;
	philo = ft_lstadd_back(philo, 0);
	if (!error_handler(av) || ac < 5 || ac > 6)
		return (help_input(), 1);
	init_philos(philo, av);
	return (0);
}
