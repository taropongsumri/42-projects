/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_simple.c                                   :+:      :+:    :+:   */
/*                                                      +:+ +:+         +:+   */
/*   By: ponsumri <ponsumri@student.42bangkok.com>       +#+  +:+       +#+   */
/*                                                        +#+#+#+#+#+   +#+   */
/*   Created: 2026/10/15 10:21:15 by ponsumri                    #+#    #+#   */
/*   Updated: 2026/10/15 10:21:15 by ponsumri             ###   ########.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../src/push_swap.h"

/*
** Insertion target in b. b is kept as a descending ring, so nb must
** land just above the biggest value smaller than it. If nb is the
** new minimum it goes above the max (the ring "wraps" there).
*/

static int	ft_insert_pos(t_ps_node *b, int nb)
{
	t_ps_node	*cur;
	t_ps_node	*best;

	best = NULL;
	cur = b;
	while (1)
	{
		if (cur->nb < nb && (!best || cur->nb > best->nb))
			best = cur;
		cur = cur->next;
		if (cur == b)
			break ;
	}
	if (!best)
		best = ft_find_max(b);
	return (ft_get_pos(b, best));
}

/*
** Simple O(n^2): insertion sort into b.
** Each top of a is inserted at its place in b (shortest rotation), then
** b is turned so its max is on top and everything is pushed back.
** Cost per element = distance to its slot <= n/2, so O(n^2) worst case,
** but on almost-sorted input the slot is next to the top: ~O(n).
*/

void	ft_sort_simple(t_ps *ps)
{
	if (ft_stack_size(ps->a) <= 3)
	{
		ft_sort_three(ps);
		return ;
	}
	while (ps->a)
	{
		if (ps->b)
			ft_rotate_b_to(ps, ft_insert_pos(ps->b, ps->a->nb));
		pb(ps);
	}
	ft_rotate_b_to(ps, ft_get_pos(ps->b, ft_find_max(ps->b)));
	while (ps->b)
		pa(ps);
}
