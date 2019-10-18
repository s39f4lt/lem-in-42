/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nuller.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idunaver <idunaver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 19:33:23 by idunaver          #+#    #+#             */
/*   Updated: 2019/10/18 19:34:44 by idunaver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	null_links(t_node *node, t_lem_arifmetic *env_math)
{
	int	i;

	i = 0;
	while (node->links[i])
	{
		if (check_matrix(env_math->matrix, node->id, node->links[i]->id) < 2)
			env_math->matrix[node->id][node->links[i]->id] = 0;
		i++;
	}
}

void	null_parent(t_node *node, t_lem_arifmetic *env_math)
{
	while (node)
	{
		if (node->parent && check_matrix(env_math->matrix, \
		node->parent->id, node->id) < 2)
		{
			node->accept = 0;
			node->parent = NULL;
		}
		node = node->next;
	}
}

void	null_accept_and_matrix(t_node *node, t_lem_arifmetic *env_math)
{
	int	i;

	while (node)
	{
		i = 0;
		while (node->links[i])
		{
			if (check_matrix(env_math->matrix, \
			node->id, node->links[i]->id) > 1)
			{
				null_links(node->links[i], env_math);
				break ;
			}
			i++;
		}
		node = node->next;
	}
}
