/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gloms <rbrendle@student.42mulhouse.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 13:05:12 by gloms             #+#    #+#             */
/*   Updated: 2023/11/03 22:49:19 by gloms            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

// void	*philo_routine(void *param)
// {
// 	t_philo	*philo;
// 	int		i;
// 	int		j;

// 	j = 0;
// 	i = 0;
// philo = param;
// randomize(&i, philo->whoami);
// 	printf("%d\n", philo->monitor->start_time);
// 	while (philo->monitor->start_time == -1)
// 		;
// 	while (j != i)
// 	{
// 		usleep(800 * 1000);
// 		printf("%d %d is living his life\n", time_since_start(philo->monitor),
// 			philo->whoami);
// 		j++;
// 	}
// 	philo->amidead = 1;
// 	printf("i am %d an i am dead\n", philo->whoami);
// 	return (NULL);
// }

void	init_philos(t_philo *philo, t_gestion *monitor, char **av)
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
		philo->monitor = monitor;
		philo->last_meal_time = 0;
		philo->amidead = 0;
		pthread_create(&philo_threads[i], NULL, philo_routine, (void *)philo);
		philo = philo->next;
		i++;
	}
	//pthread_join(philo_threads[i], NULL);
}

void	init_monitor(t_gestion *monitor, char **av)
{
	monitor->start_time = -1;
	monitor->number_of_philosophers = ft_atoi(av[1]);
	monitor->time_to_die = ft_atoi(av[2]);
	monitor->time_to_eat = ft_atoi(av[3]);
	monitor->time_to_sleep = ft_atoi(av[3]);
	monitor->dead = 0;
	if (av[4])
		monitor->number_of_meals = ft_atoi(av[4]);
}

int	main(int ac, char **av)
{
	t_philo		*philo;
	t_gestion	*monitor;

	if (!error_handler(av) || ac < 5 || ac > 6)
		return (help_input(), 1);
	philo = NULL;
	philo = ft_lstadd_back(philo, 0);
	monitor = malloc(sizeof(t_gestion));
	init_monitor(monitor, av);
	init_philos(philo, monitor, av);
	death_check(philo, monitor);
	return (0);
}
