/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goliano- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 12:46:16 by goliano-          #+#    #+#             */
/*   Updated: 2021/10/19 13:22:46 by goliano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	add_sp_val(char **splitted, t_stack *n_stack, t_sstack *s_stack, int *j)
{
	int	l;
	int	i;

	l = 0;
	i = 0;
	while (splitted[l])
		l++;
	while (i < l)
	{
		n_stack->stack_a[*j] = ft_latoi(splitted[i]);
		s_stack->ss[*j] = ft_latoi(splitted[i]);
		i++;
		*j = *j + 1;
	}
}

static int	check_space(char *argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (argv[i] == ' ')
			return (1);
		i++;
	}
	return (0);
}

static void	handle_sp_args(char **argv, t_stack *n_stack, t_sstack *s_stack)
{
	int		i;
	int		j;
	char	**sp;
	
	i = 1;
	j = 0;
	while (argv[i])
	{
		if (check_space(argv[i]) == 0)
		{
			n_stack->stack_a[j] = ft_latoi(argv[i]);
			s_stack->ss[j] = ft_latoi(argv[i]);
			j++;
		}
		else
		{
			sp = ft_split(argv[i], ' ');
			add_sp_val(sp, n_stack, s_stack, &j);
		}
		i++;
	}
	n_stack->l_a = j;
	s_stack->l = j;
	//free_sp(sp);
}

static int	params_length(char **argv)
{
	int		i;
	int		j;
	int		r;
	char	**sp;

	i = 1;
	j = 0;
	while (argv[i])
	{
		if (check_space(argv[i]) == 0)
			j++;
		else
		{
			sp = ft_split(argv[i], ' ');
			r = 0;
			while (sp[r])
			{
				r++;
			}
			j += r;
		}
		i++;
	}
	//free_sp(sp);
	return (j);
}

void	init_stacks(int argc, char **argv, t_stack *n_stack, t_sstack *s_stack)
{
	int	l;
	
	if (argc == 0)
		return ;
	l = params_length(argv);
	n_stack->stack_a = ft_calloc(l, sizeof(int));
	n_stack->stack_b = ft_calloc(l, sizeof(int));
	s_stack->ss = ft_calloc(l, sizeof(int));
	if (!n_stack->stack_a || !n_stack->stack_b || !s_stack->ss)
		return ;
	n_stack->l_b = 0;
	handle_sp_args(argv, n_stack, s_stack);
}
