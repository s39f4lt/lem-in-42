/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   breadth_first_search.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idunaver <idunaver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 21:48:35 by idunaver          #+#    #+#             */
/*   Updated: 2019/10/09 17:32:40 by idunaver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			free_queque(t_queque *queque)
{
	t_queque	*tmp;

	tmp = NULL;
	while (queque)
	{
		if (queque->next)
			tmp = queque->next;
		free(queque);
		queque = tmp;
		tmp = NULL;
	}
}

void			pop_queque(t_queque *queque)
{
	t_queque	*tmp;

	tmp = NULL;
	if (!queque)
		return ;
	if (queque->next)
		tmp = queque->next;
	queque->name = NULL;
	free(queque);
	queque = tmp;
}

t_queque		*init_queque(t_node *node)
{
	t_queque	*new;

	if (!node)
		return (NULL);
	if (!(new = (t_queque *)malloc(sizeof(t_queque))))
		error();
	new->name = node;
	new->next = NULL;
}

void			push_queque(t_queque *queque, t_node *node)
{
	t_queque	*tmp;
	t_queque	*new;

	tmp = NULL;
	new = NULL;
	if (!queque)
		queque = init_queque(node);
	else
	{
		if (!(new = (t_queque *)malloc(sizeof(queque))))
		{
			free_queque(queque);
			error();
		}
		tmp = queque;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}

int				search_in_adj_matrix();
void			mark_in_adj_matrix();

static	t_node	*end_node(t_node *node)
{
	t_node	*end;

	end = node;
	if (!node)
		return (NULL);
	while (ft_strcmp(end->name, "end") != 0)
		end = end->next;
	return (end);
}

void			breadth_first_search(t_node *node)
{
	t_queque	*queque;
	t_node		*end;

	end = end_node(node);
	queque = NULL;
	if (!node->links)
		return ;
	push_queque(queque, node);
	search_in_adj_matrix();
	while (queque->next)
	{
		if (search_in_adj_matrix() == 0)
		{
			if (queque->name == end)
				return ;
			else
			{
				while (queque->name->links++)
					push_queque(queque, queque->name->links);
			}
		}
		pop_queque(queque);
	}
	return ;
}
