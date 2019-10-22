/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idunaver <idunaver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 15:56:58 by idunaver          #+#    #+#             */
/*   Updated: 2019/10/22 19:19:52 by idunaver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_node		*search_address(t_node *node, t_links *links, t_node *current_elem)
{
	t_node *first_elem;

	first_elem = current_elem;
	while (links)
	{
		if (!ft_strcmp(node->name, links->link[0]))
		{
			current_elem = first_elem;
			while (current_elem)
			{
				if (!ft_strcmp(current_elem->name, links->link[1]))
				{
					node->links[node->iter++] = current_elem;
					break ;
				}
				current_elem = current_elem->next;
			}
		}
		if (!ft_strcmp(node->name, links->link[1]))
		{
			current_elem = first_elem;
			while (current_elem)
			{
				if (!ft_strcmp(current_elem->name, links->link[0]))
				{
					node->links[node->iter++] = current_elem;
					break ;
				}
				current_elem = current_elem->next;
			}
		}
		links = links->next;
	}
	node->links[node->iter] = NULL;
	return (NULL);
}

void		check_cross_line(t_lem_arifmetic *env_math)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (x != env_math->count_rooms - 1)
	{
		while (y != env_math->count_rooms - 1)
		{
			if (env_math->matrix[x][y] > 1 && env_math->matrix[y][x] > 1 \
			&& env_math->matrix[x][y] == env_math->matrix[y][x])
			{
				env_math->matrix[x][y] = 0;
				env_math->matrix[y][x] = 0;
			}
			y++;
		}
		x++;
		y = 0;
	}
}

void		first_init_nulling(t_links **links, t_node **node, \
t_struct **struct_pointer, t_lem_arifmetic *env_math)
{
	*links = NULL;
	*node = NULL;
	*struct_pointer = NULL;
	env_math->path = 1;
	env_math->count_path = 0;
}

void		lem_in(void)
{
	t_lem_arifmetic env_math;
	t_links			*links;
	t_node			*node;
	t_node			*end;
	t_struct		*struct_pointer;

	first_init_nulling(&links, &node, &struct_pointer, &env_math);
	if (!init_struct(&env_math, &links, &node) || !array_node(node, links) \
	|| !(env_math.matrix = init_adj_matrix(env_math.count_rooms, node)))
		return ;
	while (1)
	{
		if (!(end = breadth_first_search(node, &env_math)) || \
		!(struct_pointer = init_list_for_path(end, struct_pointer)))
			break ;
		if (env_math.count_path < calc_path_for_ants(struct_pointer, &env_math))
			env_math.count_path++;
		else
			break ;
	}
	print_path(struct_pointer);
	printf("\ncount-path: %d\n", env_math.count_path);
	go_ants(&env_math, struct_pointer);
	free_nodes(&node);
	free_struct(&struct_pointer);
	clear_adj_matrix(env_math.matrix, env_math.count_rooms);
}
