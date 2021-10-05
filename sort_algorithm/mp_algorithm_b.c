/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mp_algorithm_b.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goliano- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 11:55:14 by goliano-          #+#    #+#             */
/*   Updated: 2021/10/04 14:51:56 by goliano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*static int	b_is_sorted(t_stack *n_stack)
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
}*/

static int	n_of_chunks(t_stack *n_stack)
{
	int	r;
	int	tl;
	int	div;

	tl = n_stack->l_a + n_stack->l_b;
	div = 0;
	r = 0;
	while (tl > 1)
	{
		div += tl / 2;
		tl -= tl / 2;
		r++;
	}
	if (div != n_stack->l_b)
		r--;
	return (r);
}

int	get_chunk(t_stack *n_stack, int nc)
{
	
	int	r;
	int	tl;

	tl = n_stack->l_a + n_stack->l_b;
	r = 0;
	while (nc > 0)
	{
		r = tl / 2;
		tl -= tl / 2;
		nc--;
	}
	return (r);
}

static void	handle_two_b(t_stack *n_stack)
{
	if (n_stack->stack_b[0] < n_stack->stack_b[1])
		do_sb(n_stack);
	do_pa(n_stack);
	do_pa(n_stack);
}

static void	do_first_half_b(t_stack *n_stack, ts_stack *s_stack, int chunk)
{
	int	idx;

	idx = chunk / 2;
	while (n_stack->stack_b[0] > s_stack->ss[idx])
		do_pa(n_stack);
}

static void	do_second_half_b(t_stack *n_stack, ts_stack *s_stack, int chunk)
{
	int	crb;
	int	nta;
	int	hl;

	crb = 0;
	hl = chunk / 2;
	nta = chunk - (hl + 1);
	while (nta > 0)
	{
		if (n_stack->stack_b[0] > s_stack->ss[hl])
		{
			do_pa(n_stack);
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

static void	do_last_chunk_b(t_stack *n_stack, ts_stack *s_stack, int chunk)
{
	int	nta;
	int	hl;

	hl = chunk / 2;
	nta = chunk - (hl + 1);
	while (nta > 0)
	{
		if (n_stack->stack_b[0] > s_stack->ss[hl])
		{
			do_pa(n_stack);
			nta--;
		}
		else if (n_stack->stack_b[n_stack->l_b] > s_stack->ss[hl])
		{
			do_rrb(n_stack);
			do_pa(n_stack);
			nta--;
		}
		else
			do_rb(n_stack);
	}
}

static void	do_mp_b(t_stack *n_stack, ts_stack *s_stack, int chunk, int nc)
{
	ft_memcpy(s_stack->ss, n_stack->stack_b, chunk);
	s_stack->l = chunk;
	sort_n_stack(s_stack);
	do_first_half_b(n_stack, s_stack, chunk);
	if (nc == 1)
		do_last_chunk_b(n_stack, s_stack, chunk);
	else
		do_second_half_b(n_stack, s_stack, chunk);
}

void	mp_algorithm_b(t_stack *n_stack, ts_stack *s_stack)
{
	int	chunk;
	int	nc;

	s_stack->l = 0;
	nc = n_of_chunks(n_stack);
	while (nc > 0)
	{
		chunk = get_chunk(n_stack, nc);
		if (chunk == 1)
			do_pa(n_stack);
		else if (chunk == 2)
			handle_two_b(n_stack);
		else
			do_mp_b(n_stack, s_stack, chunk, nc);
		nc--;
	}
}
