/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_print.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ponsumri <chocodeveloper020@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 12:20:03 by ponsumri          #+#    #+#             */
/*   Updated: 2026/09/03 22:40:25 by ponsumri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr_print(char *s, int *total)
{
	if (!s)
		s = "(null)";
	ft_out(s, ft_strlen(s), total);
}
