#include "../src/push_swap.h"

void	sa(t_ps_node **a)
{
	if (swap(a))
		ft_printf("sa\n");
}

void	sb(t_ps_node **b)
{
	if (swap(b))
		ft_printf("sb\n");
}

void	ss(t_ps_node **a, t_ps_node **b)
{
	int	done;

	done = 0;
	done += swap(a);
	done += swap(b);
	if (done)
		ft_printf("ss\n");
}
