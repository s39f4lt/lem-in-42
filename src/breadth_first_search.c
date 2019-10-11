/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   breadth_first_search.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idunaver <idunaver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 21:48:35 by idunaver          #+#    #+#             */
/*   Updated: 2019/10/11 17:45:22 by idunaver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static t_node	*end_node(t_node *node)
{
	while (node->next)
		node = node->next;
	return (node);
}

static int		check_elem_queque(t_node *node)
{
	if (node->accept == 0)
		return (1);
	else
		return (-1);
}

void			fill_matrix(t_node *node, t_lem_arifmetic *env_math)
{
	t_node	*end;

	end = NULL;
	if (!node || !env_math)
		return ;
	end = end_node(node);
	env_math->path++;
	while (end->parent)
	{
		env_math->matrix[end->parent->id][end->id] = env_math->path;
		end = end->parent;
	}
}

void			breadth_first_search(t_node *node, t_lem_arifmetic *env_math)
{
	t_queque	*queque;
	t_node		*end;

	end = end_node(node);
	queque = NULL;
	if (!node || !node->links)
		return ;
	push_queque(&queque, node);
	while (queque)
	{
		node->iter = 0;
		if (queque->name == end)
		{
			free_queque(queque);
			fill_matrix(node, env_math);
			print_adj_matrix(env_math->matrix, env_math->count_rooms);
			return ;
		}
		while (queque->name->links[node->iter])
		{
			if (check_elem_queque(queque->name->links[node->iter]) == 1)
				push_queque(&queque, queque->name->links[node->iter]);
			node->iter++;
		}
		pop_queque(&queque);
	}
	return ;
}
