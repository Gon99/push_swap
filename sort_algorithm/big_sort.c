#include "../includes/push_swap.h"

size_t	ft_checkbin(int check, size_t bit)
{
	if (!check)
		return (1);
	check >>= bit;
	if (check & 1)
		return (0);
	else
		return (1);
}

void movestack(t_stack *n_stack, size_t bit)
{
	size_t	i;

	i = -1;
	while (++i < 500)
	{
		//printf("ft: %ld\n", ft_checkbin(n_stack->stack_a[0], bit));
		//printf("bit: %ld\n", bit);
		//printf("0: %d\n", n_stack->stack_a[0]);
		//return ;
		if (ft_checkbin(n_stack->stack_a[0], bit))
			do_pb(n_stack);
		else
			do_ra(n_stack);
	}
	//printf("SIZE ACABA: %ld\n", n_stack->l_a);
}

int	*ft_renamenums(t_stack *n_stack)
{
	size_t	i;
	size_t	j;
	size_t	val;
	int		*newstack;

	i = -1;
	j = -1;
	val = 0;
	newstack = malloc(sizeof(int) * (n_stack->l_a + 1));
	if (!newstack)
		return (NULL);
	newstack[n_stack->l_a] = '\0';
	while (++i < n_stack->l_a)
	{
		while (++j < n_stack->l_a)
			if (n_stack->stack_a[i] > n_stack->stack_a[j])
				val++;
		newstack[i] = val;
		val = 0;
		j = -1;
	}
	return (newstack);
}

void	ft_combstack(t_stack *n_stack)
{
	size_t	i;

	i = -1;
	while (n_stack->stack_b[0] > -1 && ++i < 500)
		do_pa(n_stack);
}

void	ft_inistackb(t_stack *n_stack)
{
	size_t	i;

	i = -1;
	while (++i < 500)
		n_stack->stack_b[i] = -1;
}

void	do_big_sort(t_stack *n_stack)
{
	size_t	i;

	i = -1;
	n_stack->stack_a = ft_renamenums(n_stack);
	ft_inistackb(n_stack);
	while (!a_is_sorted(n_stack))
	{	
		movestack(n_stack, ++i);
		ft_combstack(n_stack);
	}
}
