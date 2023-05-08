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

	if (a->top < 0 || n > max(a))
		return (n);
	i = 0;
	k = max(a);
	while (i <= a->top)
	{
		if (a->array[i] > n && a->array[i] < k)
			k = a->array[i];
		i++;
	}
	return (k);
}

void	n_ops_arg1(void (*f)(t_list **x), t_list **stack, int n)
{
	if (n <= 0)
		return ;
	f(x);
	n_ops_arg1(f, stack, n - 1);
}

void	smart_rotate(t_list **stack, int nbr, int is_b)
{
	int	find;
	int	size;

	size = ft_lstsize(stack) - 1;
	find = size;
	while (*((int *)ft_lst_content_at(find)) != nbr && find >= 0)
		find--;
	if (find < 0)
		return ;
	else if (find < size / 2)
	{
		if (is_b)
			n_ops_arg1(&rrb, stack, find + 1);
		else
			n_ops_arg1(&rra, stack, find + 1);
	}
	else
	{
		if (is_b)
			n_ops_arg1(&rb, stack, size - find);
		else
			n_ops_arg1(&ra, stack, size - find);
	}
}

void	put_in_position(t_list **a, t_list **b)
{
	int	top_b;
	int	to_move;

	top_b = b->array[b->top];
	to_move = closest_above(a, top_b);
	if (to_move == top_b && a->top >= 0)
		to_move = min(*a);
	smart_rotate_a(a, to_move);
	pa(a, b)
}

void	sort_part(t_list **a, t_list **b)
{
	while (b->top >= 0)
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
	parts = (size + 1) / CHUNK_MAX + 1;
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
	smart_rotate_a(a, min(a));
}