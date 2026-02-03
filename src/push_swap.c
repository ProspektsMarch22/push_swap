/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icezar-s <icezar-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 14:57:50 by icezar-s          #+#    #+#             */
/*   Updated: 2026/02/03 16:26:46 by icezar-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int main(void)
{
    s_stack *a;

    a = createStack();
    stackPush(a, 21);
    stackPush(a, 42);
    ft_printf("%d\n", stackPop(a));
    ft_printf("%d\n", stackTop(a));
    ft_printf("%d\n", stackPop(a));
    stackFree(a);
    return (0);
}