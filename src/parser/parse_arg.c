/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icezar-s <icezar-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 18:04:35 by icezar-s          #+#    #+#             */
/*   Updated: 2026/03/08 02:04:01 by icezar-s         ###   ########.fr       */
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

static void	exit_error(t_stack *a, t_stack *b, char **args, int i)
{
	ft_putstr_fd("Error\n", 2);
	while (i >= 0)
	{
		free(args[i]);
		i--;
	}
	free(args);
	free(a);
	free(b);
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

void	parse_arg(char *arg, t_stack *a, t_stack *b)
{
	char	**elements;
	long	lnbr;
	int		i;

	elements = ft_split(arg, 32);
	i = 0;
	while (elements[i])
		i++;
	i = i - 1;
	while (i >= 0 && elements[i])
	{
		if (!check_valid_str(elements[i]))
			exit_error(a, b, elements, i);
		lnbr = ft_atol(elements[i]);
		if (lnbr > INT_MAX || lnbr < INT_MIN
			|| has_duplicate((int)lnbr, a))
			exit_error(a, b, elements, i);
		stack_push(a, (int)lnbr);
		free(elements[i]);
		i--;
	}
	free(elements);
}

void	parse_args(char **args, int argc, t_stack *a, t_stack *b)
{
	long	lnbr;
	int		i;

	i = argc - 2;
	while (i >= 0 && args[i])
	{
		if (!check_valid_str(args[i]))
			exit_error(a, b, args, i);
		lnbr = ft_atol(args[i]);
		if (lnbr > INT_MAX || lnbr < INT_MIN
			|| has_duplicate((int)lnbr, a))
			exit_error(a, b, args, i);
		stack_push(a, (int)lnbr);
		free(args[i]);
		i--;
	}
	free(args);
}
