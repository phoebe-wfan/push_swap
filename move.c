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
		if (between(ft_lst_content_at(*a, i), min, max))
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
		if (between(ft_lst_content_at(*a, i), min, max))
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
	// printf("index_top %d, index_bottom %d\n", index_top, index_bottom);
	if (index_top < ft_lstsize(*a) - 1 - index_bottom)
		i = index_top;
	else
		i = index_bottom;
	smart_rotate_a(a, ft_lst_content_at(*a, i));
}

void	move_min_or_max_to_top(t_list **b)
{
	int	i;
	int	index_max;
	int	index_min;

	index_min = find_index(*b, min(*b));
	index_max = find_index(*b, max(*b));
	// print_stack(*b);
	// printf("minb %d, maxb %d\n", min(*b), max(*b));
	// printf("index_min %d, index_max %d\n", index_min, index_max);
	if (index_min < ft_lstsize(*b) - 1 - index_max)
		i = index_min;
	else
		i = index_max;
	// printf("i=%d\n", i);
	smart_rotate_b(b, ft_lst_content_at(*b, i));
}