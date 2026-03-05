/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icezar-s <icezar-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 01:12:25 by icezar-s          #+#    #+#             */
/*   Updated: 2026/03/05 02:37:39 by icezar-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int	get_min_pos(t_stack *a)
{
	int	min;
	int	i;
	int	pos;
	int	idx;

	min = stack_top(a);
	i = 0;
	pos = 1;
	while (i < a->q.size)
	{
		idx = (a->q.front + i) % MAX;
		if (a->q.data[idx] < min)
		{
			min = a->q.data[idx];
			pos++;
		}
		i++;
	}
	return (pos);
}

static void	pb_min(t_stack *a, t_stack *b)
{
	int	min_pos;

	min_pos = get_min_pos(a);
	if (min_pos <= ((a->q.size) / 2))
		while (get_min_pos(a) != 1)
			ra(a);
	else
		while (get_min_pos(a) != 1)
			rra(a);
	pb(a, b);
}

void	juggler_5(t_stack *a, t_stack *b)
{
	if (!check_sorted(a))
	{
		if (a->q.size == 4)
		{
			pb_min(a, b);
			juggler_3(a);
			pa(a, b);
		}
		else if (a->q.size == 5)
		{
			pb_min(a, b);
			pb_min(a, b);
			juggler_3(a);
			pa(a, b);
			pa(a, b);
		}
	}
}
