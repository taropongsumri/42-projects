/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ponsumri <ponsumri@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/17 19:26:33 by ponsumri          #+#    #+#             */
/*   Updated: 2026/09/17 19:26:33 by ponsumri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/push_swap.h"

void	ft_error(char *c)
{
	write(2, c, ft_strlen(c));
	write(2, "\n", 1);
	exit(1);
}

void	ft_free_split(char **words)
{
	int	i;

	if (!words)
		return ;
	i = 0;
	while (words[i])
		free(words[i++]);
	free(words);
}

void	ft_ps_free(t_ps *ps)
{
	ft_free_stack(&ps->a);
	ft_free_stack(&ps->b);
}

/* Single exit door for every parse error: free everything, then "Error" */

void	ft_ps_error(t_ps *ps, char **words)
{
	ft_free_split(words);
	ft_ps_free(ps);
	ft_error("Error");
}
