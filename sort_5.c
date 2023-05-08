/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 14:39:21 by wfan              #+#    #+#             */
/*   Updated: 2023/05/05 14:39:24 by wfan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_index(t_list **stack, int nbr)
{
	int		index;
	t_list	*ptr;
	int		lstsize;

	index = 0;
	ptr = *stack;
	lstsize = ft_lstsize(ptr);
	while ((*(int *)(ptr->content)) != nbr && index < lstsize)
		index++;
	return (index);
}

void	sort_3(t_list **stack_a)
{
	int		one;
	int		two;
	int		three;
	t_list	*tmp;

	one = *((int *)(*stack_a)->content);
	two = *((int *)(*stack_a)->next->content);
	tmp = ft_lstlast(*stack_a);
	three = *((int *)tmp->content);
	if (one > two && one < three && two < three)
		sa(stack_a);
	else if (one < two && two < three && one < three)
	{
		sa(stack_a);
		rra(stack_a);
	}
	else if (one > two && two < three && one > three)
		ra(stack_a);
	else if (one < two && two > three && one < three)
	{
		sa(stack_a);
		ra(stack_a);
	}
	else if (one < two && two > three && one > three)
		rra(stack_a);
}

static void	put_in_order(t_list **stack_a, t_list **stack_b, int order)
{
	if (order == 0 || order == 1)
		pa(stack_a, stack_b);
	if (order == 1)
		sa(stack_a);
	else if (order == ft_lstsize(*stack_a) - 1)
	{
		rra(stack_a);
		pa(stack_a, stack_b);
		ra(stack_a);
		ra(stack_a);
	}
	else if (order == ft_lstsize(*stack_a))
	{
		pa(stack_a, stack_b);
		ra(stack_a);
	}
	else if (order != 0)
	{
		ra(stack_a);
		pa(stack_a, stack_b);
		sa(stack_a);
		rra(stack_a);
	}
}

static int	find_b_order_in_a(t_list *stack_a, int elem_b)
{
	int	order;
	int	len_a;

	order = 0;
	len_a = ft_lstsize(stack_a);
	while (len_a && elem_b > *((int *)stack_a->content))
	{
		stack_a = stack_a->next;
		order++;
		len_a--;
	}
	return (order);
}

void	sort_5(t_list **stack_a, t_list **stack_b)
{
	int	order;

	while (ft_lstsize(*stack_a) > 3)
		pb(stack_a, stack_b);
	sort_3(stack_a);
	while (ft_lstsize(*stack_b) > 0)
	{	
		order = find_b_order_in_a(*stack_a, *((int *)(*stack_b)->content));
		put_in_order(stack_a, stack_b, order);
	}
}
