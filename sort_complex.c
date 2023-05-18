/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_complex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 16:41:40 by wfan              #+#    #+#             */
/*   Updated: 2023/05/18 15:09:36 by wfan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	max_bits(t_list *a)
{
	int	max_num;
	int	max_bits;

	max_num = ft_lstsize(a) - 1;
	max_bits = 0;
	while ((max_num >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

void	sort_complex(t_list **a, t_list **b)
{
	int	i;
	int	j;
	int	num;
	int	size;
	int	max_b;

	i = -1;
	size = ft_lstsize(*a);
	max_b = max_bits(*a);
	while (++i < max_b)
	{
		j = -1;
		while (++j < size)
		{
			num = ft_lst_content_at(*a, 0);
			if (((num >> i) & 1) == 1)
				ra(a, b);
			else
				pb(a, b);
		}
		while (*b)
			pa(a, b);
	}
}
