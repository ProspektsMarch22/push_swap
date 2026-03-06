/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   butterfly_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icezar-s <icezar-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 20:07:51 by icezar-s          #+#    #+#             */
/*   Updated: 2026/03/06 20:25:24 by icezar-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	get_pos(t_stack *stack, int target)
{
	int	i;
	int	pos;
	int	idx;

	i = -1;
	pos = 1;
	while (++i < stack->q.size)
	{
		idx = (stack->q.front + i) % MAX;
		if (stack->q.data[idx] == target)
			return (pos);
		pos++;
	}
	return (-1);
}
