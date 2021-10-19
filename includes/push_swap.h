/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goliano- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 12:27:28 by goliano-          #+#    #+#             */
/*   Updated: 2021/10/07 13:19:35 by goliano-         ###   ########.fr       */
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
	int	*stack_b;
	int	l_a;
	int	l_b;
}	t_stack;

typedef struct s_stack
{
	int	*ss;
	int	l;
}	t_sstack;

long		handle_params(int argc, char **params);
int     check_rep_numbers(t_stack *n_stack);
int		ft_strcmp(char *s1, char *s2);
int		ft_latoi(char const *str);
int		a_is_sorted(t_stack *n_stack);
int		b_is_sorted(t_stack *n_stack);
void	init_stacks(int argc, char **argv, t_stack *n_stack, t_sstack *s_stack);
void	*ft_calloc(size_t count, size_t size);
void	*ft_memset(void *b, int c, size_t len);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	do_sa(t_stack *n_stack);
void	do_sb(t_stack *n_stack);
void	do_ss(t_stack *n_stack);
void	do_ra(t_stack *n_stack);
void	do_rb(t_stack *n_stack);
void	do_rr(t_stack *n_stack);
void	do_rra(t_stack *n_stack);
void	do_rrb(t_stack *n_stack);
void	do_rrr(t_stack *n_stack);
void	do_pa(t_stack *n_stack);
void	do_pb(t_stack *n_stack);
void	short_sort(t_stack *n_stack);
void	mp_algorithm_a(t_stack *n_stack, t_sstack *s_stack);
void	mp_algorithm_b(t_stack *n_stack/*, t_sstack *s_stack*/);
void	sort_n_stack(t_sstack *s_stack);
int		n_of_chunks(t_stack *n_stack);
int		get_chunk(t_stack *n_stack, int nc);
void	do_last_chunk_b(t_stack *n_stack, t_sstack *s_stack, int *chunk);
char    **ft_split(char const *s, char c);
int     ft_strlen(char *str);
void    free_stacks(t_stack *n_stack, t_sstack *s_stack);
void    free_sp(char **sp);
void    mp_algorithm_a_big(t_stack *n_stack, t_sstack *s_stack);

#endif
