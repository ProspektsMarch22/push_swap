/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icezar-s <icezar-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 16:43:32 by icezar-s          #+#    #+#             */
/*   Updated: 2026/02/03 16:24:39 by icezar-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/ft_printf/ft_printf.h"
#include "../src/libft/libft.h"
#include <stdbool.h>

// Operational Limit, can be changed for testing
#define MAX 500

// Data structures - I'll use stacks created inside queues.
typedef struct t_queue {
    int data[MAX];
    int front;
    int rear;
    int size;
}   s_queue;

typedef struct t_stack {
    s_queue q;
}   s_stack;

// DS functions

// Queue functions
void    initQueue(s_queue *q);
bool    isQueueEmpty(s_queue *q);
void    enqueue(s_queue *q, int val);
int     dequeue(s_queue *q);
int     peek(s_queue *q);

// Stack functions
s_stack *createStack(void);
void    stackPush(s_stack *stack, int x);
int     stackPop(s_stack *stack);
int     stackTop(s_stack *stack);
void    stackFree(s_stack *stack);