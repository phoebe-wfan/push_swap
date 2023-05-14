/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max_min_mid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 16:55:58 by wfan              #+#    #+#             */
/*   Updated: 2023/05/08 16:56:10 by wfan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	max(t_list *stack)
{
	int	tmp;

	if (!stack->next)
		return (*((int *)stack->content));
	else
	{
		tmp = max(stack->next);
		if (*((int *)stack->content) > tmp)
			return (*((int *)stack->content));
		else
			return (tmp);
	}
}

int	min(t_list *stack)
{
	int	tmp;

	if (!stack->next)
		return (*((int *)stack->content));
	else
	{
		tmp = min(stack->next);
		if (*((int *)stack->content) < tmp)
			return (*((int *)stack->content));
		else
			return (tmp);
	}
}