/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_complex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 16:41:40 by wfan              #+#    #+#             */
/*   Updated: 2023/05/08 16:41:49 by wfan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	closest_above(t_list **a, int n)
{
	int	k;
	int	i;
	int	top;
	int	tmp;

	top = ft_lst_content_at(*a, 0);
	if (top < 0 || n > max(*a))
		return (n);
	i = 0;
	k = max(*a);
	while (i < ft_lstsize(*a))
	{
		tmp = ft_lst_content_at(*a, i);
		if (tmp > n && tmp < k)
			k = tmp;
		i++;
	}
	return (k);
}

void	put_in_position(t_list **a, t_list **b)
{
	int	top_b;
	int	to_move;

	top_b = ft_lst_content_at(*b, 0);
	to_move = closest_above(a, top_b);
	//printf("top_b %d, to_mov %d\n", top_b, to_move);
	if (to_move == top_b && ft_lstsize(*a) > 0)
		to_move = min(*a);
	smart_rotate_a(a, to_move);
	pa(a, b);
}

int	find_index(t_list *stack, int n)
{
	int	i;
	int size;

	i = 0;
	size = ft_lstsize(stack);
	while (ft_lst_content_at(stack, i) != n && i < size)
		i++;
	return (size - i - 1);
}

void	sort_part(t_list **a, t_list **b)
{
	while (ft_lstsize(*b) > 0)
	{
		move_min_or_max_to_top(b);
		put_in_position(a, b);
	}
}

void	move_part(t_list **a, t_list **b, int min, int max)
{
	int	size;

	size = max - min + 1;
	while (size)
	{
		move_to_top(a, min, max);
		pb(a, b);
		size--;
	}
}

int	get_parts(t_list *a)
{
	int		parts;
	int		size;

	size = ft_lstsize(a);
	parts = size / CHUNK_MAX + 1;
	return (parts);
}

void	sort_complex(t_list **a, t_list **b)
{
	int		limit_min;
	int		limit_max;
	int		parts;
	int		step;

	parts = get_parts(*a);
	limit_max = max(*a);
	step = (ft_lstsize(*a) + 1) / parts;
	while (parts >= 1)
	{
		if (parts == 1)
			limit_min = min(*a);
		else
			limit_min = limit_max - step + 1;
		move_part(a, b, limit_min, limit_max);
		sort_part(a, b);
		limit_max = limit_min - 1;
		parts--;
	}
	smart_rotate_a(a, min(*a));
}