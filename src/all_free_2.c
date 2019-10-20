/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_free_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yperra-f <yperra-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 20:00:54 by idunaver          #+#    #+#             */
/*   Updated: 2019/10/20 15:59:17 by yperra-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		free_path(t_path *path)
{
	t_path	*next;

	next = NULL;
	while (path)
	{
		if (path->next)
			next = path->next;
		free(path);
		path = next;
		next = NULL;
	}
}

t_struct	*free_struct(t_struct *struct_pointer)
{
	t_struct	*next;

	next = NULL;
	while (struct_pointer)
	{
		if (struct_pointer->next)
			next = struct_pointer->next;
		free_path(struct_pointer->path);
		struct_pointer->length = 0;
		struct_pointer->next = NULL;
		free(struct_pointer);
		struct_pointer = next;
		next = NULL;
	}
	return (NULL);
}
