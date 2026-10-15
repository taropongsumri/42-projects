/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ponsumri <ponsumri@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/17 19:21:26 by ponsumri          #+#    #+#             */
/*   Updated: 2026/09/17 19:21:26 by ponsumri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/push_swap.h"

long	ft_atoi(const char *nptr)
{
	int		i;
	int		neg;
	long	j;

	i = 0;
	neg = 1;
	j = 0;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			neg = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		if (j > (LONG_MAX - (nptr[i] - '0')) / 10)
			return (neg * LONG_MAX);
		j = j * 10 + (nptr[i] - '0');
		i++;
	}
	return (j * neg);
}
