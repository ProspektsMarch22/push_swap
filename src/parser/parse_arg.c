/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icezar-s <icezar-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 18:04:35 by icezar-s          #+#    #+#             */
/*   Updated: 2026/02/09 16:59:33 by icezar-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static bool	check_valid_str(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		if (!ft_isdigit(str[i]) && str[i] != '-')
			return (false);
	return (true);
}

static void	exit_error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(EXIT_FAILURE);
}

static bool	has_duplicate(int nbr, t_stack *a)
{
	int	i;

	i = -1;
	while (++i < a->q.size)
		if (nbr == a->q.data[i])
			return (true);
	return (false);
}

void	parse_arg(char *arg, t_stack *a)
{
	char	**elements;
	long	lnbr;
	size_t	i;

	elements = ft_split(arg, 32);
	i = 0;
	while (elements[i])
	{
		if (!check_valid_str(elements[i]))
			exit_error();
		lnbr = ft_atol(elements[i]);
		if (lnbr > INT_MAX || lnbr < INT_MIN 
				|| has_duplicate((int)lnbr, a))
			exit_error();
		stack_push(a, (int)lnbr);
		free(elements[i]);
		i++;
	}
	free(elements);
}

void	parse_args(char **args, t_stack *a)
{
	long	lnbr;
	size_t	i;

	i = 0;
	while (args[i])
	{
		if (!check_valid_str(args[i]))
			exit_error();
		lnbr = ft_atol(args[i]);
		if (lnbr > INT_MAX || lnbr < INT_MIN 
				|| has_duplicate((int)lnbr, a))
			exit_error();
		stack_push(a, (int)lnbr);
		free(args[i]);
		i++;
	}
	free(args);
}
