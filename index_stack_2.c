/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_stack_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 14:47:24 by wfan              #+#    #+#             */
/*   Updated: 2023/05/18 15:03:43 by wfan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	array_copy_stack(t_list *stack, int *array)
{
	int		i;
	int		size;
	t_list	*tmp;

	i = 0;
	size = ft_lstsize(stack);
	while (i < size)
	{
		tmp = ft_lst_at(stack, i);
		*((int *)tmp->content) = array[i];
		i++;
	}
}

void	index_stack(t_list **stack)
{
	int		*sorted_array;
	int		i;
	int		pos;
	int		*array_index;
	int		size;

	i = 0;
	size = ft_lstsize(*stack);
	array_index = stack_array_alloc(*stack);
	sorted_array = sorted_array_copy(*stack);
	while (i < size)
	{
		pos = 0;
		while (sorted_array[pos] != ft_lst_content_at(*stack, i))
			pos++;
		array_index[i++] = pos;
	}
	array_copy_stack(*stack, array_index);
	free(sorted_array);
	free(array_index);
}
