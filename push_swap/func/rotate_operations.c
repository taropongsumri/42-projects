/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ponsumri <ponsumri@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/17 19:30:05 by ponsumri          #+#    #+#             */
/*   Updated: 2026/09/17 19:30:05 by ponsumri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/push_swap.h"

void	ra(t_ps *ps)
{
	if (rotate(&ps->a))
		ft_log_op(ps, OP_RA, "ra");
}

void	rb(t_ps *ps)
{
	if (rotate(&ps->b))
		ft_log_op(ps, OP_RB, "rb");
}

void	rr(t_ps *ps)
{
	int	done;

	done = 0;
	done += rotate(&ps->a);
	done += rotate(&ps->b);
	if (done)
		ft_log_op(ps, OP_RR, "rr");
}
