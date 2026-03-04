/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icezar-s <icezar-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 19:13:14 by icezar-s          #+#    #+#             */
/*   Updated: 2026/03/04 22:02:02 by icezar-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void case_0(t_stack *a)
{
	rra(a);
	sa(a);
	return ;
}

static void case_1(t_stack *a)
{
	if (a->q.data[a->q.front + 1] == 0)
	{
		sa(a);
		return ;
	}
	rra(a);
	return ;
}

static void case_2(t_stack *a)
{
	if (a->q.data[a->q.front + 1] == 0)
	{
		ra(a);
		return ;
	}
	sa(a);
	rra(a);
	return ;
}

void	juggler_3(t_stack *a)
{
	if (!check_sorted(a))
	{
		if (a->q.size == 2 && stack_top(a) == 1)
			return (sa(a));
		if (stack_top(a) == 0)
			return (case_0(a));
		else if (stack_top(a) == 1)
			return (case_1(a));
		return (case_2(a));
	}
}
