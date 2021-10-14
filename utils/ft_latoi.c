/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goliano- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 15:43:46 by goliano-          #+#    #+#             */
/*   Updated: 2021/10/14 13:55:05 by goliano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	is_space(char s)
{
	int		is_s;

	is_s = 0;
	if (s == '\n' || s == ' ' || s == '\v' || s == '\t' || s == '\r' \
			|| s == '\f')
		is_s = 1;
	return (is_s);
}

int	ft_latoi(const char *str)
{
	char	*aux;
	long	res;
	int		is_n;

	aux = (char *)str;
	res = 0;
	is_n = 0;
	while (is_space(*aux) != '\0')
		aux++;
	if (*aux == '+' || *aux == '-')
	{
		if (*aux == '-')
			is_n = 1;
		aux++;
	}
	while (*aux >= '0' && *aux <= '9')
	{
		res = res * 10 + *aux - '0';
		aux++;
	}
	if (is_n)
		res = -res;
	if (res > 2147483647 || res < -2147483648)
		return (0);
	return (res);
}
