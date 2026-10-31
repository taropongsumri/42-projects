/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ponsumri <chocodeveloper020@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 10:21:15 by ponsumri          #+#    #+#             */
/*   Updated: 2026/10/31 12:44:11 by ponsumri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Adaptive regimes (thresholds fixed by the subject):
**   disorder <  0.2 : insertion sort, cost ~ inversions, cheap when
**                     the input is nearly sorted         -> O(n^2)
**   disorder <  0.5 : chunk sort                         -> O(n sqrt n)
**   disorder >= 0.5 : radix sort, cost independent of order -> O(n log n)
*/

static int	ft_pick_regime(t_ps *ps)
{
	if (ps->strategy != S_ADAPTIVE)
		return (ps->strategy);
	if (ps->disorder < 0.2)
		return (S_SIMPLE);
	if (ps->disorder < 0.5)
		return (S_MEDIUM);
	return (S_COMPLEX);
}

/*
** Adaptive also has a constant-size base case: for n <= 5 every class is
** O(1), so it uses the hand-tuned small sort (<= 12 ops for 5 values).
*/

void	ft_sort(t_ps *ps)
{
	ps->regime = ft_pick_regime(ps);
	if (ft_is_sorted(ps->a))
		return ;
	if (ps->strategy == S_ADAPTIVE && ft_stack_size(ps->a) <= 5)
		ft_sort_small(ps);
	else if (ps->regime == S_SIMPLE)
		ft_sort_simple(ps);
	else if (ps->regime == S_MEDIUM)
		ft_sort_medium(ps);
	else
		ft_sort_complex(ps);
}
