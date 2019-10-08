/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgendry <rgendry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 19:44:03 by rgendry           #+#    #+#             */
/*   Updated: 2019/10/08 20:34:59 by rgendry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		check_link(t_lem *lem, char *name, int size)
{
	int i;

	i = 0;
	while (lem->nodes)
	{
		i++;
		if (!ft_strcmp(lem->nodes->name, name))
			return (size);
		lem->nodes = lem->nodes->next;
	}
	error();
	return (0);
}

void	set_map(t_lem *lem)
{
	t_link	*head;
	int		x;
	int		y;

	head = lem->links;
	while (head)
	{
		x = check_link(lem, head->name1, lem->size);
		y = check_link(lem, head->name2, lem->size);
		head = head->next;
	}
}

t_index	*create_map(int size)
{
	int		i;
	t_index	*new;

	i = 0;
	if (!(new = (t_index *)malloc(sizeof(t_index) * size)))
		error();
	while (i < size)
	{
		new[i].name = NULL;
		new[i].index = 2147483647;
		i++;
	}
	return (new);
}

void	index_map(t_lem *lem)
{
	lem->index_map = create_map(lem->size);
	set_map(lem);
}
