/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goliano- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 12:28:47 by goliano-          #+#    #+#             */
/*   Updated: 2021/09/21 16:57:34 by goliano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	int	r;
	t_stack	n_stack;
	
	r = handle_params(argc, argv);
	init_stacks(argc, argv, &n_stack);
	do_pa(&n_stack);
	printf("V1: %d\n", n_stack.stack_a[0]);
	printf("V2: %d\n", n_stack.stack_a[1]);
	printf("V3: %d\n", n_stack.stack_a[2]);
	printf("V4: %d\n", n_stack.stack_a[3]);
	printf("R: %d\n", r);
	return (0);
}
