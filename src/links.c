/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   links.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idunaver <idunaver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 20:24:38 by idunaver          #+#    #+#             */
/*   Updated: 2019/10/07 21:09:53 by idunaver         ###   ########.fr       */
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

void	add_links(t_links *begin_list, char **links)
{
	t_links *new_elem;
	t_links	*current;

	current = begin_list;
	if (!begin_list)
		error();
	while (current->next)
		current = current->next;
	if (!(new_elem = (t_links *)malloc(sizeof(t_links))))
	{
		free_links(begin_list);
		error();
	}
	new_elem->link = links;
	current->next = new_elem;
	new_elem->next = NULL;
	new_elem->prev = current;
}

t_links	*init_links(char **links)
{
	t_links	*new_elem;

	if (!(new_elem = (t_links *)malloc(sizeof(t_links))))
		error();
	new_elem->link = links;
	new_elem->next = NULL;
	new_elem->prev = NULL;
	return (new_elem);
}
