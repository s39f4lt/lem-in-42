/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_node.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idunaver <idunaver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 16:14:21 by idunaver          #+#    #+#             */
/*   Updated: 2019/10/21 18:21:50 by idunaver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	count_connect(t_node *node, t_links *links)
{
	t_links *first_elem_links;

	first_elem_links = links;
	while (node)
	{
		links = first_elem_links;
		while (links)
		{
			if (!ft_strcmp(links->link[0], node->name))
				node->count_connect++;
			links = links->next;
		}
		links = first_elem_links;
		while (links)
		{
			if (!ft_strcmp(links->link[1], node->name))
				node->count_connect++;
			links = links->next;
		}
		node = node->next;
	}
}

void	init_node_arr(t_node *node, t_links *links)
{
	t_node	*first_elem;

	first_elem = node;
	while (node)
	{
		node->iter = 0;
		node->links = (t_node **)malloc(sizeof(t_node *) * \
		(node->count_connect + 1));
		search_address(node, links, first_elem);
		node = node->next;
	}
}

int		array_node(t_node *node, t_links *links)
{
	count_connect(node, links);
	init_node_arr(node, links);
	free_links(&links);
	return (1);
}
