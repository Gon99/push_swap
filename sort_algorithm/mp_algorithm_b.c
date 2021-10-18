/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mp_algorithm_b.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goliano- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 11:55:14 by goliano-          #+#    #+#             */
/*   Updated: 2021/10/18 16:42:08 by goliano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	b_is_sorted(t_stack *n_stack)
{
	int	i;
	int	is_sorted;

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

/*static void	handle_two_b(t_stack *n_stack, int *chunk)
{
	if (n_stack->stack_b[0] < n_stack->stack_b[1])
		do_sb(n_stack);
	do_pa(n_stack);
	do_pa(n_stack);
	*chunk -= 2;
}*/

/*static void	do_second_half_b(t_stack *n_stack, t_sstack *s_stack, int *chunk)
{
	int	crb;
	int	nta;
	int	hl;

	crb = 0;
	hl = *chunk / 2;
	nta = *chunk - (hl + 1);
	while (nta > 0)
	{
		if (n_stack->stack_b[0] > s_stack->ss[hl])
		{
            if (n_stack->stack_b[0] < n_stack->stack_b[1])
                do_sb(n_stack);
			do_pa(n_stack);
			*chunk = *chunk - 1;
			nta--;
		}
		else
		{
			do_rb(n_stack);
			crb++;
		}
	}
	while (crb > 0)
	{
		do_rrb(n_stack);
		crb--;
	}
}*/

static int	get_max_val_of_chunk(t_stack *n_stack)
{
	int	max;
	int	i;

	max = n_stack->stack_b[0];
	i = 1;
	while (i < n_stack->l_b)
	{
		if (n_stack->stack_b[i] > max)
			max = n_stack->stack_b[i];
		i++;
	}
	return (max);
}

static int	idx_of_max_val(t_stack *n_stack)
{
	int	i;
	int	idx;
	int	max;

	max = n_stack->stack_b[0];
	i = 1;
	idx = 0;
	while (i < n_stack->l_b)
	{
		if (n_stack->stack_b[i] > max)
		{
			max = n_stack->stack_b[i];
			idx = i;
		}
		i++;
	}
	return (idx);
}

static int	idx_of_min_val(t_stack *n_stack)
{
	int	i;
	int	idx;
	int	min;

	min = n_stack->stack_b[0];
	i = 1;
	idx = 0;
	while (i < n_stack->l_b - 1)
	{
		if (n_stack->stack_b[i] > min)
		{
			min = n_stack->stack_b[i];
			idx = i;
		}
		i++;
	}
	return (idx);
	
}

static int	get_min_val(t_stack *n_stack)
{
	int	min;
	int	i;

	i = 1;
	min = n_stack->stack_b[0];
	while (i < n_stack->l_b - 1)
	{
		if (n_stack->stack_b[i] < min)
			min = n_stack->stack_b[i];
		i++;
	}
	return (min);
}

static void	do_mp_b(t_stack *n_stack, int *chunk)
{
	int	max;
	int	idx;
	int	min;
	int	idx2;

	idx = idx_of_max_val(n_stack);
	max = get_max_val_of_chunk(n_stack);
	min = get_min_val(n_stack);
	idx2 = idx_of_min_val(n_stack);
	/*printf("IDX: %d\n", idx);
	printf("MAX:  %d\n", max);
	printf("LB:  %d\n", n_stack->l_b / 2);
	printf("LB2:  %d\n", n_stack->l_b);
	*/
	if (idx < n_stack->l_b / 2)
	{
		while (1)
		{
			if (n_stack->stack_b[0] == max)
			{
				do_pa(n_stack);
				*chunk = *chunk - 1;
				break ;
			}
			else
				do_rb(n_stack);
		}
	}
	else
	{
		while (1)
		{
			if (n_stack->stack_b[n_stack->l_b - 1] == max)
			{
				do_rrb(n_stack);
				do_pa(n_stack);
				*chunk = *chunk - 1;
				break;
			}
			else
				do_rrb(n_stack);
		}
	}
}

void	mp_algorithm_b(t_stack *n_stack, t_sstack *s_stack)
{
	int	chunk;
	int	nc;

	s_stack->l = 0;
	nc = n_of_chunks(n_stack);
	chunk = 0;
	while (n_stack->l_b > 0)
	{
		/*if (chunk == 0)
			chunk = get_chunk(n_stack, nc);
		if (chunk == 1)
		{
			do_pa(n_stack);
			chunk--;
		}
		else if (chunk == 2)
			handle_two_b(n_stack, &chunk);
		else
			do_mp_b(n_stack, &chunk);*/
		do_mp_b(n_stack, &chunk);
		if (chunk == 0)
			nc--;
	}
}
