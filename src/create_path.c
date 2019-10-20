/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idunaver <idunaver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 17:26:13 by idunaver          #+#    #+#             */
/*   Updated: 2019/10/20 17:12:27 by idunaver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_path		*init_struct_path(t_struct *struct_pointer, t_node *end)
{
	t_path	*new;

	while (end)
	{
		if (!struct_pointer->path)
		{
			if (!(struct_pointer->path = (t_path *)malloc(sizeof(t_path))) \
			|| !(struct_pointer->path->name = end->name))
				return (NULL);
			struct_pointer->path->next = NULL;
		}
		else
		{
			if (!(new = (t_path *)malloc(sizeof(t_path))) \
			|| !(new->name = end->name))
				return (NULL);
			new->next = struct_pointer->path;
			struct_pointer->path = new;
		}
		end = end->parent;
	}
	return (new);
}

t_struct	*init_struct_res(t_node *end)
{
	t_struct	*struct_pointer;

	if (!(struct_pointer = (t_struct *)malloc(sizeof(t_struct))))
		return (NULL);
	struct_pointer->path = NULL;
	if (!(struct_pointer->path = init_struct_path(struct_pointer, end)))
		return (NULL);
	struct_pointer->length = calc_length_one_path(struct_pointer->path);
	struct_pointer->next = NULL;
	return (struct_pointer);
}

t_struct	*init_list_for_path(t_node *end, t_struct *struct_pointer)
{
	t_struct *head;

	if (!struct_pointer)
	{
		if (!(struct_pointer = init_struct_res(end)))
			return (free_struct(struct_pointer));
		head = struct_pointer;
		// struct_pointer->next = NULL;
	}
	else
	{
		head = struct_pointer;
		while (struct_pointer->next)
			struct_pointer = struct_pointer->next;
		if (!(struct_pointer->next = init_struct_res(end)))
			return (free_struct(head));
		// struct_pointer = struct_pointer->next;
		// struct_pointer->next = NULL;
		sort_path(&head);
	}
	return (head);
}
