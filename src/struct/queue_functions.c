/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icezar-s <icezar-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 15:52:01 by icezar-s          #+#    #+#             */
/*   Updated: 2026/02/03 16:28:58 by icezar-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void    initQueue(s_queue *q)
{
    q->front = 0;
    q->rear = -1;
    q->size = 0;
}

bool    isQueueEmpty(s_queue *q)
{
    return (q->size == 0);
}

void    enqueue(s_queue *q, int val)
{
    if (q->size == MAX)
    {
        ft_printf("Queue overflow\n");
        return ;
    }
    q->rear = (q->rear + 1) % MAX;
    q->data[q->rear] = val;
    q->size += 1;
}

int dequeue(s_queue *q)
{
    int val;

    val = q->data[q->front];
    q->front = (q->front + 1) % MAX;
    q->size -= 1;
    return (val);
}

int peek(s_queue *q)
{
    return (q->data[q->front]);
}