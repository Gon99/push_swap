/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_actions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goliano- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 16:19:40 by goliano-          #+#    #+#             */
/*   Updated: 2021/10/25 12:06:23 by goliano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	do_pa(t_stack *n_stack)
{
	size_t	i;
	int		*new_stack;

	write(1, "pa\n", 3);
	n_stack->l_a++;
	new_stack = ft_calloc(sizeof(int), n_stack->l_a);
	if (!new_stack)
		return ;
	new_stack[0] = n_stack->stack_b[0];
	i = 0;
	while (i < n_stack->l_b)
	{
		n_stack->stack_b[i] = n_stack->stack_b[i + 1];
		i++;
	}
	n_stack->l_b--;
	i = 1;
	while (i < n_stack->l_a)
	{
		new_stack[i] = n_stack->stack_a[i - 1];
		i++;
	}
	ft_memcpy(n_stack->stack_a, new_stack, n_stack->l_a);
	free(new_stack);
}

void	do_pb(t_stack *n_stack)
{
	size_t	i;
	int		*new_stack;

	write(1, "pb\n", 3);
	n_stack->l_b++;
	new_stack = ft_calloc(sizeof(int), n_stack->l_b);
	if (!new_stack)
		return ;
	new_stack[0] = n_stack->stack_a[0];
	i = 0;
	while (i < n_stack->l_a)
	{
		n_stack->stack_a[i] = n_stack->stack_a[i + 1];
		i++;
	}
	n_stack->l_a--;
	i = 1;
	while (i < n_stack->l_b)
	{
		new_stack[i] = n_stack->stack_b[i - 1];
		i++;
	}
	ft_memcpy(n_stack->stack_b, new_stack, n_stack->l_b);
	free(new_stack);
}
