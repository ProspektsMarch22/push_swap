/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icezar-s <icezar-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 17:53:44 by icezar-s          #+#    #+#             */
/*   Updated: 2026/02/10 18:10:54 by icezar-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	numbers_to_ranked(t_stack *a)
{
	int	i;
	int	j;
	int	count_smaller;
	int	*ranks;

	ranks = (int *)malloc(sizeof(int) * (a->q.size));
	if (!ranks)
		exit(EXIT_FAILURE);
	i = 0;
	while (i < a->q.size)
	{
		j = 0;
		count_smaller = 0;
		while (j < a->q.size)
			if (a->q.data[j++] <= a->q.data[i])
				count_smaller++;
		ranks[i] = count_smaller;
		i++;
	}
	i = -1;
	while (++i < a->q.size)
		a->q.data[a->q.front - i] = ranks[i];
}
