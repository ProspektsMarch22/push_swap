/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icezar-s <icezar-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 14:57:50 by icezar-s          #+#    #+#             */
/*   Updated: 2026/03/06 20:25:05 by icezar-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*b;
	char	**args;
	int	i;

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
	ft_printf("%d\n", get_pos(a, 0));
	free(a);
	free(b);
	return (0);
}
