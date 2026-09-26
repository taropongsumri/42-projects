#include "../src/push_swap.h"

void	ra(t_ps_node **a)
{
	if (rotate(a))
		ft_printf("ra\n");
}

void	rb(t_ps_node **b)
{
	if (rotate(b))
		ft_printf("rb\n");
}

void	rr(t_ps_node **a, t_ps_node **b)
{
	int	done;

	done = 0;
	done += rotate(a);
	done += rotate(b);
	if (done)
		ft_printf("rr\n");
}