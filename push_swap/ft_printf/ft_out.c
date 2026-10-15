/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_out.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ponsumri <chocodeveloper020@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/04 11:45:00 by ponsumri          #+#    #+#             */
/*   Updated: 2026/09/04 11:45:00 by ponsumri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_out(char *s, size_t len, int *total)
{
	if (*total < 0)
		return (-1);
	if (write(1, s, len) < 0)
	{
		*total = -1;
		return (-1);
	}
	*total += (int)len;
	return (0);
}
