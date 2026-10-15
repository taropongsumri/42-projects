/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ponsumri <chocodeveloper020@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/17 19:30:05 by ponsumri          #+#    #+#             */
/*   Updated: 2026/10/14 17:43:50 by ponsumri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_ps_node	*stack_a;
	t_ps_node	*stack_b;

	if (argc < 2)
		return (0);
	stack_a = ft_parse_args(argc, argv);
	stack_b = NULL;
	if (ft_is_sorted(stack_a))
	{
		ft_free_stack(&stack_a);
		return (0);
	}
	ft_index_stack(stack_a);
	ft_free_stack(&stack_a);
	ft_free_stack(&stack_b);
	return (0);
}
