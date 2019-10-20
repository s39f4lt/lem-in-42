/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idunaver <idunaver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 17:21:05 by idunaver          #+#    #+#             */
/*   Updated: 2019/10/20 21:24:32 by idunaver         ###   ########.fr       */
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
	name ? (new_elem->name = ft_strdup(name)) : (new_elem->name = NULL);
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
		free_nodes(*begin_list);
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

void	add_node_elem(t_node **node, t_node *current_elem, int flag)
{
	t_node *first_elem;

	first_elem = *node;
	if (flag == 1)
	{
		current_elem->next = first_elem;
		if (first_elem)
			(first_elem)->previous = current_elem;
		current_elem->previous = NULL;
		*node = current_elem;
	}
	else if (flag == 2)
	{
		if (first_elem)
		{
			while ((first_elem)->next)
				first_elem = (first_elem)->next;
			(first_elem)->next = current_elem;
			current_elem->previous = first_elem;
			current_elem->next = NULL;
		}
		else
		{
			first_elem = current_elem;
			current_elem->next = NULL;
			current_elem->previous = NULL;
		}
	}
}
