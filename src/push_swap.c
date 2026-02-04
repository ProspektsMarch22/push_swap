/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icezar-s <icezar-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 14:57:50 by icezar-s          #+#    #+#             */
/*   Updated: 2026/02/04 16:25:54 by icezar-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int main(void)
{
	t_stack	*a;
	t_stack *b;

	a = create_stack();
	b = create_stack();
	stack_push(a, 2);
	stack_push(a, 4);
	stack_push(a, 6);
	stack_push(b, 1);
	stack_push(b, 3);
	stack_push(b, 5);
	pb(a, b);
	ft_printf("%d\n", stack_top(b));
	sb(b);
	ft_printf("%d\n", stack_top(b));
	sb(b);
	ft_printf("%d\n", stack_top(b));
	stack_free(a);
	stack_free(b);
    return (0);
}
