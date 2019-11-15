/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_add.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yperra-f <yperra-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 20:30:49 by yperra-f          #+#    #+#             */
/*   Updated: 2019/10/24 20:33:00 by yperra-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	search_address_norminete(t_node *current_elem, t_links *links,\
t_node *node)
{
	while (current_elem)
	{
		if (!ft_strcmp(current_elem->name, links->link[1]))
		{
			node->links[node->iter++] = current_elem;
			break ;
		}
		current_elem = current_elem->next;
	}
}

void	search_address_norminete_2(t_node *current_elem, t_links *links,\
t_node *node)
{
	while (current_elem)
	{
		if (!ft_strcmp(current_elem->name, links->link[0]))
		{
			node->links[node->iter++] = current_elem;
			break ;
		}
		current_elem = current_elem->next;
	}
}

t_node	*search_address(t_node *node, t_links *links, \
t_node *current_elem)
{
	t_node *first_elem;

	first_elem = current_elem;
	while (links)
	{
		if (!ft_strcmp(node->name, links->link[0]))
		{
			current_elem = first_elem;
			search_address_norminete(current_elem, links, node);
		}
		if (!ft_strcmp(node->name, links->link[1]))
		{
			current_elem = first_elem;
			search_address_norminete_2(current_elem, links, node);
		}
		links = links->next;
	}
	node->links[node->iter] = NULL;
	return (NULL);
}
