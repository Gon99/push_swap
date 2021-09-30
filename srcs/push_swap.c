/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goliano- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 12:28:47 by goliano-          #+#    #+#             */
/*   Updated: 2021/09/30 19:03:27 by goliano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	int			r;
	t_stack		n_stack;
	ts_stack	s_stack;
	
	r = handle_params(argc, argv);
	init_stacks(argc, argv, &n_stack, &s_stack);
	sort_n_stack(&s_stack);
	mp_algorithm(&n_stack, &s_stack);
	/*if (argc - 1 < 6)
		short_sort(&n_stack);*/
	//do_pa(&n_stack);
	//do_sa(&n_stack);
	//do_pb(&n_stack);
	//do_pb(&n_stack);
	//do_pb(&n_stack);
	//do_rrb(&n_stack);
	//do_ra(&n_stack);
	//do_pb(&n_stack);
	//do_pb(&n_stack);
	//do_pb(&n_stack);
	//do_pa(&n_stack);
	//do_pa(&n_stack);
	//do_pa(&n_stack);
	printf("VA1: %d\n", n_stack.stack_a[0]);
	printf("VA2: %d\n", n_stack.stack_a[1]);
	printf("VA3: %d\n", n_stack.stack_a[2]);
	printf("VA4: %d\n", n_stack.stack_a[3]);
	printf("VA5: %d\n", n_stack.stack_a[4]);
	printf("VB1: %d\n", n_stack.stack_b[0]);
	printf("VB2: %d\n", n_stack.stack_b[1]);
	printf("VB3: %d\n", n_stack.stack_b[2]);
	printf("VB4: %d\n", n_stack.stack_b[3]);
	printf("SS1: %d\n", s_stack.ss[0]);
	printf("SS2: %d\n", s_stack.ss[1]);
	printf("SS3: %d\n", s_stack.ss[2]);
	printf("SS4: %d\n", s_stack.ss[3]);
	printf("SS5: %d\n", s_stack.ss[4]);
	printf("R: %d\n", r);
	//system("leaks -q a.out");
	return (0);
}
