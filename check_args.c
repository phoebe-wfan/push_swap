/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 17:08:58 by wfan              #+#    #+#             */
/*   Updated: 2023/05/18 14:41:44 by wfan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error_exit(char **args, int argc)
{
	ft_putendl_fd("Error", 2);
	if (argc == 2)
		ft_free(args);
	exit(EXIT_FAILURE);
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
	if (ft_strlen(num) <= 0)
		return (0);
	if (num[0] == '-' || num[0] == '+')
	{	
		if (ft_strlen(num) == 1)
			return (0);
		else
			i++;
	}
	while (num[i])
	{
		if (!ft_isdigit(num[i]))
			return (0);
		i++;
	}
	return (1);
}

long	ft_atolong(const char *nptr)
{
	size_t			i;
	long			nbr;
	long			sign;
	unsigned char	*str;

	str = (unsigned char *)nptr;
	i = 0;
	nbr = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
	{
		nbr = nbr * 10;
		nbr = nbr + (str[i] - '0');
		i++;
	}
	return (nbr * sign);
}

void	ft_check_args(int argc, char **argv)
{
	int		i;
	long	tmp;
	char	**args;	

	i = 0;
	if (argc == 2)
		args = ft_split(argv[1], ' ');
	else
	{
		i = 1;
		args = argv;
	}
	if (!args[i])
		ft_error_exit(args, argc);
	while (args[i])
	{
		tmp = ft_atolong(args[i]);
		if ((!ft_isnum(args[i])) || ft_contains(tmp, args, i)
			|| (tmp < -2147483648 || tmp > 2147483647))
			ft_error_exit(args, argc);
		i++;
	}
	if (argc == 2)
		ft_free(args);
}
