/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 17:09:32 by wfan              #+#    #+#             */
/*   Updated: 2023/04/09 17:18:20 by wfan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list **stack)
{
	t_list	*tmp;

	if (ft_lstsize(*stack) > 1)
	{
		tmp = (*stack)->next;
		(*stack)->next = tmp->next;
		tmp->next = *stack;
		*stack = tmp;
	}
}

void	push(t_list **stack_dest, t_list **stack_src)
{
	t_list	*tmp;

	if (*stack_src)
	{
		tmp = (*stack_src)->next;
		(*stack_src)->next = *stack_dest;
		*stack_dest = *stack_src;
		*stack_src = tmp;
	}
}

void	rotate(t_list **stack)
{
	t_list	*tmp;

	if (ft_lstsize(*stack) > 1)
	{
		tmp = *stack;
		*stack = (*stack)->next;
		ft_lstlast(*stack)->next = tmp;
		tmp->next = NULL;
	}
}

void	reverse_rotate(t_list **stack)
{
	t_list	*tmp;
	t_list	*last;

	if (ft_lstsize(*stack) > 1)
	{
		last = ft_lstlast(*stack);
		tmp = *stack;
		while (tmp->next != last)
			tmp = tmp->next;
		tmp->next = NULL;
		last->next = *stack;
		*stack = last;
	}
}

void	sa(t_list **stack_a)
{
	swap(stack_a);
	ft_putendl_fd("sa", 1);
}
