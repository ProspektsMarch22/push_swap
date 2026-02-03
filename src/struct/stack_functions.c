/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icezar-s <icezar-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 16:09:51 by icezar-s          #+#    #+#             */
/*   Updated: 2026/02/03 16:24:25 by icezar-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

s_stack *createStack(void)
{
    s_stack *stack;

    stack = (s_stack *)malloc(sizeof(s_stack));
    if (!stack)
        return ((void *)0);
    initQueue(&stack->q);
    return (stack);
}

void    stackPush(s_stack *stack, int x)
{
    int rotation;

    enqueue(&stack->q, x);
    rotation = stack->q.size - 1;
    while (rotation)
    {
        enqueue(&stack->q, dequeue(&stack->q));
        rotation--;
    }
}

int stackPop(s_stack *stack)
{
    return (dequeue(&stack->q));
}

int stackTop(s_stack *stack)
{
    return (peek(&stack->q));
}

void    stackFree(s_stack *stack)
{
    free(stack);
}