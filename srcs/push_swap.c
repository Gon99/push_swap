/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goliano- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 12:28:47 by goliano-          #+#    #+#             */
/*   Updated: 2021/10/07 16:28:32 by goliano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	pull_all_b(t_stack *n_stack)
{
	while (n_stack->l_b > 0)
		do_pa(n_stack);
}

static int	handle_stack_a(t_stack *n_stack, t_sstack *s_stack)
{
	int	is;

	is = 0;
	sort_n_stack(s_stack);
	while (n_stack->l_a > 2)
	{
		if (a_is_sorted(n_stack))
		{
			is = 1;
			break ;
		}
		mp_algorithm_a(n_stack, s_stack);
		s_stack->l = n_stack->l_a;
		ft_memcpy(s_stack->ss, n_stack->stack_a, n_stack->l_a);
		sort_n_stack(s_stack);
	}
	if (n_stack->stack_a[0] > n_stack->stack_a[1])
		do_sa(n_stack);
	return (is);
}

static void	handle_stack_b(t_stack *n_stack, t_sstack *s_stack, int is)
{
	while (n_stack->l_b > 0)
	{
		if (b_is_sorted(n_stack))
		{
			pull_all_b(n_stack);
			break ;
		}
		mp_algorithm_b(n_stack, s_stack, is);
	}
}

static void print_a(t_stack *n_stack)
{
	int	i;

	i = 0;
	while (i < n_stack->l_a)
	{
		printf("A[%d]: %d\n", i, n_stack->stack_a[i]);
		i++;
	}
}

static void print_b(t_stack *n_stack)
{
	int	i;

	i = 0;
	while (i < n_stack->l_b)
	{
		printf("B[%d]: %d\n", i, n_stack->stack_b[i]);
		i++;
	}
}

int	main(int argc, char **argv)
{
	int			r;
	int			is;
	t_stack		n_stack;
	t_sstack	s_stack;

	is = 0;
	r = handle_params(argc, argv);
	init_stacks(argc, argv, &n_stack, &s_stack);
	if (argc - 1 == 3)
		short_sort(&n_stack);
	int	x = 0;
	while(!a_is_sorted(&n_stack))
	{
		is = handle_stack_a(&n_stack, &s_stack);
		handle_stack_b(&n_stack, &s_stack, is);
		printf("\n");
		printf("\n");
		printf("\n");
		printf("\n");
		x++;
	}
	printf("IS: %d\n", is);
	printf("R: %d\n", r);
	print_a(&n_stack);
	printf("\n");
	print_b(&n_stack);
	return (0);
}
