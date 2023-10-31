/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gloms <rbrendle@student.42mulhouse.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 18:43:08 by gloms             #+#    #+#             */
/*   Updated: 2023/10/30 17:46:53 by gloms            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <libc.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <time.h>
# include <unistd.h>

/*-------------STRUCTS-------------*/

typedef struct s_gestion
{
	int					start_time;
	int					number_of_philosophers;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					number_of_meals;
}						t_gestion;

typedef struct s_philo
{
	int					whoami;
	int					amidead;
	int					meals_eaten;
	pthread_mutex_t		fork;
	struct s_gestion	*monitor;
	struct s_philo		*next;
}						t_philo;

/*--------------TEMPO--------------*/

void					randomize(int *valeur, int seed);

/*--------------UTILS--------------*/

int						ft_atoi(char *str);
int						ft_strlen(char *s);
t_philo					*ft_lstnew(int who_is_he);
t_philo					*ft_lstadd_back(t_philo *philo, int who_is_he);
void					do_circular_list(t_philo *philo);

/*-------------PARSING-------------*/

int						error_handler(char **av);
void					help_input(void);

/*--------------TIME--------------*/

int						get_time(void);
int						time_since_start(t_gestion *monitor);
int						death_check(t_philo *philo, t_gestion *monitor);

#endif
