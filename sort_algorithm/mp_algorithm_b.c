/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mp_algorithm_b.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goliano- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 11:55:14 by goliano-          #+#    #+#             */
/*   Updated: 2021/10/07 15:35:36 by goliano-         ###   ########.fr       */
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

static void	handle_two_b(t_stack *n_stack, int *chunk)
{
	if (n_stack->stack_b[0] < n_stack->stack_b[1])
		do_sb(n_stack);
	do_pa(n_stack);
	do_pa(n_stack);
	*chunk -= 2;
}

static void	do_second_half_b(t_stack *n_stack, t_sstack *s_stack, int *chunk)
{
	int	crb;
	int	nta;
	int	hl;

	crb = 0;
	hl = *chunk / 2;
	nta = *chunk - (hl + 1);
	printf("PARO");
	return ;
	while (nta > 0)
	{
		if (n_stack->stack_b[0] > s_stack->ss[hl])
		{
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
}

static void	do_mp_b(t_stack *n_stack, t_sstack *s_stack, int *chunk, int nc)
{
	ft_memcpy(s_stack->ss, n_stack->stack_b, *chunk);
	s_stack->l = *chunk;
	sort_n_stack(s_stack);
	if (nc == 1)
		do_last_chunk_b(n_stack, s_stack, chunk);
	else
		do_second_half_b(n_stack, s_stack, chunk);
}

void	mp_algorithm_b(t_stack *n_stack, t_sstack *s_stack, int is)
{
	int	chunk;
	int	nc;

	s_stack->l = 0;
	nc = n_of_chunks(n_stack);
	if (is == 1)
		nc--;
	chunk = 0;
	while (nc > 0)
	{
		if (chunk == 0)
			chunk = get_chunk(n_stack, nc);
		if (chunk == 1)
		{
			do_pa(n_stack);
			chunk--;
		}
		else if (chunk == 2)
			handle_two_b(n_stack, &chunk);
		else
			do_mp_b(n_stack, s_stack, &chunk, nc);
		if (chunk == 0)
			nc--;
	}
}
