/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putx_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ponsumri <chocodeveloper020@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/04 01:06:08 by ponsumri          #+#    #+#             */
/*   Updated: 2026/09/04 11:09:42 by ponsumri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_puthex_print(unsigned long n, int *total, char *base)
{
	char	c;

	if (n >= 16)
		ft_puthex_print(n / 16, total, base);
	c = base[n % 16];
	ft_out(&c, 1, total);
}
