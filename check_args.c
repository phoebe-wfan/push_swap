/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 17:08:58 by wfan              #+#    #+#             */
/*   Updated: 2023/04/28 16:29:03 by wfan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error_exit(char **args)
{
	ft_putendl_fd("Error", 2);
	ft_free(args);
	exit(EXIT_FAILURE);
}

void	print_list(t_list *top)
{
	t_list	*tmp;

	tmp = top;
	while (tmp != NULL)
	{
		ft_putnbr_fd(*((int *)(tmp->content)), 1);
		ft_putendl_fd("", 1);
		tmp = tmp->next;
	}
}

static int	ft_contains(int num, char **argv, int i)
{
	i++;
	while (argv[i])
	{
		if (ft_atoi(argv[i]) == num)
			return (1);
		i++;
	}
	return (0);
}

static int	ft_isnum(char *num)
{
	int	i;

	i = 0;
	if (num[0] == '-')
		i++;
	while (num[i])
	{
		if (!ft_isdigit(num[i]))
			return (0);
		i++;
	}
	return (1);
}

void	ft_check_args(int argc, char **argv)
{
	int		i;
	long	tmp;
	char	**args;	

	i = 1;
	if (argc == 2)
		args = ft_split(argv[1], ' ');
	else
	{
		i = 1;
		args = argv;
	}
	while (args[i])
	{
		tmp = ft_atoi(args[i]);
		if (!ft_isnum(args[i]))
			ft_error_exit(args);
		if (ft_contains(tmp, args, i))
			ft_error_exit(args);
		if (tmp < -2147483648 || tmp > 2147483647)
			ft_error_exit(args);
		i++;
	}
}
