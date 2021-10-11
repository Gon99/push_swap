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
		if (x == 2)
			break;
		is = handle_stack_a(&n_stack, &s_stack);
		handle_stack_b(&n_stack, &s_stack, is);
		printf("\n");
		printf("\n");
		printf("\n");
		printf("\n");
		x++;
	}
	printf("IS: %d\n", is);
	printf("VA1: %d\n", n_stack.stack_a[0]);
	printf("VA2: %d\n", n_stack.stack_a[1]);
	printf("VA3: %d\n", n_stack.stack_a[2]);
	printf("VA4: %d\n", n_stack.stack_a[3]);
	printf("VA5: %d\n", n_stack.stack_a[4]);
	printf("VA6: %d\n", n_stack.stack_a[5]);
    	printf("VA7: %d\n", n_stack.stack_a[6]);
   	printf("VA8: %d\n", n_stack.stack_a[7]);
   	printf("VA9: %d\n", n_stack.stack_a[8]);
    	printf("VA10: %d\n", n_stack.stack_a[9]);
	printf("VA11: %d\n", n_stack.stack_a[10]);
	printf("VA12: %d\n", n_stack.stack_a[11]);
	printf("VA13: %d\n", n_stack.stack_a[12]);
	printf("VA14: %d\n", n_stack.stack_a[13]);
	printf("VA15: %d\n", n_stack.stack_a[14]);
	printf("VA16: %d\n", n_stack.stack_a[15]);
    	printf("VA17: %d\n", n_stack.stack_a[16]);
    	printf("VA18: %d\n", n_stack.stack_a[17]);
    	printf("VA19: %d\n", n_stack.stack_a[18]);
    	printf("VA20: %d\n", n_stack.stack_a[19]);
	printf("R: %d\n", r);
	return (0);
}
