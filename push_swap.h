/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 16:34:02 by wfan              #+#    #+#             */
/*   Updated: 2023/04/02 16:34:07 by wfan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdio.h>

# define CHUNK_MAX 25

void	print_list(t_list *top);
void	ft_check_args(int argc, char **argv);
int		is_sorted(t_list **stack);
int		is_sorted_reverse(t_list **stack);
void	free_stack(t_list **stack);
void	ft_free(char **str);
void	index_stack(t_list **stack);
int		max(t_list *stack);
int		min(t_list *stack);

// debug tool
void print_stack(t_list *node);

void	sort_5(t_list **stack_a, t_list **stack_b);
void	sort_complex(t_list **a, t_list **b);

void	swap(t_list **stack);
void	push(t_list **stack_dest, t_list **stack_src);
void	rotate(t_list **stack);
void	reverse_rotate(t_list **stack);

void	sa(t_list **stack_a);
void	sb(t_list **stack_b);
void	ss(t_list **stack_a, t_list **stack_b);
void	pa(t_list **stack_a, t_list **stack_b);
void	pb(t_list **stack_a, t_list **stack_b);
void	ra(t_list **stack_a);
void	rb(t_list **stack_b);
void	rr(t_list **stack_b, t_list **stack_a);
void	rra(t_list **stack_a);
void	rrb(t_list **stack_b);
void	rrr(t_list **stack_a, t_list **stack_b);
#endif
