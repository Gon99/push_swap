/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goliano- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 13:32:04 by goliano-          #+#    #+#             */
/*   Updated: 2021/10/13 16:54:18 by goliano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	check_repeated_numbers(char **params)
{
	int	i;
	int	j;

	i = 1;
	while (params[i])
	{
		j = i + 1;
		while (params[j])
		{
			/*if (ft_atoi(params[i]) == 0 && params[i][0] != '0')
				return (0);*/
			if (ft_strcmp(params[i], params[j]) == 0)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static int	check_long_atoi(char **params)
{
	int	i;
	int	r;

	i = 0;
	r = 1;
	while (params[i] && r == 1)
	{
		if (ft_latoi(params[i]) == 0 && params[i][0] != '0')
			r = 0;
		i++;
	}
	return (r);
}

long	handle_params(int argc, char **params)
{
	long	r;

	r = 1;
	if (argc == 1)
		r = 0;
	r = check_repeated_numbers(params);
	r = check_long_atoi(params);
	printf("R2: %ld\n", r);
	return (r);
}
