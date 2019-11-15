/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_for_print_result.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idunaver <idunaver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 18:42:05 by idunaver          #+#    #+#             */
/*   Updated: 2019/10/24 18:42:31 by idunaver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_group	*init_group(t_lem_arifmetic *env_math, \
t_struct *pointer_struct)
{
	t_group *group;
	int		count_path;

	count_path = 0;
	group = (t_group *)malloc(env_math->count_path * sizeof(t_group));
	while (count_path != env_math->count_path)
	{
		group[count_path].count = 0;
		group[count_path].way = pointer_struct->path;
		group[count_path].length = pointer_struct->length;
		count_path++;
		pointer_struct = pointer_struct->next;
	}
	return (group);
}

t_ant	*init_ant(t_lem_arifmetic *env_math)
{
	t_ant	*ants;
	int		index;
	int		id;

	id = 1;
	index = 0;
	ants = (t_ant *)malloc(env_math->count_ants * sizeof(t_ant));
	while (index != env_math->count_ants)
	{
		ants[index].id = id++;
		ants[index].length = 0;
		ants[index].node = NULL;
		ants[index].path = NULL;
		index++;
	}
	return (ants);
}
