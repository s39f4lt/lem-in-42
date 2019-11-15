/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_free_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idunaver <idunaver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 20:00:54 by idunaver          #+#    #+#             */
/*   Updated: 2019/10/24 18:34:54 by idunaver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		free_path(t_path **path)
{
	t_path	*next;
	t_path	*copy;

	if (!*path)
		return ;
	next = NULL;
	copy = *path;
	while (copy)
	{
		if (copy->next)
			next = copy->next;
		ft_memdel((void**)&copy);
		copy = next;
		next = NULL;
	}
	*path = NULL;
}

t_struct	*free_struct(t_struct **struct_pointer)
{
	t_struct	*next;
	t_struct	*copy;

	if (!*struct_pointer)
		return (NULL);
	next = NULL;
	copy = *struct_pointer;
	while (copy)
	{
		if (copy->next)
			next = copy->next;
		free_path(&copy->path);
		ft_memdel((void**)&copy);
		copy = next;
		next = NULL;
	}
	*struct_pointer = NULL;
	return (NULL);
}

void		free_group(t_group **group)
{
	t_group	*copy;

	copy = *group;
	ft_memdel((void**)&copy);
	copy = NULL;
}

void		free_ants(t_ant **ants)
{
	t_ant	*copy;

	copy = *ants;
	ft_memdel((void**)&copy);
	copy = NULL;
}
