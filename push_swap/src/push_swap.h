/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ponsumri <chocodeveloper020@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/17 19:30:05 by ponsumri          #+#    #+#             */
/*   Updated: 2026/10/15 13:08:06 by ponsumri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdlib.h>
# include <unistd.h>
# include "ft_printf.h"

/* Strategy ids: what the user asked for (strategy) / what ran (regime) */
# define S_NONE		-1
# define S_SIMPLE	0
# define S_MEDIUM	1
# define S_COMPLEX	2
# define S_ADAPTIVE	3

/* Operation ids, used as indexes into t_ps.ops for --bench */
# define OP_SA		0
# define OP_SB		1
# define OP_SS		2
# define OP_PA		3
# define OP_PB		4
# define OP_RA		5
# define OP_RB		6
# define OP_RR		7
# define OP_RRA		8
# define OP_RRB		9
# define OP_RRR		10
# define OP_COUNT	11

typedef struct s_ps_node
{
	int					nb;
	int					index;
	struct s_ps_node	*next;
	struct s_ps_node	*prev;
}	t_ps_node;

/*
** Program state. Globals are forbidden, so this is passed to every
** operation: it owns both stacks and the per-operation counters.
** Its Counters !!!! bro
*/
typedef struct s_ps
{
	t_ps_node	*a;
	t_ps_node	*b;
	int			ops[OP_COUNT];
	int			strategy;
	int			regime;
	int			bench;
	double		disorder;
}	t_ps;

/* utils: parsing and errors */
int			ft_isdigit(int c);
char		**ft_split(char const *s, char c);
int			ft_isnum(char *num);
long		ft_atoi(const char *nptr);
int			ft_strcmp(const char *s1, const char *s2);
void		ft_putstr_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);
void		ft_error(char *c);
void		ft_free_split(char **words);
void		ft_ps_free(t_ps *ps);
void		ft_ps_error(t_ps *ps, char **words);
int			ft_apply_flag(t_ps *ps, char *arg);
void		ft_parse_args(t_ps *ps, int argc, char **argv);

/* utils: nodes and stack queries */
t_ps_node	*ft_new_node(int nb);
void		ft_add_bottom(t_ps_node **stack, t_ps_node *node);
void		ft_free_stack(t_ps_node **stack);
int			ft_stack_size(t_ps_node *s);
int			ft_is_sorted(t_ps_node *s);
t_ps_node	*ft_find_min(t_ps_node *s);
t_ps_node	*ft_find_max(t_ps_node *s);
int			ft_get_pos(t_ps_node *s, t_ps_node *node);
void		ft_index_stack(t_ps_node *s);
double		ft_disorder(t_ps_node *a);
void		ft_print_bench(t_ps *ps);

/* func: raw list moves (no output) */
int			swap(t_ps_node **s);
int			push(t_ps_node **get, t_ps_node **dst);
int			rotate(t_ps_node **stack);
int			reverse_rotate(t_ps_node **stack);

/* func: Push_swap operations (print + count) */
void		ft_log_op(t_ps *ps, int op, char *name);
void		sa(t_ps *ps);
void		sb(t_ps *ps);
void		ss(t_ps *ps);
void		pa(t_ps *ps);
void		pb(t_ps *ps);
void		ra(t_ps *ps);
void		rb(t_ps *ps);
void		rr(t_ps *ps);
void		rra(t_ps *ps);
void		rrb(t_ps *ps);
void		rrr(t_ps *ps);

/* sort */
void		ft_sort(t_ps *ps);
void		ft_sort_three(t_ps *ps);
void		ft_sort_small(t_ps *ps);
void		ft_sort_simple(t_ps *ps);
void		ft_sort_medium(t_ps *ps);
void		ft_sort_complex(t_ps *ps);
void		ft_rotate_a_to(t_ps *ps, int pos);
void		ft_rotate_b_to(t_ps *ps, int pos);

#endif
