/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yperra-f <yperra-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 17:21:05 by idunaver          #+#    #+#             */
/*   Updated: 2019/10/24 20:36:29 by yperra-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	start_mid_end_elem(t_node *new_elem, int flag)
{
	if (!flag)
		new_elem->start_or_end = 0;
	else if (flag == 1)
		new_elem->start_or_end = 1;
	else if (flag == 2)
		new_elem->start_or_end = 2;
}

t_node	*init_node(char *name, int count_connect, int flag)
{
	t_node	*new_elem;

	if (!(new_elem = (t_node *)malloc(sizeof(t_node))))
		error();
	start_mid_end_elem(new_elem, flag);
	if (name)
		new_elem->name = ft_strdup(name);
	else
		new_elem->name = NULL;
	new_elem->level = 0;
	new_elem->accept = 0;
	new_elem->count_connect = count_connect;
	new_elem->parent = NULL;
	new_elem->next = NULL;
	new_elem->previous = NULL;
	new_elem->links = NULL;
	return (new_elem);
}

void	add_node(t_node **begin_list, char *name, int count_connect, int flag)
{
	t_node	*new_elem;
	t_node	*current;

	current = *begin_list;
	if (!*begin_list)
		error();
	while (current->next)
		current = current->next;
	if (!(new_elem = (t_node *)malloc(sizeof(t_node))))
	{
		free_nodes(begin_list);
		error();
	}
	start_mid_end_elem(new_elem, flag);
	new_elem->name = ft_strdup(name);
	new_elem->level = 0;
	new_elem->accept = 0;
	new_elem->parent = NULL;
	new_elem->count_connect = count_connect;
	current->next = new_elem;
	new_elem->next = NULL;
	new_elem->previous = current;
	new_elem->links = NULL;
}

t_node	*eject_elem(t_node **node, int flag)
{
	t_node *prev_elem;
	t_node *next_elem;
	t_node *iter;

	iter = *node;
	while (iter)
	{
		if ((iter)->start_or_end == flag)
		{
			prev_elem = (iter)->previous;
			next_elem = (iter)->next;
			if (prev_elem)
				prev_elem->next = next_elem;
			if (next_elem)
				next_elem->previous = prev_elem;
			if (!prev_elem)
				*node = next_elem;
			return (iter);
		}
		iter = (iter)->next;
	}
	return (NULL);
}
