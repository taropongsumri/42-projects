#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <limits.h>
# include <stdlib.h>

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

int		ft_isdigit(int c);
void	ft_clear_args(int argc, char **argv);
char	**ft_split(char const *s, char c);
int		ft_isnum(char *num);
int		ft_collect(int num, char **argv, int i);
int		ft_atoi(const char *nptr);
void	ft_error(char *c);
char 	*ft_join_args(argc, argv);

int		swap(t_ps_node **s);
int		push(t_ps_node **get, t_ps_node **push);
int		rotate(t_ps_node **stack);
int		reverse_rotate(t_ps_node **stack);

void	sa(t_ps_node **a);
void	sb(t_ps_node **b);
void	ss(t_ps_node **a, t_ps_node **b);
void	pa(t_ps_node **a, t_ps_node **b);
void	pb(t_ps_node **a, t_ps_node **b);
void	ra(t_ps_node **a);
void	rb(t_ps_node **b);
void	rr(t_ps_node **a, t_ps_node **b);
void	rra(t_ps_node **a);
void	rrb(t_ps_node **b);
void	rrr(t_ps_node **a, t_ps_node **b);

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