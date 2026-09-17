/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_join_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ponsumri <ponsumri@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/17 20:13:23 by ponsumri          #+#    #+#             */
/*   Updated: 2026/09/17 20:13:23 by ponsumri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/push_swap.c"

static int	ft_join_len(int argc, char **argv)
{
	int	total_len;
	int	i;

	total_len = 0;
	i = 1;
	while (i < argc)
	{
		total_len += ft_strlen(argv[i]);
		if (i < argc - 1)
			total_len++;
		i++;
	}
	return (total_len);
}

char	*ft_join_args(int argc, char **argv)
{
	char	*result;
	int		i;
	int		j;
	int		pos;

	result = malloc(sizeof(char) * (ft_join_len(argc, argv) + 1));
	if (result == NULL)
		return (NULL);
	pos = 0;
	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j] != '\0')
			result[pos++] = argv[i][j++];
		if (i < argc - 1)
			result[pos++] = ' ';
		i++;
	}
	result[pos] = '\0';
	return (result);
}