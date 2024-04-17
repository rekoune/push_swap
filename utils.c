/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arekoune <arekoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 01:26:55 by arekoune          #+#    #+#             */
/*   Updated: 2024/04/17 14:53:30 by arekoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*new_node(int nb)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	node->nbr = nb;
	node->next = NULL;
	return (node);
}

void	add_front(t_list **head, t_list *new)
{
	new->next = *head;
	*head = new;
}

int	list_size(t_list *head)
{
	int	i;

	i = 0;
	while (head)
	{
		head = head->next;
		i++;
	}
	return (i);
}

void	add_back(t_list **head, t_list *new)
{
	t_list	*node;

	if (!(*head))
	{
		*head = new;
		return ;
	}
	node = *head;
	while (node->next)
		node = node->next;
	node->next = new;
}

int	max_index(t_list *head)
{
	int	max;

	max = head->index;
	while (head)
	{
		if (max < head->index)
			max = head->index;
		head = head->next;
	}
	return (max);
}
