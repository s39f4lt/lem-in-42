/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   work_with_node.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idunaver <idunaver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 17:21:05 by idunaver          #+#    #+#             */
/*   Updated: 2019/10/07 17:59:06 by idunaver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	free_nodes(t_node *nodes)
{
	t_node	*tmp;

	tmp = NULL;
	while (nodes)
	{
		if (nodes->next)
			tmp = nodes->next;
		free(nodes);
		nodes = NULL;
		nodes = tmp;
		tmp = NULL;
	}
}

t_node	*init_node(char *name, int count_connect)
{
	t_node	*new_elem;

	if (!(new_elem = (t_node *)malloc(sizeof(t_node))))
		exit(EXIT_FAILURE);
	new_elem->name = ft_strdup(name);
	new_elem->level = 0;
	new_elem->count_connect = count_connect;
	new_elem->next = NULL;
	new_elem->previous = NULL;
	new_elem->links = NULL;
	return (new_elem);
}

void	add_node(t_node *begin_list, char *name, int count_connect)
{
	t_node	*new_elem;

	if (!begin_list)
		exit(EXIT_FAILURE);
	if (!(new_elem = (t_node *)malloc(sizeof(t_node))))
	{
		free_nodes(begin_list);
		exit(EXIT_FAILURE);
	}
	new_elem->name = ft_strdup(name);
	new_elem->level = 0;
	new_elem->count_connect = count_connect;
	begin_list->next = new_elem;
	new_elem->next = NULL;
	new_elem->previous = begin_list;
	new_elem->links = NULL;
}
