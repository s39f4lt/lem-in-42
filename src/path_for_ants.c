/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_for_ants.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idunaver <idunaver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 12:31:13 by idunaver          #+#    #+#             */
/*   Updated: 2019/10/18 18:01:38 by idunaver         ###   ########.fr       */
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

int			calc_path_for_ants(t_struct *path, t_lem_arifmetic *env_math)
{
	int			ants;
	int			diff_path;
	int			count_path;
	t_struct	*next_path;

	next_path = NULL;
	diff_path = 0;
	if (!path || !env_math)
		return (-1);
	count_path = 1;
	ants = env_math->count_ants;
	if (path->next)
		next_path = path->next;
	while (ants && path && next_path)
	{
		count_path++;
		diff_path = (next_path->length - path->length) * count_path;
		ants = ants - diff_path;
		path = path->next;
		next_path = path->next;
	}
	return (count_path);
}
