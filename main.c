/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 17:58:44 by wfan              #+#    #+#             */
/*   Updated: 2023/04/28 16:28:28 by wfan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*ft_atoi_ptr(const char *nptr)
{
	int	nbr;
	int	*ptr;

	nbr = ft_atoi(nptr);
	ptr = malloc(sizeof(int));
	*ptr = nbr;
	return (ptr);
}

static int	get_min_value(t_list **stack)
{	
	t_list	*top;
	int		min;

	top = *stack;
	min = *((int *)(top->content));
	while (top)
	{
		if (*((int *)(top->content)) < min)
			min = *((int *)(top->content));
		top = top->next;
	}
	return (min);
}

void	ft_sort(t_list **stack_a, t_list **stack_b)
{
	t_list	*top_a;
	int		min_value;

	top_a = *stack_a;
	while (ft_lstsize(*stack_a) != 0)
	{
		min_value = get_min_value(stack_a);
		top_a = *stack_a;
		if (*((int *)(top_a->content)) == min_value)
			pb(stack_a, stack_b);
		else
			ra(stack_a);
	}
	while (ft_lstsize(*stack_b) != 0)
		pa(stack_a, stack_b);
}

static void	initstack(t_list **stack, int argc, char **argv)
{
	t_list	*new;
	char	**args;
	int		i;

	i = 1;
	if (argc == 2)
		args = ft_split(argv[1], ' ');
	else
		args = argv;
	while (args[i])
	{
		new = ft_lstnew((void *)ft_atoi_ptr(args[i]));
		ft_lstadd_back(stack, new);
		i++;
	}
	if (argc == 2)
		ft_free(args);
}

int	main(int argc, char **argv)
{
	t_list	**stack_a;
	t_list	**stack_b;

	if (argc < 2)
		return (-1);
	ft_check_args(argc, argv);
	stack_a = (t_list **)malloc(sizeof(t_list));
	stack_b = (t_list **)malloc(sizeof(t_list));
	*stack_a = NULL;
	*stack_b = NULL;
	initstack(stack_a, argc, argv);
	if (is_sorted(stack_a))
	{
		free_stack(stack_a);
		free_stack(stack_b);
		return (0);
	}
	ft_sort(stack_a, stack_b);
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}
