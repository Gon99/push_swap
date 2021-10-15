/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_chunks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goliano- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 12:36:51 by goliano-          #+#    #+#             */
/*   Updated: 2021/10/15 16:47:59 by goliano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	n_of_chunks(t_stack *n_stack)
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
		if (div == n_stack->l_b)
			break ;
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

void	do_last_chunk_b(t_stack *n_stack, t_sstack *s_stack, int *chunk)
{
	int	nta;
	int	hl;

	hl = *chunk / 2;
	nta = *chunk - (hl + 1);
	while (nta > 0)
	{
		if (n_stack->stack_b[0] > s_stack->ss[hl])
		{
			if (n_stack->stack_b[0] < n_stack->stack_b[1])
				do_sb(n_stack);
			do_pa(n_stack);
			nta--;
			*chunk = *chunk - 1;
		}
		else if (n_stack->stack_b[n_stack->l_b - 1] > s_stack->ss[hl])
		{
			do_rrb(n_stack);
			/*NEW*/
			/*if (n_stack->stack_b[0] < n_stack->stack_b[n_stack->l_b - 1])
			{
				do_rrb(n_stack);
				do_sb(n_stack);
				do_pa(n_stack);
				*chunk = *chunk - 1;
				nta--;
			}*/
			do_pa(n_stack);
			*chunk = *chunk - 1;
			nta--;
		}
		else
			do_rb(n_stack);
	}
}
