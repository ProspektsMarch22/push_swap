/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icezar-s <icezar-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 16:09:51 by icezar-s          #+#    #+#             */
/*   Updated: 2026/02/04 14:18:49 by icezar-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_stack	*create_stack(void)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		return ((void *)0);
	init_queue(&stack->q);
	return (stack);
}

void	stack_push(t_stack *stack, int x)
{
	int	rotation;

	enqueue(&stack->q, x);
	rotation = stack->q.size - 1;
	while (rotation)
	{
		enqueue(&stack->q, dequeue(&stack->q));
		rotation--;
	}
}

int	stack_pop(t_stack *stack)
{
	return (dequeue(&stack->q));
}

int	stack_top(t_stack *stack)
{
	return (peek(&stack->q));
}

void	stack_free(t_stack *stack)
{
	free(stack);
}
