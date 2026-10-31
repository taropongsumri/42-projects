/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ponsumri <chocodeveloper020@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 10:21:15 by ponsumri          #+#    #+#             */
/*   Updated: 2026/10/31 12:44:11 by ponsumri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Bring the node at position pos to the top using the cheaper direction:
** pos rotations from the top, or (size - pos) reverse rotations.
*/

void	ft_rotate_a_to(t_ps *ps, int pos)
{
	int	size;

	size = ft_stack_size(ps->a);
	if (pos <= size / 2)
		while (pos-- > 0)
			ra(ps);
	else
		while (pos++ < size)
			rra(ps);
}

void	ft_rotate_b_to(t_ps *ps, int pos)
{
	int	size;

	size = ft_stack_size(ps->b);
	if (pos <= size / 2)
		while (pos-- > 0)
			rb(ps);
	else
		while (pos++ < size)
			rrb(ps);
}
