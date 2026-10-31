/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_index.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ponsumri <chocodeveloper020@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/17 19:30:05 by ponsumri          #+#    #+#             */
/*   Updated: 2026/10/31 12:44:11 by ponsumri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** The rank of a value is simply how many nodes hold something
** smaller. No allocation and no second list to keep in sync.
*/

static int	ft_rank_of(t_ps_node *s, int n, int nb)
{
	int	rank;
	int	i;

	rank = 0;
	i = 0;
	while (i < n)
	{
		if (s->nb < nb)
			rank++;
		s = s->next;
		i++;
	}
	return (rank);
}

void	ft_index_stack(t_ps_node *s)
{
	t_ps_node	*cur;
	int			n;
	int			i;

	if (!s)
		return ;
	n = ft_stack_size(s);
	cur = s;
	i = 0;
	while (i < n)
	{
		cur->index = ft_rank_of(s, n, cur->nb);
		cur = cur->next;
		i++;
	}
}
