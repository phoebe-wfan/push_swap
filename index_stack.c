/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 15:24:30 by wfan              #+#    #+#             */
/*   Updated: 2023/05/08 15:24:32 by wfan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*ft_lst_content_at(t_list *lst, int index)
{
	int	i;
	int size;

	i = 0;
	if (!lst)
		return (NULL);
	size = ft_lstsize(lst);
	while (i != index && i < size)
	{
		lst = lst->next;
		i++;
	}
	return (lst->content);
}

t_list	*ft_lst_at(t_list *lst, int index)
{
	int	i;
	int	size;

	i = 0;
	if (!lst)
		return (NULL);
	size = ft_lstsize(lst);
	while ((i != index) && (i < size))
	{
		lst = lst->next;
		i++;
	}
	return (lst);
}

void	insertion_sort(int array[], int size)
{
	int				i;
	int				j;
	int				key;

	j = 1;
	while (j < size)
	{
		i = j - 1;
		key = array[j++];
		while (i >= 0 && array[i + 1] < array[i])
		{
			array[i + 1] = array[i];
			array[i--] = key;
		}
	}
}

int *stack_array_alloc(t_list *stack)
{
	int		size;
	int		*array;
	int		i;

	i = 0;
	size = ft_lstsize(stack);
	array = malloc(size * sizeof(int));
	while (i < size)
	{
		array[i] = *((int *)ft_lst_content_at(stack, i));
		i++;
	}
	return (array);
}

static int	*sorted_array_copy(t_list *stack)
{
	int		*copy;
	int		size;

	size = ft_lstsize(stack);
	copy = stack_array_alloc(stack);
	insertion_sort(copy, size);
	return (copy);
}

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
		while (sorted_array[pos] != *((int *)ft_lst_content_at(*stack, i)))
			pos++;
		array_index[i++] = pos;
	}
	array_copy_stack(*stack, array_index);
	free(sorted_array);
	free(array_index);
}

