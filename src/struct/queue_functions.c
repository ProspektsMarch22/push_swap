/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icezar-s <icezar-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 15:52:01 by icezar-s          #+#    #+#             */
/*   Updated: 2026/02/04 15:08:46 by icezar-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	init_queue(t_queue *q)
{
	q->front = 0;
	q->rear = -1;
	q->size = 0;
}

bool	is_queue_empty(t_queue *q)
{
	return (q->size == 0);
}

void	enqueue(t_queue *q, int val)
{
	if (q->size == MAX)
	{
		ft_printf("Queue overflow\n");
		exit(EXIT_FAILURE);
	}
	q->rear = (q->rear + 1) % MAX;
	q->data[q->rear] = val;
	q->size += 1;
}

int	dequeue(t_queue *q)
{
	int	val;

	if (is_queue_empty(q))
	{
		ft_printf("Queue underflow\n");
		exit(EXIT_FAILURE);
	}
	val = q->data[q->front];
	q->front = (q->front + 1) % MAX;
	q->size -= 1;
	return (val);
}

int	peek(t_queue *q)
{
	if (is_queue_empty(q))
	{
		ft_printf("Queue is empty\n");
		exit(EXIT_FAILURE);
	}
	return (q->data[q->front]);
}
