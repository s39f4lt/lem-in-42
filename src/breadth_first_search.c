/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   breadth_first_search.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yperra-f <yperra-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 21:48:35 by idunaver          #+#    #+#             */
/*   Updated: 2019/10/24 20:34:25 by yperra-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

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

t_node			*bfs_norminete(t_node *node)
{
	t_node		*end;

	end = end_node(node);
	if (!node || !node->links)
		return (NULL);
	return (end);
}

t_node			*breadth_first_search(t_node *node, t_lem_arifmetic *env_math)
{
	t_queque	*queque;
	t_node		*end;

	if (!(end = bfs_norminete(node)))
		return (NULL);
	queque = NULL;
	push_queque(&queque, node);
	while (queque)
	{
		node->iter = 0;
		if (queque->name == end)
			return (end_is_found(node, env_math, &queque, end));
		while (queque->name->links[node->iter])
		{
			if ((!queque->name->links[node->iter]->accept && \
			ft_strcmp(queque->name->links[node->iter]->name, node->name)) || \
			(!ft_strcmp(queque->name->links[node->iter]->name, end->name)))
				push_queque(&queque, queque->name->links[node->iter]);
			node->iter++;
		}
		pop_queque(&queque);
	}
	free_queque(&queque);
	return (NULL);
}
