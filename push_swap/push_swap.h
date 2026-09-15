#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h>

typedef struct s_ps_node
{
	int					nb;
	struct s_ps_node	*next;
	struct s_ps_node	*prev;
}	t_ps_node;

typedef struct s_stack
{
	t_ps_node	*top;
	int			size;
}	t_stack;

int        ft_isdigit(int c);
// void    sa(t_stack **a, int print);
// void    sb(t_stack **b, int print);
// void    ss(t_stack **a, t_stack **b, int print);
// void    pa(t_stack **a, t_stack **b, int print);
// void    pb(t_stack **a, t_stack **b, int print);
// void    ra(t_stack **a, int print);
// void    rb(t_stack **b, int print);
// void    rr(t_stack **a, t_stack **b, int print);
// void    rra(t_stack **a, int print);
// void    rrb(t_stack **b, int print);
// void    rrr(t_stack **a, t_stack **b, int print);

#endif