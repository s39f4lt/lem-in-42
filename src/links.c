/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   links.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idunaver <idunaver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 20:24:38 by idunaver          #+#    #+#             */
/*   Updated: 2019/10/21 17:18:16 by idunaver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

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

void	add_links(t_links *begin_list, char **links)
{
	t_links *new_elem;

	if (!begin_list)
		error();
	while (begin_list->next)
		begin_list = begin_list->next;
	if (!(new_elem = (t_links *)malloc(sizeof(t_links))))
	{
		free_links(&begin_list);
		error();
	}
	new_elem->link = links;
	begin_list->next = new_elem;
	new_elem->next = NULL;
	new_elem->prev = begin_list;
}
