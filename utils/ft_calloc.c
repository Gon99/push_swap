/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goliano- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 13:11:48 by goliano-          #+#    #+#             */
/*   Updated: 2021/09/21 14:28:22 by goliano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	size_t	s;

	s = count * size;
	ptr = malloc(s);
	if (!ptr)
		return (NULL);
	ft_memset(ptr, 0, s);
	return (ptr);
}
