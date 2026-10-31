/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_node.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ponsumri <chocodeveloper020@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/17 19:30:05 by ponsumri          #+#    #+#             */
/*   Updated: 2026/10/31 12:44:11 by ponsumri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_ps_node	*ft_new_node(int nb)
{
	t_ps_node	*node;

	node = (t_ps_node *)malloc(sizeof(t_ps_node));
	if (!node)
		return (NULL);
	node->nb = nb;
	node->index = -1;
	node->next = node;
	node->prev = node;
	return (node);
}

void	ft_add_bottom(t_ps_node **stack, t_ps_node *node)
{
	t_ps_node	*last;

	if (!stack || !node)
		return ;
	if (!*stack)
	{
		*stack = node;
		return ;
	}
	last = (*stack)->prev;
	last->next = node;
	node->prev = last;
	node->next = *stack;
	(*stack)->prev = node;
}

void	ft_free_stack(t_ps_node **stack)
{
	t_ps_node	*cur;
	t_ps_node	*nxt;

	if (!stack || !*stack)
		return ;
	(*stack)->prev->next = NULL;
	cur = *stack;
	while (cur)
	{
		nxt = cur->next;
		free(cur);
		cur = nxt;
	}
	*stack = NULL;
}
