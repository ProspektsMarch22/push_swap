/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icezar-s <icezar-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 14:57:50 by icezar-s          #+#    #+#             */
/*   Updated: 2026/02/10 18:16:11 by icezar-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int main(int argc, char *argv[])
{
	t_stack	*a;
	char	**args;
	int	i;

	a = create_stack();
	if (argc > 2)
	{
		args = (char **)ft_calloc((size_t)(argc - 1), (sizeof(char *) * argc));
		if (!args)
			exit(EXIT_FAILURE);
		i = 0;
		while (++i < argc)
			args[i - 1] = ft_strdup(argv[i]);
		parse_args(args, a);
		ft_printf("%d\n", stack_top(a));
		free(a);
	}
	return (0);
}
