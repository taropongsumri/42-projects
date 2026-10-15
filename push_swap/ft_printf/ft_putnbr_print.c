/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_print.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ponsumri <chocodeveloper020@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 12:29:00 by ponsumri          #+#    #+#             */
/*   Updated: 2026/09/04 17:40:14 by ponsumri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_print(int n, int *total)
{
	char	c;

	if (n == -2147483648)
	{
		ft_out("-2147483648", 11, total);
		return ;
	}
	if (n < 0)
	{
		ft_out("-", 1, total);
		n = -n;
	}
	if (n >= 10)
		ft_putnbr_print(n / 10, total);
	c = n % 10 + '0';
	ft_out(&c, 1, total);
}
