/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ponsumri <ponsumri@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/17 19:30:05 by ponsumri          #+#    #+#             */
/*   Updated: 2026/09/17 19:30:05 by ponsumri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/push_swap.h"

void	sa(t_ps *ps)
{
	if (swap(&ps->a))
		ft_log_op(ps, OP_SA, "sa");
}

void	sb(t_ps *ps)
{
	if (swap(&ps->b))
		ft_log_op(ps, OP_SB, "sb");
}

void	ss(t_ps *ps)
{
	int	done;

	done = 0;
	done += swap(&ps->a);
	done += swap(&ps->b);
	if (done)
		ft_log_op(ps, OP_SS, "ss");
}
