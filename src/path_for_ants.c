/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_for_ants.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idunaver <idunaver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 12:31:13 by idunaver          #+#    #+#             */
/*   Updated: 2019/10/20 17:42:53 by idunaver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			calc_length_one_path(t_path *path)
{
	t_path	*tmp;
	int		length;

	length = 0;
	tmp = path;
	while (tmp)
	{
		tmp = tmp->next;
		length++;
	}
	return (length);
}

t_struct	*swap_elems(t_struct **current, t_struct **next, t_struct **prev)
{
	t_struct	*tmp;

	tmp = NULL;
	if (!*current || !*next)
		return (NULL);
	tmp = (*next)->next;
	(*next)->next = *current;
	(*current)->next = tmp;
	if (*prev)
		(*prev)->next = *next;
	return (*current);
}

void		sort_path(t_struct **path)
{
	t_struct	*current;
	t_struct	*prev;
	t_struct	*next;

	if (!path || !*path)
		return ;
	prev = NULL;
	current = *path;
	if (current->next)
		next = current->next;
	while (current && next)
	{
		if (current->length > next->length)
		{
			current = swap_elems(&current, &next, &prev);
			if (prev)
				current = prev;
			continue ;
		}
		prev = current;
		current = current->next;
		next = current->next;
	}
}

int			calc_path_for_ants(t_struct *struct_pointer, t_lem_arifmetic *env_math)
{
	int			ants;
	int			diff_path;
	int			count_path;

	diff_path = 0;
	count_path = 0;
	ants = env_math->count_ants;
	if (!struct_pointer->next)
		return (1);	
	while (ants && struct_pointer && struct_pointer->next)
	{
		count_path++;
		if (!(diff_path = (struct_pointer->next->length - struct_pointer->length) * count_path))
		{
			while (struct_pointer->next && struct_pointer->length == struct_pointer->next->length)
			{
				struct_pointer = struct_pointer->next;
				count_path++;
				if (ants - count_path == 0)
					return (count_path);
			}
		}
		ants = ants - diff_path;
		struct_pointer = struct_pointer->next;
	}
	if (ants > 0)
		count_path++;
	return (count_path);
}
