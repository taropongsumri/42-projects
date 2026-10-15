#include "../src/push_swap.h"

static void	ft_put_count(char *label, int count, char *end)
{
	ft_putstr_fd(label, 2);
	ft_putstr_fd(": ", 2);
	ft_putnbr_fd(count, 2);
	ft_putstr_fd(end, 2);
}

/* No %f in ft_printf: print disorder as an integer of hundredths of % */

static void	ft_put_percent(double ratio)
{
	long	hundredths;
	char	digits[2];

	hundredths = (long)(ratio * 10000.0 + 0.5);
	ft_putstr_fd("[bench] disorder: ", 2);
	ft_putnbr_fd((int)(hundredths / 100), 2);
	digits[0] = '0' + (hundredths % 100) / 10;
	digits[1] = '0' + hundredths % 10;
	write(2, ".", 1);
	write(2, digits, 2);
	write(2, "%\n", 2);
}

static void	ft_put_strategy(t_ps *ps)
{
	char	*names[4];
	char	*classes[3];

	names[S_SIMPLE] = "Simple";
	names[S_MEDIUM] = "Medium";
	names[S_COMPLEX] = "Complex";
	names[S_ADAPTIVE] = "Adaptive";
	classes[S_SIMPLE] = "O(n^2)";
	classes[S_MEDIUM] = "O(n*sqrt(n))";
	classes[S_COMPLEX] = "O(n log n)";
	ft_putstr_fd("[bench] strategy: ", 2);
	ft_putstr_fd(names[ps->strategy], 2);
	ft_putstr_fd(" / ", 2);
	ft_putstr_fd(classes[ps->regime], 2);
	ft_putstr_fd("\n", 2);
}

void	ft_print_bench(t_ps *ps)
{
	int	total;
	int	i;

	total = 0;
	i = 0;
	while (i < OP_COUNT)
		total += ps->ops[i++];
	ft_put_percent(ps->disorder);
	ft_put_strategy(ps);
	ft_put_count("[bench] total_ops", total, "\n");
	ft_put_count("[bench] sa", ps->ops[OP_SA], "  ");
	ft_put_count("sb", ps->ops[OP_SB], "  ");
	ft_put_count("ss", ps->ops[OP_SS], "  ");
	ft_put_count("pa", ps->ops[OP_PA], "  ");
	ft_put_count("pb", ps->ops[OP_PB], "\n");
	ft_put_count("[bench] ra", ps->ops[OP_RA], "  ");
	ft_put_count("rb", ps->ops[OP_RB], "  ");
	ft_put_count("rr", ps->ops[OP_RR], "  ");
	ft_put_count("rra", ps->ops[OP_RRA], "  ");
	ft_put_count("rrb", ps->ops[OP_RRB], "  ");
	ft_put_count("rrr", ps->ops[OP_RRR], "\n");
}
