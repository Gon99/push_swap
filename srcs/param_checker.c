/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goliano- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 13:32:04 by goliano-          #+#    #+#             */
/*   Updated: 2021/10/14 15:56:32 by goliano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	check_long_atoi(char **params)
{
	int	i;
	int	r;

	i = 1;
	r = 1;
	while (params[i] && r == 1)
	{
		if (ft_latoi(params[i]) == 0)
		{
			if (params[i][0] == '-' && params[i][1] == '0')
				r = 1;
			else if(params[i][0] == '0')
				r = 1;
			else
				r = 0;
		}
		i++;
	}
	return (r);
}

int		check_rep_numbers(t_stack *n_stack)
{
	int	i;
	int	j;

	i = 0;
	while (i < n_stack->l_a - 1)
	{
		j = i + 1;
		while (j < n_stack->l_a)
		{
			if (n_stack->stack_a[i] == n_stack->stack_a[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int		check_letters(char **argv)
{
	int	l;
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		l = ft_strlen(argv[i]);
		while (j < l)
		{
			/*if ((argv[i][j] < '0' || argv[i][j] > '9') && argv[i][j] != 32 )
				if (argv[i][j] != '-')
					return (0);
				if (argv[i][j] == '-' && (argv[i][j + 1] < '0' || argv[i][j + 1] > '9'))
					return (0);
	*/		j++;
		}
		i++;
	}
	return (1);
}

long	handle_params(int argc, char **params)
{
	long	r;

	r = 1;
	if (argc == 1)
		r = 0;
	r = r && check_letters(params);
	r = r && check_long_atoi(params);
	return (r);
}
