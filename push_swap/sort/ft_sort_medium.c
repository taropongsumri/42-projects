/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_medium.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ponsumri <chocodeveloper020@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 10:21:15 by ponsumri          #+#    #+#             */
/*   Updated: 2026/10/31 12:44:11 by ponsumri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_sqrt(int n)
{
	int	r;

	r = 0;
	while ((r + 1) * (r + 1) <= n)
		r++;
	return (r);
}

/*
** Phase 1, sliding window of width range ~ 1.5 * sqrt(n) over the indexes.
** i = how many elements are already in b.
**   index <= i          : old/small -> pb then rb (sink to b's bottom)
**   index <= i + range  : in window -> pb (stay on b's top)
**   otherwise           : not yet   -> ra
** Each full pass of a pushes at least `range` elements, so there are
** <= n / range passes of <= n rotations: O(n * sqrt(n)).
*/

static void	ft_push_chunks(t_ps *ps)
{
	int	range;
	int	i;

	range = ft_sqrt(ft_stack_size(ps->a)) * 3 / 2;
	i = 0;
	while (ps->a)
	{
		if (ps->a->index <= i)
		{
			pb(ps);
			rb(ps);
			i++;
		}
		else if (ps->a->index <= i + range)
		{
			pb(ps);
			i++;
		}
		else
			ra(ps);
	}
}

/*
** Phase 2: b is now roughly ordered, big values near the top/bottom,
** so the max is always within ~range of an end. Bring it up, pa.
*/

void	ft_sort_medium(t_ps *ps)
{
	if (ft_stack_size(ps->a) <= 3)
	{
		ft_sort_three(ps);
		return ;
	}
	ft_push_chunks(ps);
	while (ps->b)
	{
		ft_rotate_b_to(ps, ft_get_pos(ps->b, ft_find_max(ps->b)));
		pa(ps);
	}
}
