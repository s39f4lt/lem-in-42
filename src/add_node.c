/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_node.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yperra-f <yperra-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 20:35:46 by yperra-f          #+#    #+#             */
/*   Updated: 2019/10/24 20:36:17 by yperra-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	add_node_elem_norminete(t_node *current_elem,\
t_node *first_elem, t_node **node)
{
	current_elem->next = first_elem;
	if (first_elem)
		(first_elem)->previous = current_elem;
	current_elem->previous = NULL;
	*node = current_elem;
}

void	add_node_elem(t_node **node, t_node *current_elem, int flag)
{
	t_node *first_elem;

	first_elem = *node;
	if (flag == 1)
		add_node_elem_norminete(current_elem, first_elem, node);
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
