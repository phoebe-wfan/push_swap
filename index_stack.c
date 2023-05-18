/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 15:24:30 by wfan              #+#    #+#             */
/*   Updated: 2023/05/18 15:04:11 by wfan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lst_content_at(t_list *lst, int index)
{
	int	i;
	int	size;

	i = 0;
	if (!lst)
		return (-1);
	size = ft_lstsize(lst);
	while (i != index && i < size)
	{
		lst = lst->next;
		i++;
	}
	return (*((int *)lst->content));
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

int	*stack_array_alloc(t_list *stack)
{
	int		size;
	int		*array;
	int		i;

	i = 0;
	size = ft_lstsize(stack);
	array = malloc(size * sizeof(int));
	while (i < size)
	{
		array[i] = ft_lst_content_at(stack, i);
		i++;
	}
	return (array);
}

int	*sorted_array_copy(t_list *stack)
{
	int		*copy;
	int		size;

	size = ft_lstsize(stack);
	copy = stack_array_alloc(stack);
	insertion_sort(copy, size);
	return (copy);
}
