/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goliano- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 16:26:47 by goliano-          #+#    #+#             */
/*   Updated: 2021/10/07 16:26:49 by goliano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	int		i;

	i = 0;
	if (!dst && !src)
		return (0);
	while (n > 0)
	{
		((int *)dst)[i] = ((int *)src)[i];
		i++;
		n--;
	}
	return (dst);
}
