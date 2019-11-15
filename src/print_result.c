/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_result.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idunaver <idunaver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 11:11:45 by idunaver          #+#    #+#             */
/*   Updated: 2019/10/24 18:42:24 by idunaver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	dist_of_remaining_ants(int ants, t_group *group, \
t_lem_arifmetic *env_math)
{
	int	remainder;
	int separation;
	int index;

	index = 0;
	separation = ants / env_math->count_path;
	remainder = ants % env_math->count_path;
	while (ants != 0 && index < env_math->count_path)
	{
		group[index].count = group[index].count + separation;
		ants -= separation;
		index++;
	}
	index = 0;
	while (remainder-- != 0)
		group[index++].count++;
}

void	split_ants(t_lem_arifmetic *env_math, t_group *group)
{
	int		ants;
	int		min_length;
	int		index;

	index = 0;
	ants = env_math->count_ants;
	while (ants && index != env_math->count_path)
	{
		min_length = group[index].length;
		while (index + 1 != env_math->count_path && \
		min_length++ < group[index + 1].length)
		{
			group[index].count++;
			ants--;
		}
		index++;
	}
	if (ants != 0)
		dist_of_remaining_ants(ants, group, env_math);
}

int		print_line(t_ant *ants, t_lem_arifmetic *env_math, int end, \
t_node *node)
{
	int i;

	i = 0;
	env_math->count = 0;
	while (i < end)
	{
		if (ants[i].node)
		{
			if (ft_strcmp(ants[i].node->name, node->name))
				printf("L%d-%s ", ants[i].id, ants[i].node->name);
			ants[i].node = ants[i].node->next;
			env_math->count = 1;
		}
		i++;
	}
	if (env_math->count)
		printf("\n");
	return (env_math->count);
}

int		set_ants(t_group *group, t_ant *ants, \
t_lem_arifmetic *env_math, t_node *node)
{
	env_math->count = 1;
	env_math->i_g = 0;
	env_math->i_a = 0;
	while (env_math->count)
	{
		env_math->count = 0;
		env_math->i_g = 0;
		while (env_math->i_g != env_math->count_path)
		{
			if (group[env_math->i_g].count != 0)
			{
				ants[env_math->i_a].node = group[env_math->i_g].way;
				ants[env_math->i_a].length = group[env_math->i_g].length;
				group[env_math->i_g].count--;
				env_math->i_a++;
				env_math->count = 1;
			}
			env_math->i_g++;
		}
		print_line(ants, env_math, env_math->i_a, node);
	}
	return (env_math->i_a);
}

void	go_ants(t_lem_arifmetic *env_math, \
t_struct *pointer_struct, t_node *node)
{
	int		end;
	t_ant	*ants;
	t_group	*group;

	ants = NULL;
	group = NULL;
	group = init_group(env_math, pointer_struct);
	ants = init_ant(env_math);
	split_ants(env_math, group);
	end = set_ants(group, ants, env_math, node);
	while (1)
	{
		if (!print_line(ants, env_math, end, node))
			break ;
	}
	free_group(&group);
	free_ants(&ants);
}
