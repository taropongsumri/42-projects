/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ponsumri <chocodeveloper020@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/17 19:30:05 by ponsumri          #+#    #+#             */
/*   Updated: 2026/10/15 13:09:53 by ponsumri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/push_swap.h"

// Prepare empty huge struct 
static void	ft_init_ps(t_ps *ps)
{
	int	i;

	ps->a = NULL;
	ps->b = NULL;
	ps->strategy = S_NONE;
	ps->regime = S_SIMPLE;
	ps->bench = 0;
	ps->disorder = 0.0;
	i = 0;
	while (i < OP_COUNT)
		ps->ops[i++] = 0;
}

int	main(int argc, char **argv)
{
	t_ps	ps;

	if (argc < 2)
		return (0);
	ft_init_ps(&ps);
	ft_parse_args(&ps, argc, argv);
	if (!ps.a)
		return (0);
	ps.disorder = ft_disorder(ps.a);
	ft_index_stack(ps.a);
	ft_sort(&ps);
	if (ps.bench)
		ft_print_bench(&ps);
	ft_ps_free(&ps);
	return (0);
}
