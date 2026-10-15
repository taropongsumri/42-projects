/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ponsumri <chocodeveloper020@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/03 17:31:32 by ponsumri          #+#    #+#             */
/*   Updated: 2026/09/05 17:25:48 by ponsumri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_format(char thing, va_list *args, int *total)
{
	if (thing == 'c')
		ft_putchar_print(va_arg(*args, int), total);
	else if (thing == 's')
		ft_putstr_print(va_arg(*args, char *), total);
	else if (thing == 'p')
		ft_putptr_print(va_arg(*args, void *), total);
	else if (thing == 'd' || thing == 'i')
		ft_putnbr_print(va_arg(*args, int), total);
	else if (thing == 'u')
		ft_putunbr_print(va_arg(*args, unsigned int), total);
	else if (thing == 'x')
		ft_puthex_print(va_arg(*args, unsigned int), total, "0123456789abcdef");
	else if (thing == 'X')
		ft_puthex_print(va_arg(*args, unsigned int), total, "0123456789ABCDEF");
	else if (thing == '%')
		ft_putchar_print('%', total);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		total;

	if (!format)
		return (-1);
	total = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			if (!*(format + 1))
			{
				total = -1;
				break ;
			}
			format++;
			ft_format(*format, &args, &total);
		}
		else
			ft_putchar_print(*format, &total);
		format++;
	}
	va_end(args);
	return (total);
}
