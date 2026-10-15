/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_operations.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ponsumri <ponsumri@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/17 19:30:05 by ponsumri          #+#    #+#             */
/*   Updated: 2026/09/17 19:30:05 by ponsumri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/push_swap.h"

void	rra(t_ps *ps)
{
	if (reverse_rotate(&ps->a))
		ft_log_op(ps, OP_RRA, "rra");
}

void	rrb(t_ps *ps)
{
	if (reverse_rotate(&ps->b))
		ft_log_op(ps, OP_RRB, "rrb");
}

void	rrr(t_ps *ps)
{
	int	done;

	done = 0;
	done += reverse_rotate(&ps->a);
	done += reverse_rotate(&ps->b);
	if (done)
		ft_log_op(ps, OP_RRR, "rrr");
}
