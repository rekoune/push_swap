/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arekoune <arekoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 01:26:47 by arekoune          #+#    #+#             */
/*   Updated: 2024/04/18 21:48:14 by arekoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list **stack, char c, int a)
{
	int		size;
	t_list	*head;
	t_list	*node;

	head = *stack;
	node = *stack;
	size = list_size(*stack);
	if (size > 1)
	{
		*stack = node->next;
		node = node->next;
		head->next = node->next;
		node->next = head;
		if (a > 0)
		{
			write(1, "s", 1);
			write(1, &c, 1);
			write(1, "\n", 1);
		}
	}
}

void	swap_a_b(t_list **stack_a, t_list **stack_b, int a)
{
	swap(stack_a, 'a', 0);
	swap(stack_b, 'b', 0);
	if (a > 0)
		write(1, "ss\n", 3);
}

void	push(t_list **stack_1, t_list **stack_2, char c, int a)
{
	t_list	*head_1;
	t_list	*head_2;
	t_list	*node_1;

	head_1 = *stack_1;
	head_2 = *stack_2;
	node_1 = *stack_1;
	if (list_size(*stack_2) > 0)
	{
		*stack_1 = head_2;
		*stack_2 = head_2->next;
		head_2->next = node_1;
		if (a == 1)
		{
			write(1, "p", 1);
			write(1, &c, 1);
			write(1, "\n", 1);
		}
	}
}

void	rotate(t_list **head, char c, int a)
{
	t_list	*node;
	t_list	*first_node;

	node = *head;
	first_node = *head;
	if (list_size(*head) > 1)
	{
		*head = node->next;
		while (first_node->next)
			first_node = first_node->next;
		first_node->next = node;
		node->next = NULL;
		if (a > 0)
		{
			write(1, "r", 1);
			write(1, &c, 1);
			write(1, "\n", 1);
		}
	}
}

void	rotate_a_b(t_list **stack_a, t_list **stack_b, int a)
{
	rotate(stack_a, 'a', 0);
	rotate(stack_b, 'b', 0);
	if (a > 0)
		write(1, "rr\n", 3);
}
