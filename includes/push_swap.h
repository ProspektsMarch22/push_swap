/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icezar-s <icezar-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 16:43:32 by icezar-s          #+#    #+#             */
/*   Updated: 2026/02/04 16:20:57 by icezar-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/ft_printf/ft_printf.h"
#include "../src/libft/libft.h"
#include <stdbool.h>

// Operational Limit, can be changed for testing
#define MAX 500

// Data structures - I'll use stacks created inside queues.
typedef struct s_queue
{
	int	data[MAX];
	int	front;
	int	rear;
	int	size;
}	t_queue;

typedef struct s_stack
{
	t_queue	q;
}	t_stack;

// DS functions
// Queue functions
void	init_queue(t_queue *q);
bool	is_queue_empty(t_queue *q);
void	enqueue(t_queue *q, int val);
int		dequeue(t_queue *q);
int		peek(t_queue *q);

// Stack functions
t_stack	*create_stack(void);
void	stack_push(t_stack *stack, int x);
int		stack_pop(t_stack *stack);
int		stack_top(t_stack *stack);
void	stack_free(t_stack *stack);

// push_swap operations
void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);
