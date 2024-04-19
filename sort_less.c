/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_less.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arekoune <arekoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 16:40:50 by arekoune          #+#    #+#             */
/*   Updated: 2024/04/19 18:47:14 by arekoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_list **head)
{
	int		max;
	t_list	*node;

	max = max_index(*head);
	if ((*head)->index == max)
		rotate(head, 'a', 1);
	else if (position(*head, max) == 1)
		reverse_rotate(head, 'a', 1);
	node = (*head)->next;
	if ((*head)->index > node->index)
		swap(head, 'a', 1);
}

void	sort_5(t_list **stack_a, t_list **stack_b)
{
	while ((*stack_a)->index != 0)
	{
		if (position(*stack_a, 0) == 1 || position(*stack_a, 0) == 2)
			rotate(stack_a, 'a', 1);
		else
			reverse_rotate(stack_a, 'a', 1);
	}
	push(stack_b, stack_a, 'b', 1);
	while ((*stack_a)->index != 1)
	{
		if (position(*stack_a, 0) == 1 || position(*stack_a, 0) == 2)
			rotate(stack_a, 'a', 1);
		else
			reverse_rotate(stack_a, 'a', 1);
	}
	push(stack_b, stack_a, 'b', 1);
	sort_3(stack_a);
	push(stack_a, stack_b, 'a', 1);
	push(stack_a, stack_b, 'a', 1);
}

int	order_check(t_list *head)
{
	int		i;
	t_list	*node;

	i = list_size(head);
	node = head->next;
	while (i > 1 && (head->nbr < node->nbr))
	{
		i--;
		head = head->next;
		node = head->next;
	}
	if (i > 1)
		return (1);
	else
		return (0);
}

int	repetation(t_list *head)
{
	t_list	*node;

	while (head)
	{
		node = head->next;
		while (node)
		{
			if (head->nbr == node->nbr)
				return (0);
			node = node->next;
		}
		head = head->next;
	}
	return (1);
}

int	position(t_list *head, int max)
{
	int	i;

	i = 0;
	while (head && head->index != max)
	{
		i++;
		head = head->next;
	}
	return (i);
}
