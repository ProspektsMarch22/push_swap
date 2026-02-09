/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icezar-s <icezar-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 14:57:50 by icezar-s          #+#    #+#             */
/*   Updated: 2026/02/09 15:16:05 by icezar-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int main(int argc, char *argv[])
{
	t_stack	*a;

	if (argc == 2 && *argv[1])
	{
		a = create_stack();
		parse_arg(argv[1], a);
		ft_printf("%d\n", stack_top(a));
		rra(a);
		rra(a);
		ft_printf("%d\n", stack_top(a));
		ft_printf("%d\n", a->q.data[a->q.rear]);
		stack_free(a);
	}
	return (0);
}
