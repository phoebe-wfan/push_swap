/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smart.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 17:16:09 by wfan              #+#    #+#             */
/*   Updated: 2023/05/14 17:16:22 by wfan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	run_n(void (*op)(t_list **a, t_list **b), t_list **stack_a, t_list **stack_b, int n)
{
	if (n <= 0)
		return ;
	op(stack_a, stack_b);
	run_n(op, stack_a, stack_b, n - 1);
}

void	smart_rotate_a(t_list **a, int n)
{
	int	find;

	find = ft_lstsize(*a) - 1;
	// printf("sra n %d, find %d\n", n, find);
	while (find >= 0 && ft_lst_content_at(*a, find) != n)
		find--;
	// printf("sra n %d, find %d\n", n, find);
	if (find < 0)
		return ;
	else if (find < (ft_lstsize(*a) - 1) / 2)
		run_n(&rra, a, NULL, find + 1);
	else
		run_n(&ra, a, NULL, ft_lstsize(*a) - 1 - find);
}

void	smart_rotate_b(t_list **b, int n)
{
	int	find;

	find = ft_lstsize(*b) - 1;
	// printf("srb n %d, find %d\n", n, find);
	while (find >= 0 && ft_lst_content_at(*b, find) != n)
		find--;
	// printf("srb n %d, find %d\n", n, find);
	if (find < 0)
		return ;
	else if (find < (ft_lstsize(*b) - 1) / 2)
		run_n(&rrb, NULL, b, find + 1);
	else
		run_n(&rb, NULL, b, ft_lstsize(*b) - 1 - find);
}