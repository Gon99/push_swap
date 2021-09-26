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
