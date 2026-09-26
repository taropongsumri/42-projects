#include "../src/push_swap.h"

void	pa(t_ps_node **a, t_ps_node **b)
{
	if (push(b, a))
		ft_printf("pa\n");
}

void	pb(t_ps_node **a, t_ps_node **b)
{
	if (push(a, b))
		ft_printf("pb\n");
}