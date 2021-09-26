#include "../includes/push_swap.h"

void	do_rra(t_stack *n_stack)
{
	int	aux;
	int	i;

	write(1, "rra\n", 4);
	i = n_stack->l_a - 1;
	aux = n_stack->stack_a[n_stack->l_a - 1];
	while (i > 0)
	{
		n_stack->stack_a[i] = n_stack->stack_a[i - 1];
		i--;
	}
	n_stack->stack_a[0] = aux;
}

void	do_rrb(t_stack *n_stack)
{
	int	aux;
	int	i;

	write(1, "rrb\n", 4);
	i = n_stack->l_b - 1;
	aux = n_stack->stack_b[n_stack->l_b - 1];
	while (i > 0)
	{
		n_stack->stack_b[i] = n_stack->stack_b[i - 1];
		i--;
	}
	n_stack->stack_b[0] = aux;
}

void	do_rrr(t_stack *n_stack)
{
	do_rra(n_stack);
	do_rrb(n_stack);
}
