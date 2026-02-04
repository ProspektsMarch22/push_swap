/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icezar-s <icezar-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 17:28:07 by icezar-s          #+#    #+#             */
/*   Updated: 2026/02/04 17:28:13 by icezar-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	sa(t_stack *a)
{
	int	tmp;

	if (a->q.size <= 1)
		return ;
	tmp = stack_top(a);
	a->q.data[a->q.front] = a->q.data[a->q.front + 1];
	a->q.data[a->q.front + 1] = tmp;
	ft_printf("sa\n");
}

void	sb(t_stack *b)
{
	int	tmp;

	if (b->q.size <= 1)
		return ;
	tmp = stack_top(b);
	b->q.data[b->q.front] = b->q.data[b->q.front + 1];
	b->q.data[b->q.front + 1] = tmp;
	ft_printf("sb\n");
}

void	ss(t_stack *a, t_stack *b)
{
	int	tmp_a;
	int	tmp_b;

	if (a->q.size <= 1 || b->q.size <= 1)
		return ;
	tmp_a = stack_top(a);
	tmp_b = stack_top(b);
	a->q.data[a->q.front] = a->q.data[a->q.front + 1];
	a->q.data[a->q.front + 1] = tmp_a;
	b->q.data[b->q.front] = b->q.data[b->q.front + 1];
	b->q.data[b->q.front + 1] = tmp_b;
	ft_printf("ss\n");
}

void	pa(t_stack *a, t_stack *b)
{
	stack_push(a, stack_pop(b));
	ft_printf("pa\n");
}

void	pb(t_stack *a, t_stack *b)
{
	stack_push(b, stack_pop(a));
	ft_printf("pb\n");
}
