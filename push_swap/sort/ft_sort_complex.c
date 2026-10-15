/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_complex.c                                  :+:      :+:    :+:   */
/*                                                      +:+ +:+         +:+   */
/*   By: ponsumri <ponsumri@student.42bangkok.com>       +#+  +:+       +#+   */
/*                                                        +#+#+#+#+#+   +#+   */
/*   Created: 2026/10/15 10:21:15 by ponsumri                    #+#    #+#   */
/*   Updated: 2026/10/15 10:21:15 by ponsumri             ###   ########.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../src/push_swap.h"

/*
** Complex O(n log n): LSD binary radix sort on the indexes (0 .. n-1).
** For each bit (low to high): elements with bit 0 go to b, bit 1 stay
** in a (ra), then everything comes back. Each pass keeps the order of
** previous bits stable, so after log2(n) passes a is sorted.
** Ops: log2(n) passes * (n + 2 * zeros) <= 3n log2(n).
*/

static int	ft_max_bits(int n)
{
	int	bits;

	bits = 0;
	while (((n - 1) >> bits) != 0)
		bits++;
	return (bits);
}

void	ft_sort_complex(t_ps *ps)
{
	int	n;
	int	bits;
	int	bit;
	int	j;

	n = ft_stack_size(ps->a);
	bits = ft_max_bits(n);
	bit = 0;
	while (bit < bits && !ft_is_sorted(ps->a))
	{
		j = 0;
		while (j++ < n)
		{
			if ((ps->a->index >> bit) & 1)
				ra(ps);
			else
				pb(ps);
		}
		while (ps->b)
			pa(ps);
		bit++;
	}
}
