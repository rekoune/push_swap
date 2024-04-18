/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arekoune <arekoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 21:45:05 by arekoune          #+#    #+#             */
/*   Updated: 2024/04/18 21:51:29 by arekoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "get_next_line.h"
# include "push_swap.h"

t_list	*put_in_a_bonus(int ac, char **av);
void	get_the_line(t_list **stack_a, t_list **stack_b);
int		rule_check(char *str);
int		compare(char *str, char *line);
void	do_the_rule(t_list **stack_a, t_list **stack_b, char *line);

#endif