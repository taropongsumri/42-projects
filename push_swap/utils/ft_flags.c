/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ponsumri <chocodeveloper020@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 10:21:15 by ponsumri          #+#    #+#             */
/*   Updated: 2026/10/31 12:44:11 by ponsumri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Two different strategy selectors (e.g. --simple --complex) is an error */

static void	ft_set_strategy(t_ps *ps, int strategy)
{
	if (ps->strategy != S_NONE && ps->strategy != strategy)
		ft_ps_error(ps, NULL);
	ps->strategy = strategy;
}

/* Returns 1 if arg was a flag (and applies it), 0 if it must be a number */

int	ft_apply_flag(t_ps *ps, char *arg)
{
	if (!ft_strcmp(arg, "--bench"))
		ps->bench = 1;
	else if (!ft_strcmp(arg, "--simple"))
		ft_set_strategy(ps, S_SIMPLE);
	else if (!ft_strcmp(arg, "--medium"))
		ft_set_strategy(ps, S_MEDIUM);
	else if (!ft_strcmp(arg, "--complex"))
		ft_set_strategy(ps, S_COMPLEX);
	else if (!ft_strcmp(arg, "--adaptive"))
		ft_set_strategy(ps, S_ADAPTIVE);
	else
		return (0);
	return (1);
}
