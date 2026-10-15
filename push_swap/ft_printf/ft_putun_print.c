/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putun_print.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ponsumri <chocodeveloper020@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/04 01:06:08 by ponsumri          #+#    #+#             */
/*   Updated: 2026/09/04 11:00:30 by ponsumri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putunbr_print(unsigned int n, int *total)
{
	char	c;

	if (n >= 10)
		ft_putunbr_print(n / 10, total);
	c = n % 10 + '0';
	ft_out(&c, 1, total);
}
