/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   butterfly_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icezar-s <icezar-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 20:07:51 by icezar-s          #+#    #+#             */
/*   Updated: 2026/03/06 22:50:58 by icezar-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int	get_max_pos(t_stack *stack)
{
	int	i;
	int	max;
	int	pos;
	int	idx;

	max = stack_top(stack);
	i = 0;
	pos = 0;
	while (i < stack->q.size)
	{
		idx = (stack->q.front + i) % MAX;
		if (stack->q.data[idx] > max)
		{
			max = stack->q.data[idx];
			pos = i;
		}
		i++;
	}
	return (pos);
}

static void	push_b_in_chunks(t_stack *a, t_stack *b, int size)
{
	int	chunk;
	int	count;

	count = 0;
	if (size <= 100)
		chunk = 15;
	else
		chunk = 35;
	while (a->q.size)
	{
		if (stack_top(a) <= count)
		{
			pb(a, b);
			rb(b);
			count++;
		}
		else if (stack_top(a) <= count + chunk)
		{
			pb(a, b);
			count++;
		}
		else
			ra(a);
	}
}

static void	move_max_top(t_stack *b, int size)
{
	int	pos;
	int	max_val;

	pos = get_max_pos(b);
	max_val = b->q.data[(b->q.front + pos) % MAX];
	if (pos == 1)
		return (sb(b));
	if (pos <= size / 2)
		while (stack_top(b) != max_val)
			rb(b);
	else
		while (stack_top(b) != max_val)
			rrb(b);
}

void	butterfly_sort(t_stack *a, t_stack *b, int size)
{
	int	max;
	int	max_val;

	push_b_in_chunks(a, b, size);
	while (b->q.size)
	{
		max = get_max_pos(b);
		max_val = b->q.data[(b->q.front + max) % MAX];
		if (b->q.size > 1 && stack_top(b) == (max_val - 1))
		{
			pa(a, b);
			move_max_top(b, b->q.size);
			pa(a, b);
			sa(a);
		}
		else
		{
			move_max_top(b, b->q.size);
			pa(a, b);
		}
	}
}
