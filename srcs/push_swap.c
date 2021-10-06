/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goliano- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 12:28:47 by goliano-          #+#    #+#             */
/*   Updated: 2021/10/06 16:02:22 by goliano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int    b_is_sorted(t_stack *n_stack)
{
    int    i;
    int    is_sorted;

    i = 0;
    is_sorted = 1;
    while (i < n_stack->l_b - 1 && is_sorted == 1)
    {
        if (n_stack->stack_b[i] < n_stack->stack_b[i + 1])
            is_sorted = 0;
        i++;
    }
    return (is_sorted);
}

void    pull_all_b(t_stack *n_stack)
{
    while(n_stack->l_b > 0)
        do_pa(n_stack);
}

int	main(int argc, char **argv)
{
	int			r;
	int			is;
	t_stack		n_stack;
	ts_stack	s_stack;
	
	is = 0;
	r = handle_params(argc, argv);
	init_stacks(argc, argv, &n_stack, &s_stack);
    if (argc - 1 == 3)
        short_sort(&n_stack);
	sort_n_stack(&s_stack);
	while (n_stack.l_a > 2)
	{
        if (a_is_sorted(&n_stack))
		{
			is = 1;
            break ;
		}
		mp_algorithm_a(&n_stack, &s_stack);
		s_stack.l = n_stack.l_a;
		ft_memcpy(s_stack.ss, n_stack.stack_a, n_stack.l_a);
		sort_n_stack(&s_stack);
	}
    if (n_stack.stack_a[0] > n_stack.stack_a[1])
        do_sa(&n_stack);
    while (n_stack.l_b > 0)
    {
        if (b_is_sorted(&n_stack))
        {
            pull_all_b(&n_stack);
            break;
        }
        mp_algorithm_b(&n_stack, &s_stack, is);
    }
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
	printf("R: %d\n", r);
	//system("leaks -q a.out");
	return (0);
}
