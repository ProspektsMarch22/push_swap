/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icezar-s <icezar-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 14:57:50 by icezar-s          #+#    #+#             */
/*   Updated: 2026/02/04 14:26:55 by icezar-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int main(void)
{
    t_stack *a;

    a = create_stack();
    stack_push(a, 21);
    stack_push(a, 42);
    ft_printf("%d\n", stack_pop(a));
    ft_printf("%d\n", stack_top(a));
    ft_printf("%d\n", stack_pop(a));
    stack_free(a);
    return (0);
}
