/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_core.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ponsumri <chocodeveloper020@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/17 19:30:05 by ponsumri          #+#    #+#             */
/*   Updated: 2026/10/31 12:42:47 by ponsumri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_ps_node	*ft_unlink_top(t_ps_node **src)
{
	t_ps_node	*node;

	node = *src;
	if (node->next == node)
		*src = NULL;
	else
	{
		node->prev->next = node->next;
		node->next->prev = node->prev;
		*src = node->next;
	}
	return (node);
}

static void	ft_link_top(t_ps_node **dst, t_ps_node *node)
{
	t_ps_node	*last;

	if (!*dst)
	{
		node->next = node;
		node->prev = node;
	}
	else
	{
		last = (*dst)->prev;
		node->next = *dst;
		node->prev = last;
		last->next = node;
		(*dst)->prev = node;
	}
	*dst = node;
}

int	push(t_ps_node **src, t_ps_node **dst)
{
	if (!src || !dst || !*src)
		return (0);
	ft_link_top(dst, ft_unlink_top(src));
	return (1);
}
