/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icezar-s <icezar-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 14:57:50 by icezar-s          #+#    #+#             */
/*   Updated: 2026/03/06 22:53:35 by icezar-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	handler(t_stack *a, t_stack *b)
{
	int	size;

	size = a->q.size;
	if (size == 0 || size == 1)
		return ;
	else if (size <= 3)
		return (juggler_3(a));
	else if (size <= 5)
		return (juggler_5(a, b));
	else
		return (butterfly_sort(a, b, size));
}

int	main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*b;
	char	**args;
	int		i;

	a = create_stack();
	b = create_stack();
	if (argc > 2)
	{
		args = (char **)ft_calloc((size_t)(argc - 1), (sizeof(char *) * argc));
		if (!args)
			exit(EXIT_FAILURE);
		i = 0;
		while (++i < argc)
			args[i - 1] = ft_strdup(argv[i]);
		parse_args(args, argc, a);
	}
	else
		parse_arg(argv[1], a);
	numbers_to_ranked(a);
	handler(a, b);
	free(a);
	free(b);
	return (0);
}
