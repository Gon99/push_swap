/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goliano- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 13:32:04 by goliano-          #+#    #+#             */
/*   Updated: 2021/09/17 15:58:53 by goliano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	handle_params(int argc, char **params)
{
	int		i;
	int		j;

	i = 1;
	if (argc == 1)
		return (0);
	while (params[i])
	{
		j = i + 1;
		if (ft_atoi(params[i]) == 0 && params[i][0] != '0')
			return (0);
		while (params[j])
		{
			if (ft_strcmp(params[i], params[j]) == 0)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
