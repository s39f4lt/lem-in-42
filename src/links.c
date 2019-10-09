/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   links.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yperra-f <yperra-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 20:24:38 by idunaver          #+#    #+#             */
/*   Updated: 2019/10/08 16:44:03 by yperra-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	free_links(t_links *links)
{
	t_links	*tmp;

	tmp = NULL;
	while (links)
	{
		if (links->next)
			tmp = links->next;
		free(links);
		links = NULL;
		links = tmp;
		tmp = NULL;
	}
}

t_links	*init_links(char **links)
{
	t_links	*new_elem;

	if (!(new_elem = (t_links *)malloc(sizeof(t_links))))
		error();
	new_elem->link = links;
	// print_array(new_elem->link);
	new_elem->next = NULL;
	new_elem->prev = NULL;
	return (new_elem);
}

void	add_links(t_links **begin_list, char **links)
{
	t_links *new_elem;
	t_links	*current;

	current = *begin_list;
	if (!*begin_list)
		error();
	while (current->next)
		current = current->next;
	if (!(new_elem = (t_links *)malloc(sizeof(t_links))))
	{
		free_links(*begin_list);
		error();
	}
	new_elem->link = links;
	// print_array(new_elem->link);
	current->next = new_elem;
	new_elem->next = NULL;
	new_elem->prev = current;
}
