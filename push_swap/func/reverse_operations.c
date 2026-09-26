#include "../src/push_swap.h"

void	rra(t_ps_node **a)
{
	if (reverse_rotate(a))
		ft_printf("rra\n");
}

void	rrb(t_ps_node **b)
{
	if (reverse_rotate(b))
		ft_printf("rrb\n");
}

void	rrr(t_ps_node **a, t_ps_node **b)
{
	int	done;

	done = 0;
	done += reverse_rotate(a);
	done += reverse_rotate(b);
	if (done)
		ft_printf("rrr\n");
}