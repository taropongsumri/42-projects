/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_disorder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ponsumri <chocodeveloper020@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 10:21:15 by ponsumri          #+#    #+#             */
/*   Updated: 2026/10/31 12:44:11 by ponsumri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Subject formula: mistakes / total_pairs, where a mistake is a pair
** (i < j) with a[i] > a[j]. O(n^2) comparisons, no operations emitted.
** Must be called before any move.
*/

double	ft_disorder(t_ps_node *a)
{
	t_ps_node	*i;
	t_ps_node	*j;
	long		mistakes;
	long		pairs;

	if (!a || a->next == a)
		return (0.0);
	mistakes = 0;
	pairs = 0;
	i = a;
	while (i->next != a)
	{
		j = i->next;
		while (j != a)
		{
			pairs++;
			if (i->nb > j->nb)
				mistakes++;
			j = j->next;
		}
		i = i->next;
	}
	return ((double)mistakes / (double)pairs);
}
