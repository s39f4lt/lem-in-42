/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   breadth_first_search.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idunaver <idunaver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 21:48:35 by idunaver          #+#    #+#             */
/*   Updated: 2019/10/18 19:33:52 by idunaver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static t_node	*end_node(t_node *node)
{
	if (!node)
		return (NULL);
	while (node->next)
		node = node->next;
	return (node);
}

void			fill_matrix(t_node *node, t_lem_arifmetic *env_math)
{
	t_node	*end;

	if (!node || !env_math)
		return ;
	end = end_node(node);
	env_math->path++;
	while (end->parent)
	{
		env_math->matrix[end->parent->id][end->id] = env_math->path;
		// printf("bfs: %s\n", end->name);
		// printf("parent_name - %s\n", end->parent->name);
		end = end->parent;
	}
	// printf("bfs: %s\n", end->name);
	// end->parent ? printf("parent_name - %s\n", end->parent->name) : printf("parent_name - NULL\n");
}

void			print_queque(t_queque *queque)
{
	while (queque)
	{
		printf("%s\n", queque->name->name);
		queque = queque->next;
	}
}

int				check_matrix(int **matrix, int x, int y)
{
	return (matrix[x][y]);
}

t_node			*breadth_first_search(t_node *node, t_lem_arifmetic *env_math)
{
	t_queque	*queque;
	t_node		*end;

	end = end_node(node);
	queque = NULL;
	if (!node || !node->links)
		return (NULL);
	push_queque(&queque, node);
	while (queque)
	{
		node->iter = 0;
		if (queque->name == end)
		{
			free_queque(queque);
			fill_matrix(node, env_math);
			null_accept_and_matrix(node, env_math);
			null_parent(node, env_math);
			return (end);
		}
		while (queque->name->links[node->iter])
		{
			if ((!queque->name->links[node->iter]->accept && check_matrix(env_math->matrix, queque->name->id, queque->name->links[node->iter]->id) == 1 && ft_strcmp(queque->name->links[node->iter]->name, node->name)) || (!ft_strcmp(queque->name->links[node->iter]->name, end->name)))
				push_queque(&queque, queque->name->links[node->iter]);
			node->iter++;
		}
		pop_queque(&queque);
	}
	return (NULL);
}
