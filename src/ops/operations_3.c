/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icezar-s <icezar-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 14:12:56 by icezar-s          #+#    #+#             */
/*   Updated: 2026/02/09 14:50:59 by icezar-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	abandon_queue(t_queue *q)
{
	int	val;

	if (is_queue_empty(q))
	{
		ft_printf("Queue underflow\n");
		exit(EXIT_FAILURE);
	}
	val = q->data[q->rear];
	q->rear = q->rear - 1;
	q->size -= 1;
	return (val);
}

void	rra(t_stack *a)
{
	int	tmp;

	if (a->q.size <= 1)
		return ;
	tmp = abandon_queue(&a->q);
	stack_push(a, tmp);
	ft_printf("rra\n");
}

void	rrb(t_stack *b)
{
	int	tmp;

	if (b->q.size <= 1)
		return ;
	tmp = abandon_queue(&b->q);
	stack_push(b, tmp);
	ft_printf("rrb\n");
}

void	rrr(t_stack *a, t_stack *b)
{
	int	tmp1;
	int	tmp2;

	if (a->q.size <= 1 || b->q.size <= 1)
		return ;
	tmp1 = abandon_queue(&a->q);
	tmp2 = abandon_queue(&b->q);
	stack_push(a, tmp1);
	stack_push(b, tmp1);
	ft_printf("rrr\n");
}
