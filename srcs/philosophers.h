/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gloms <rbrendle@student.42mulhouse.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 18:43:08 by gloms             #+#    #+#             */
/*   Updated: 2023/10/17 19:30:29 by gloms            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <unistd.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>

		/*-------------STRUCTS-------------*/

typedef	struct	s_gestion
{
	int	number_of_philosophers;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	Number_of_meals;
}				t_gestion;

typedef	struct	s_philo
{
	int whoami;
	pthread_t fork;
	pthread_t meals_eaten;
	struct s_philo *next;
}				t_philo;

		/*--------------UTILS--------------*/

int		ft_atoi(char *str);
int		ft_strlen(char *s);
t_philo *ft_lstnew(int who_is_he);
t_philo	*ft_lstadd_back(t_philo *philo, int who_is_he);
void	do_circular_list(t_philo *philo);

		/*-------------PARSING-------------*/

int		error_handler(char **av);
void	help_input(void);

#endif
