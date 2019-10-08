/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_link.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgendry <rgendry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 20:25:09 by rgendry           #+#    #+#             */
/*   Updated: 2019/10/05 20:29:53 by rgendry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_link	*create_link(char **data)
{
	t_link *new;

	if (!(new = (t_link*)malloc(sizeof(t_link))))
		error();
	new->name1 = ft_strdup(data[0]);
	new->name2 = ft_strdup(data[1]);
	new->next = NULL;
	return (new);
}

void	add_link(t_link *link, t_lem *lem)
{
	t_link	*head;

	head = lem->links;
	if (head)
	{
		link->next = lem->links;
		lem->links = link;
	}
	else
		lem->links = link;
}

void	get_link(char *line, t_lem *lem)
{
	char	**data;
	t_link	*link;

	data = ft_strsplit(line, '-');
	if (arr_len(data) != 2)
	{
		free_arr(&data);
		error();
	}
	link = create_link(data);
	add_link(link, lem);
	free_arr(&data);
	ft_strdel(&line);
}
