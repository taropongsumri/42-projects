/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clear_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ponsumri <ponsumri@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/17 19:30:05 by ponsumri          #+#    #+#             */
/*   Updated: 2026/09/17 19:30:05 by ponsumri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/push_swap.h"

void	ft_clear_args(int argc, char **argv)
{
	char	*joined;
	char	**args;
	int		i;
	long	tmp;

	joined = ft_join_args(argc, argv);
	args = ft_split(joined, ' ');
	free(joined);
	i = 0;
	while (args[i])
	{
		if (!ft_isnum(args[i]))
			ft_error("Error");
		tmp = ft_atoi(args[i]);
		if (tmp < INT_MIN || tmp > INT_MAX)
			ft_error("Error");
		if (ft_contains(tmp, args, i))
			ft_error("Error");
		i++;
	}
}
