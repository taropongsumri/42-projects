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

/* One pass: bit 0 -> b, bit 1 -> stays in a (ra), then bring b back */

static void	ft_radix_pass(t_ps *ps, int n, int bit)
{
	int	j;

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
}

void	ft_sort_complex(t_ps *ps)
{
	int	n;
	int	bits;
	int	bit;

	n = ft_stack_size(ps->a);
	if (n <= 3)
	{
		ft_sort_three(ps);
		return ;
	}
	bits = ft_max_bits(n);
	bit = 0;
	while (bit < bits && !ft_is_sorted(ps->a))
		ft_radix_pass(ps, n, bit++);
}
