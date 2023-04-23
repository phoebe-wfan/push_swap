/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 17:09:55 by wfan              #+#    #+#             */
/*   Updated: 2023/04/02 17:09:59 by wfan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free (str[i]);
		i++;
	}
	free (str);
}

int	is_sorted(t_list **stack)
{
	t_list	*top;

	top = *stack;
	while (top && top->next)
	{
		if (*((int *)(top->content)) > *((int *)(top->next->content)))
			return (0);
		top = top->next;
	}
	return (1);
}

int	is_sorted_reverse(t_list **stack)
{
	t_list	*top;

	top = *stack;
	while (top && top->next)
	{
		if (*((int *)(top->content)) < *((int *)(top->next->content)))
			return (0);
		top = top->next;
	}
	return (1);
}

void	free_stack(t_list **stack)
{
	t_list	*top;
	t_list	*tmp;

	top = *stack;
	while (top)
	{
		tmp = top;
		free(tmp->content);
		top = top->next;
		free(tmp);
	}
	free(stack);
}
