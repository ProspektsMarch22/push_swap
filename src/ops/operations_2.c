/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icezar-s <icezar-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 13:42:04 by icezar-s          #+#    #+#             */
/*   Updated: 2026/02/09 14:25:20 by icezar-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ra(t_stack *a)
{
	int	tmp;

	if (a->q.size <= 1)
		return ;
	tmp = stack_pop(a);
	enqueue(&a->q, tmp);
	ft_printf("ra\n");
}

void	rb(t_stack *b)
{
	int	tmp;

	if (b->q.size <= 1)
		return ;
	tmp = stack_pop(b);
	enqueue(&b->q, tmp);
	ft_printf("rb\n");
}

void	rr(t_stack *a, t_stack *b)
{
	int	tmp1;
	int	tmp2;

	if (a->q.size <= 1 || b->q.size <= 1)
		return ;
	tmp1 = stack_pop(a);
	tmp2 = stack_pop(b);
	enqueue(&a->q, tmp1);
	enqueue(&b->q, tmp2);
	ft_printf("rr\n");
}
