/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goliano- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 12:28:47 by goliano-          #+#    #+#             */
/*   Updated: 2021/10/04 14:51:53 by goliano-         ###   ########.fr       */
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
	while (n_stack.l_a > 2)
	{
		mp_algorithm_a(&n_stack, &s_stack);
		s_stack.l = n_stack.l_a;
		ft_memcpy(s_stack.ss, n_stack.stack_a, n_stack.l_a);
		sort_n_stack(&s_stack);
	}
	printf("LA1: %d\n", n_stack.l_a);
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
