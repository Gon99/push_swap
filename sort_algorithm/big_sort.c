/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goliano- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 15:53:38 by goliano-          #+#    #+#             */
/*   Updated: 2021/10/22 16:28:33 by goliano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

size_t	ft_checkbin(int check, size_t bit)
{
	if (!check)
		return (1);
	check >>= bit;
	if (check & 1)
		return (0);
	else
		return (1);
}

void	movestack(t_stack *n_stack, size_t bit)
{
	size_t	i;
	size_t	l;

	i = 0;
	l = n_stack->l_a;
	while (i < l)
	{
		if (ft_checkbin(n_stack->stack_a[0], bit))
			do_pb(n_stack);
		else
			do_ra(n_stack);
		i++;
	}
}

int	*ft_renamenums(t_stack *n_stack)
{
	size_t	i;
	size_t	j;
	size_t	val;
	int		*newstack;

	i = 0;
	val = 0;
	newstack = malloc(sizeof(int) * (n_stack->l_a + 1));
	if (!newstack)
		return (NULL);
	newstack[n_stack->l_a] = '\0';
	while (i < n_stack->l_a)
	{
		j = 0;
		while (j < n_stack->l_a)
		{
			if (n_stack->stack_a[i] > n_stack->stack_a[j])
				val++;
			j++;
		}
		newstack[i] = val;
		val = 0;
		i++;
	}
	return (newstack);
}

void	ft_combstack(t_stack *n_stack)
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
	n_stack->stack_a = ft_renamenums(n_stack);
	while (x < n_stack->l_a)
	{
		n_stack->stack_b[x] = -1;
		x++;
	}
	while (!a_is_sorted(n_stack))
	{	
		movestack(n_stack, i++);
		ft_combstack(n_stack);
	}
}
