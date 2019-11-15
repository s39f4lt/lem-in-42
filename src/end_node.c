/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_node.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yperra-f <yperra-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 20:33:55 by yperra-f          #+#    #+#             */
/*   Updated: 2019/10/24 20:34:29 by yperra-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_node			*end_node(t_node *node)
{
	if (!node)
		return (NULL);
	while (node->next)
		node = node->next;
	return (node);
}

t_node			*end_is_found(t_node *node, t_lem_arifmetic *env_math, \
t_queque **queque, t_node *end)
{
	free_queque(queque);
	fill_matrix(node, env_math);
	null_accept_and_matrix(node, env_math);
	null_parent(node, env_math);
	return (end);
}
