/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goliano- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 12:27:28 by goliano-          #+#    #+#             */
/*   Updated: 2021/09/21 16:41:13 by goliano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct n_stack
{
	int	*stack_a;
    int *stack_b;
    int l;
}	t_stack;

int		handle_params(int argc, char **params);
int		ft_strcmp(char *s1, char *s2);
int		ft_atoi(char const *str);
void	init_stacks(int argc, char **argv, t_stack *n_stack);
void	*ft_calloc(size_t count, size_t size);
void	*ft_memset(void *b, int c, size_t len);
void	do_sa(t_stack *n_stack);
void	do_sb(t_stack *n_stack);
void	do_ss(t_stack *n_stack);
void	do_ra(t_stack *n_stack);
void	do_rb(t_stack *n_stack);
void	do_rr(t_stack *n_stack);
void	do_pa(t_stack *n_stack);

#endif
