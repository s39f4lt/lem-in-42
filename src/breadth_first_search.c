/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   breadth_first_search.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idunaver <idunaver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 21:48:35 by idunaver          #+#    #+#             */
/*   Updated: 2019/10/21 21:31:42 by idunaver         ###   ########.fr       */
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

t_node			*end_is_found(t_node *node, t_lem_arifmetic *env_math, \
t_queque **queque, t_node *end)
{
	free_queque(queque);
	fill_matrix(node, env_math);
	null_accept_and_matrix(node, env_math);
	null_parent(node, env_math);
	return (end);
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
			return (end_is_found(node, env_math, &queque, end));
		while (queque->name->links[node->iter])
		{
			if ((!queque->name->links[node->iter]->accept && \
			check_matrix(env_math->matrix, queque->name->id, queque->name->links[node->iter]->id) && \
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
