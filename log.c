/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 16:21:12 by wfan              #+#    #+#             */
/*   Updated: 2023/05/08 16:24:31 by wfan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void print_stack(t_list *node)
{
	t_list *tmp;
	printf("print stack: ");
	tmp = node;
	while (tmp)
	{
		printf("%d ", *((int *)tmp->content));
		tmp = tmp->next;
	}
	printf("\n print stack\n");
}
