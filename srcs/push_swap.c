/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goliano- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 12:28:47 by goliano-          #+#    #+#             */
/*   Updated: 2021/10/19 17:02:15 by goliano-         ###   ########.fr       */
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

static void	handle_stack_a_big(t_stack *n_stack, t_sstack *s_stack)
{
	s_stack->l = n_stack->l_a;
	ft_memcpy(s_stack->ss, n_stack->stack_a, n_stack->l_a);
	sort_n_stack(s_stack);
	mp_algorithm_a_big(n_stack, s_stack);
}

/*static void print_a(t_stack *n_stack)
{
	int	i;

	i = 0;
	while (i < n_stack->l_a)
	{
		printf("A[%d]: %d\n", i, n_stack->stack_a[i]);
		i++;
	}
}*/

static void print_b(t_stack *n_stack)
{
	int	i;

	i = 0;
	while (i < n_stack->l_b - 1)
	{
		printf("B[%d]: %d\n", i, n_stack->stack_b[i]);
		i++;
	}
}

void	handle_error(int err)
{
	if (err == 0)
	{
		write(1, "Error\n", 6);
		exit(1);
	}
}

int	main(int argc, char **argv)
{
	long		r;
	t_stack		n_stack;
	t_sstack	s_stack;

	r = handle_params(argc, argv);
	init_stacks(argc, argv, &n_stack, &s_stack);
	if (r == 1)
		r = check_rep_numbers(&n_stack);
	handle_error(r);
	if (n_stack.l_a == 3)
		short_sort(&n_stack);
	else if (n_stack.l_a <= 100)
	{
		while(!a_is_sorted(&n_stack))
		{
			handle_stack_a(&n_stack, &s_stack);
			handle_stack_b(&n_stack);
		}
	}
	else
	{
		int	x = 0;
		while (!a_is_sorted(&n_stack))
		{
			if (x == 1)
				break;
			handle_stack_a_big(&n_stack, &s_stack);
			print_b(&n_stack);
			x++;
			//handle_stack_b_big(&n_stack, &s_stack);
		}
	}
	//print_a(&n_stack);
	//free_stacks(&n_stack, &s_stack);
	//system("leaks -q push_swap");
	return (0);
}
