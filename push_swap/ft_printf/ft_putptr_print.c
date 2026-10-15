/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr_print.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ponsumri <chocodeveloper020@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/04 01:06:08 by ponsumri          #+#    #+#             */
/*   Updated: 2026/09/04 10:24:48 by ponsumri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putptr_print(void *ptr, int *total)
{
	if (!ptr)
	{
		ft_out("(nil)", 5, total);
		return ;
	}
	ft_out("0x", 2, total);
	ft_puthex_print((unsigned long)ptr, total, "0123456789abcdef");
}
