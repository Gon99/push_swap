/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goliano- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 12:28:47 by goliano-          #+#    #+#             */
/*   Updated: 2021/10/27 11:30:39 by goliano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	pull_all_b(t_stack *n_stack)
{
	while (n_stack->l_b > 0)
		do_pa(n_stack);
}

static void	handle_stack_a(t_stack *n_stack, t_sstack *s_stack)
{
	while (n_stack->l_a > 2)
	{
		if (a_is_sorted(n_stack))
			break ;
		s_stack->l = n_stack->l_a;
		ft_memcpy(s_stack->ss, n_stack->stack_a, n_stack->l_a);
		sort_n_stack(s_stack);
		mp_algorithm_a(n_stack, s_stack);
	}
	if (n_stack->stack_a[0] > n_stack->stack_a[1])
		do_sa(n_stack);
}

static void	handle_stack_b(t_stack *n_stack)
{
	while (n_stack->l_b > 0)
	{
		if (b_is_sorted(n_stack))
		{
			pull_all_b(n_stack);
			break ;
		}
		mp_algorithm_b(n_stack);
	}
}

static void	handle_error(int err, t_stack *n_stack, t_sstack *s_stack)
{
	if (err == 0)
	{
		write(1, "Error\n", 6);
		free_stacks(n_stack, s_stack);
		exit(1);
	}
}

int	main(int argc, char **argv)
{
	long		r;
	t_stack		n_stack;
	t_sstack	s_stack;

	if (argc <= 1)
		return (0);
	r = handle_params(argc, argv);
	init_stacks(argc, argv, &n_stack, &s_stack);
	if (r == 1)
		r = check_rep_numbers(&n_stack);
	handle_error(r, &n_stack, &s_stack);
	if (n_stack.l_a == 3)
		short_sort(&n_stack);
	else if (n_stack.l_a <= 100)
	{
		while (!a_is_sorted(&n_stack))
		{
			handle_stack_a(&n_stack, &s_stack);
			handle_stack_b(&n_stack);
		}
	}
	else
		do_big_sort(&n_stack);
	free_stacks(&n_stack, &s_stack);
	return (0);
}
