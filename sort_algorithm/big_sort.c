/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goliano- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 15:53:38 by goliano-          #+#    #+#             */
/*   Updated: 2021/10/25 16:37:20 by goliano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

size_t	shift_right_bytes(int num, size_t pos)
{
	int	r;

	r = 1;
	if (!num)
		return (1);
	num >>= pos;
	if (num & 1)
		return (0);
	return (r);
}

void	push_to_a(t_stack *n_stack, size_t bit)
{
	size_t	i;
	size_t	l;

	i = 0;
	l = n_stack->l_a;
	while (i < l)
	{
		if (shift_right_bytes(n_stack->stack_a[0], bit))
			do_pb(n_stack);
		else
			do_ra(n_stack);
		i++;
	}
}

int	*change_stack_a(t_stack *n_stack)
{
	size_t	i;
	size_t	j;
	size_t	n_num;
	int		*aux;

	i = 0;
	aux = malloc(sizeof(int) * (n_stack->l_a + 1));
	if (!aux)
		return (0);
	while (i < n_stack->l_a)
	{
		n_num = 0;
		j = 0;
		while (j < n_stack->l_a)
		{
			if (n_stack->stack_a[i] > n_stack->stack_a[j])
				n_num++;
			j++;
		}
		aux[i] = n_num;
		i++;
	}
	free(n_stack->stack_a);
	return (aux);
}

void	push_to_b(t_stack *n_stack)
{
	size_t	i;
	size_t	l;

	i = 0;
	l = n_stack->l_a + n_stack->l_b;
	while (n_stack->stack_b[0] > -1 && i < l)
	{
		do_pa(n_stack);
		i++;
	}
}

void	do_big_sort(t_stack *n_stack)
{
	size_t	i;
	size_t	x;

	i = 0;
	x = 0;
	n_stack->stack_a = change_stack_a(n_stack);
	while (x < n_stack->l_a)
	{
		n_stack->stack_b[x] = -1;
		x++;
	}
	while (!a_is_sorted(n_stack))
	{
		push_to_a(n_stack, i++);
		push_to_b(n_stack);
	}
}
