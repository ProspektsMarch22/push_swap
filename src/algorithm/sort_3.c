/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaiva <lpaiva@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 19:13:14 by icezar-s          #+#    #+#             */
/*   Updated: 2026/03/08 00:47:33 by lpaiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	juggler_3(t_stack *a)
{
	int	top;
	int	mid;
	int	bot;

	top = a->q.data[a->q.front];
	mid = a->q.data[(a->q.front + 1) % MAX];
	bot = a->q.data[(a->q.front + 2) % MAX];
	if (top > mid && top < bot && mid < bot)
		sa(a);
	else if (top > mid && mid > bot)
	{
		sa(a);
		rra(a);
	}
	else if (top > mid && mid < bot && top > bot)
		ra(a);
	else if (top < mid && top < bot && mid > bot)
	{
		sa(a);
		ra(a);
	}
	else if (top < mid && top > bot && mid > bot)
		rra(a);
}
