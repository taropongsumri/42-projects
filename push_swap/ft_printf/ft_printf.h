/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ponsumri <chocodeveloper020@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/03 14:03:36 by ponsumri          #+#    #+#             */
/*   Updated: 2026/09/05 15:37:47 by ponsumri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *format, ...);
int		ft_out(char *s, size_t len, int *total);
void	ft_putchar_print(char c, int *total);
void	ft_putstr_print(char *s, int *total);
void	ft_putnbr_print(int n, int *total);
void	ft_putptr_print(void *ptr, int *total);
void	ft_putunbr_print(unsigned int n, int *total);
void	ft_puthex_print(unsigned long n, int *total, char *base);
size_t	ft_strlen(const char *s);

#endif
