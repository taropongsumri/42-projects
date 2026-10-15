/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ponsumri <ponsumri@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/17 19:30:05 by ponsumri          #+#    #+#             */
/*   Updated: 2026/09/17 19:30:05 by ponsumri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/push_swap.h"

/*
** The list is circular: last->next == first and first->prev == last.
** An empty stack is NULL, a single node is self-linked (n->next == n).
*/

int	swap(t_ps_node **s)
{
	t_ps_node	*first;
	t_ps_node	*sec;
	t_ps_node	*last;
	t_ps_node	*third;

	if (!s || !*s || (*s)->next == *s)
		return (0);
	first = *s;
	sec = first->next;
	if (sec->next == first)
	{
		*s = sec;
		return (1);
	}
	last = first->prev;
	third = sec->next;
	last->next = sec;
	sec->prev = last;
	sec->next = first;
	first->prev = sec;
	first->next = third;
	third->prev = first;
	*s = sec;
	return (1);
}

int	rotate(t_ps_node **stack)
{
	if (!stack || !*stack || (*stack)->next == *stack)
		return (0);
	*stack = (*stack)->next;
	return (1);
}

int	reverse_rotate(t_ps_node **stack)
{
	if (!stack || !*stack || (*stack)->next == *stack)
		return (0);
	*stack = (*stack)->prev;
	return (1);
}

/*
** Every printed operation goes through here, so --bench counts are
** always exactly what was written to stdout.
*/

void	ft_log_op(t_ps *ps, int op, char *name)
{
	ps->ops[op]++;
	ft_printf("%s\n", name);
}
