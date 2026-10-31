/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ponsumri <chocodeveloper020@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/17 19:30:05 by ponsumri          #+#    #+#             */
/*   Updated: 2026/10/31 12:44:11 by ponsumri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_stack_size(t_ps_node *s)
{
	t_ps_node	*cur;
	int			n;

	if (!s)
		return (0);
	n = 1;
	cur = s->next;
	while (cur != s)
	{
		n++;
		cur = cur->next;
	}
	return (n);
}

/*
** Compares n - 1 adjacent pairs only. The wrap edge (bottom -> top)
** always runs high -> low in a sorted ring, so testing it would
** report every sorted stack as unsorted.
*/

int	ft_is_sorted(t_ps_node *s)
{
	int	n;
	int	i;

	n = ft_stack_size(s);
	if (n < 2)
		return (1);
	i = 0;
	while (i < n - 1)
	{
		if (s->nb > s->next->nb)
			return (0);
		s = s->next;
		i++;
	}
	return (1);
}

t_ps_node	*ft_find_min(t_ps_node *s)
{
	t_ps_node	*min;
	t_ps_node	*cur;

	if (!s)
		return (NULL);
	min = s;
	cur = s->next;
	while (cur != s)
	{
		if (cur->nb < min->nb)
			min = cur;
		cur = cur->next;
	}
	return (min);
}

t_ps_node	*ft_find_max(t_ps_node *s)
{
	t_ps_node	*max;
	t_ps_node	*cur;

	if (!s)
		return (NULL);
	max = s;
	cur = s->next;
	while (cur != s)
	{
		if (cur->nb > max->nb)
			max = cur;
		cur = cur->next;
	}
	return (max);
}

int	ft_get_pos(t_ps_node *s, t_ps_node *node)
{
	t_ps_node	*cur;
	int			pos;

	if (!s || !node)
		return (-1);
	if (s == node)
		return (0);
	cur = s->next;
	pos = 1;
	while (cur != s)
	{
		if (cur == node)
			return (pos);
		cur = cur->next;
		pos++;
	}
	return (-1);
}
