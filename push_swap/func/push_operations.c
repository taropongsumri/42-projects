/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ponsumri <ponsumri@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/17 19:30:05 by ponsumri          #+#    #+#             */
/*   Updated: 2026/09/17 19:30:05 by ponsumri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/push_swap.h"

void	pa(t_ps *ps)
{
	if (push(&ps->b, &ps->a))
		ft_log_op(ps, OP_PA, "pa");
}

void	pb(t_ps *ps)
{
	if (push(&ps->a, &ps->b))
		ft_log_op(ps, OP_PB, "pb");
}
