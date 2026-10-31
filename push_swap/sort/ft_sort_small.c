/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_small.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ponsumri <chocodeveloper020@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 10:21:15 by ponsumri          #+#    #+#             */
/*   Updated: 2026/10/31 12:44:11 by ponsumri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** 3 elements: put the max at the bottom (ra or rra), then fix the top
** two with sa. At most 2 operations.
*/

void	ft_sort_three(t_ps *ps)
{
	t_ps_node	*max;

	if (ft_is_sorted(ps->a))
		return ;
	if (ft_stack_size(ps->a) == 2)
	{
		sa(ps);
		return ;
	}
	max = ft_find_max(ps->a);
	if (ps->a == max)
		ra(ps);
	else if (ps->a->next == max)
		rra(ps);
	if (ps->a->nb > ps->a->next->nb)
		sa(ps);
}

/*
** 4-5 elements: push the minimums to b until 3 remain, sort those 3,
** push back. Everything in b is smaller than a, so pa keeps a sorted.
*/

void	ft_sort_small(t_ps *ps)
{
	while (ft_stack_size(ps->a) > 3 && !ft_is_sorted(ps->a))
	{
		ft_rotate_a_to(ps, ft_get_pos(ps->a, ft_find_min(ps->a)));
		pb(ps);
	}
	ft_sort_three(ps);
	while (ps->b)
		pa(ps);
}
