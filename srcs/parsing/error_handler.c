/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gloms <rbrendle@student.42mulhouse.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 13:07:32 by gloms             #+#    #+#             */
/*   Updated: 2023/10/13 16:08:50 by gloms            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	help_input(void)
{
	printf(" ____________________________________________________\n");
	printf("|                                                    |\n");
	printf("|         Please enter 4 or 5 valid arguments        |\n");
	printf("|____________________________________________________|\n");
	printf("|                                                    |\n");
	printf("|  [1][number_of_philosophers]                       |\n");
	printf("|  [2][time_to_die]                                  |\n");
	printf("|  [3][time_to_eat]                                  |\n");
	printf("|  [4][time_to_sleep]                                |\n");
	printf("|  [5][Number_of_meals]                              |\n");
	printf("|____________________________________________________|\n");
}

int	error_handler(char **av)
{
	int	i;

	i = 0;
	while (av[++i])
	{
		if (ft_atoi(av[i]) <= 0)
			return (0);
	}
	return (1);
}
