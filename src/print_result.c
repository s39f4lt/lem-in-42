/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_result.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idunaver <idunaver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 11:11:45 by idunaver          #+#    #+#             */
/*   Updated: 2019/10/22 22:27:30 by idunaver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_group	*init_group(t_lem_arifmetic *env_math, \
t_struct *pointer_struct)
{
	t_group *group;
	int 	count_path;

	count_path = -1;
	group = (t_group *)malloc(env_math->count_path * sizeof(t_group));
	while (++count_path != env_math->count_path)
	{
		group[count_path].count = 0;
		group[count_path].way = pointer_struct->path;
		group[count_path].length = pointer_struct->length;
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
		index++;
	}
	return (ants);
}

void	dist_of_remaining_ants(int ants, t_group **group, \
t_lem_arifmetic *env_math)
{
	int		remainder;
	int 	separation;
	int 	index;
	t_group	*copy;

	index = 0;
	copy = *group;
	separation = ants / env_math->count_path;
	remainder = ants % env_math->count_path;
	while (ants != 0)
	{
		copy[index].count = copy[index].count + separation;
		ants -= separation;
		index++;
	}
	index = 0;
	while (remainder-- != 0)
	{
		copy[index].count++;
		index++;
	}
}

void	split_ants(t_lem_arifmetic *env_math, t_group **group)
{
	int		ants;
	int		min_length;
	t_group	*copy;
	int		index;

	index = 0;
	copy = *group;
	ants = env_math->count_ants;
	while (ants && index != env_math->count_path)
	{
		min_length = copy[index].length;
		while (index + 1 != env_math->count_path && min_length++ < copy[index + 1].length)
		{
			copy[index].count++;
			ants--;
		}
		index++;
	}
	if (ants != 0)
		dist_of_remaining_ants(ants, group, env_math);
}

int		print_line(t_ant *ants, t_lem_arifmetic *env_math, int end)
{
	int	count;
	int i = 0;
	// t_path	*path;

	count = 0;
	env_math = NULL;
	while (i < end)
	{
		// ants[i].node = ants[i].path;
		printf("%d\n", end);
		// path = ants[i].node;
		if (ants[i].node)
		{
			printf("L%d-%s", ants[i].id, ants[i].node->name);
			if (ants[i].node->next)
			{
				printf(" ");
				ants[i].node = ants[i].node->next;
			}
			count = 1;
		}
		i++;
	}
	if (count)
		printf("\n");
	return (count);
}

int		set_ants(t_group **group, t_ant	**ants, t_lem_arifmetic *env_math)
{
	int count;
	int ant;
	int	i_g;
	int i_a;
	int end;

	ant = 1;
	count = 1;
	i_g = 0;
	i_a = 0;
	end = 0;
	while (count)
	{
		count = 0;
		i_g = 0;
		while (i_g != env_math->count_path)
		{
			if ((*group)[i_g].count != 0)
			{
				(*group)[i_g].count--;
				(*ants)[i_a].path = (*group)[i_g].way;
				(*ants)[i_a].node = (*ants)[i_a].path;
				(*ants)[i_a].length = (*group)[i_g].length;
				end++;
				i_a++;
				count = 1;
			}
			i_g++;
		}
		print_line(*ants, env_math, end);
		// end = 0;
	}
	// print_line(ants, env_math, end);
	return (end);
}

void	go_ants(t_lem_arifmetic *env_math, t_struct *pointer_struct)
{
	t_ant	*ants;
	t_group	*group;
	int		count;
	int 	end;

	count = 1;
	ants = NULL;
	group = NULL;
	group = init_group(env_math, pointer_struct);
	ants = init_ant(env_math);
	split_ants(env_math, &group);
	end = set_ants(&group, &ants, env_math);
	// while (count)
	// print_line(ants, env_math, end);
}