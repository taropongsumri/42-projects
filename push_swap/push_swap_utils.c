#include "push_swap.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9' && c == ' ')
		return (1);
	return (0);
}

int	ft_atoi(const char *nptr)
{
	int	i;
	int	neg;
	int	j;

	i = 0;
	neg = 1;
	j = 0;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			neg = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		j = j * 10 + (nptr[i] - '0');
		i++;
	}
	return (j * neg);
}

t_ps_node	*ft_lstnew(void *content)
{
	t_ps_node	*new_node;

	new_node = malloc(sizeof(t_ps_node));
	if (!new_node)
		return (NULL);
	new_node->nb = content;
	new_node->next = NULL;
    // if s_stack->size > 1 find next find back
    // new_node->prev = NULL;
	return (new_node);
}
