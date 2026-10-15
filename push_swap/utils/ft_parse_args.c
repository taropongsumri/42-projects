/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_args.c                                    :+:      :+:    :+:   */
/*                                                      +:+ +:+         +:+   */
/*   By: ponsumri <ponsumri@student.42bangkok.com>       +#+  +:+       +#+   */
/*                                                        +#+#+#+#+#+   +#+   */
/*   Created: 2026/10/15 10:21:15 by ponsumri                    #+#    #+#   */
/*   Updated: 2026/10/15 10:21:15 by ponsumri             ###   ########.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../src/push_swap.h"

static int	ft_has_value(t_ps_node *s, int nb)
{
	t_ps_node	*cur;

	if (!s)
		return (0);
	cur = s;
	while (1)
	{
		if (cur->nb == nb)
			return (1);
		cur = cur->next;
		if (cur == s)
			return (0);
	}
}

static void	ft_add_number(t_ps *ps, char **words, char *s)
{
	long		nb;
	t_ps_node	*node;

	nb = ft_atoi(s);
	if (!ft_isnum(s) || nb < INT_MIN || nb > INT_MAX
		|| ft_has_value(ps->a, (int)nb))
		ft_ps_error(ps, words);
	node = ft_new_node((int)nb);
	if (!node)
		ft_ps_error(ps, words);
	ft_add_bottom(&ps->a, node);
}

/*
** Each argv entry is split on its own, so "1 2" 3 works but an empty
** or blank argument ("" or "   ") is an error instead of vanishing.
*/

static void	ft_parse_word_list(t_ps *ps, char *arg)
{
	char	**words;
	int		i;

	words = ft_split(arg, ' ');
	if (!words)
		ft_ps_error(ps, NULL);
	if (!words[0])
		ft_ps_error(ps, words);
	i = 0;
	while (words[i])
		ft_add_number(ps, words, words[i++]);
	ft_free_split(words);
}

void	ft_parse_args(t_ps *ps, int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (!ft_apply_flag(ps, argv[i]))
			ft_parse_word_list(ps, argv[i]);
		i++;
	}
	if (ps->strategy == S_NONE)
		ps->strategy = S_ADAPTIVE;
}
