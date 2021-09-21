/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goliano- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 14:27:38 by goliano-          #+#    #+#             */
/*   Updated: 2021/09/21 14:29:40 by goliano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	*ft_memset(void	*b, int c, size_t len)
{
	unsigned char	*aux;

	aux = b;
	while (len > 0)
	{
		*aux = (unsigned char)c;
		len--;
		aux++;
	}
	return (b);
}
