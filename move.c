/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 15:39:26 by wfan              #+#    #+#             */
/*   Updated: 2023/05/14 15:39:43 by wfan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	between(int n, int min, int max)
{
	return (n >= min && n <= max);
}

static int	find_from_top(t_list **a, int min, int max)
{
	int	i;

	i = 0;
	while (i < ft_lstsize(*a))
	{
		if (between(*((int *)ft_lst_content_at(*a, i)), min, max))
			return (i);
		i++;
	}
	return (-1);
}

static int	find_from_bottom(t_list **a, int min, int max)
{
	int	i;

	i = ft_lstsize(*a) - 1;
	while (i >= 0)
	{
		if (between(*((int *)ft_lst_content_at(*a, i)), min, max))
			return (i);
		i--;
	}
	return (-1);
}

void	move_to_top(t_list **a, int min, int max)
{
	int	i;
	int	index_top;
	int	index_bottom;

	index_top = find_from_top(a, min, max);
	index_bottom = find_from_bottom(a, min, max);
	if (index_top < ft_lstsize(*a) - index_bottom)
		i = index_top;
	else
		i = index_bottom;
	smart_rotate(a, *((int *)ft_lst_content_at(*a, i)), 0);
}

void	move_min_or_max_to_top(t_list **b)
{
	int	i;
	int	index_max;
	int	index_min;

	index_min = find_index(*b, min(*b));
	index_max = find_index(*b, max(*b));
	if (index_min < ft_lstsize(*b) - index_max)
		i = index_min;
	else
		i = index_max;
	smart_rotate(b, *((int *)ft_lst_content_at(*b, i)), 0);
}