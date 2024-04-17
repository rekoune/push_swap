/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arekoune <arekoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 16:41:05 by arekoune          #+#    #+#             */
/*   Updated: 2024/04/17 16:41:06 by arekoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(t_list **head, char c, int a)
{
	t_list	*last_node;
	t_list	*befor_last_node;
	t_list	*first_node;
	int		size;
	int		i;

	i = 1;
	size = list_size(*head);
	last_node = *head;
	befor_last_node = *head;
	first_node = *head;
	while (last_node->next)
		last_node = last_node->next;
	while (i++ < (size - 1))
		befor_last_node = befor_last_node->next;
	*head = last_node;
	last_node->next = first_node;
	befor_last_node->next = NULL;
	if (a > 0)
	{
		write(1, "rr", 2);
		write(1, &c, 1);
		write(1, "\n", 1);
	}
}

void	reverse_rotate_all(t_list **stack_a, t_list **stack_b)
{
	reverse_rotate(stack_a, 'a', 0);
	reverse_rotate(stack_b, 'b', 0);
	write(1, "rrr\n", 4);
}
