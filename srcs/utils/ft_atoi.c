/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gloms <rbrendle@student.42mulhouse.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 12:53:19 by gloms             #+#    #+#             */
/*   Updated: 2023/10/13 16:17:54 by gloms            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

int	is_number(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_atoi(char *str)
{
	int	i;
	int	rtn;

	i = 0;
	rtn = 0;
	while (str[i])
	{
		if (!is_number(str[i]))
		{
			printf("\n ERROR : positive numbers only\n");
			return (-1);
		}
		rtn = rtn * 10 + str[i] - 48;
		i++;
	}
	if (rtn <= 0)
		printf("\n Error : positive numbers only\n");
	return (rtn);
}
