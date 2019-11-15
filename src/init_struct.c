/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yperra-f <yperra-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 16:10:27 by idunaver          #+#    #+#             */
/*   Updated: 2019/10/24 19:53:15 by yperra-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		rebuild_struct_norminete(t_node **node, int flag, \
t_node *first_or_last_elem, t_node *current_elem)
{
	add_node_elem(node, first_or_last_elem, 1);
	flag++;
	current_elem = *node;
	return (flag);
}

int		rebuild_struct_norminete_2(t_node **node, int flag, \
t_node *first_or_last_elem, t_node *current_elem)
{
	add_node_elem(node, first_or_last_elem, 2);
	flag++;
	current_elem = *node;
	return (flag);
}

void	rebuild_struct(t_node **node, t_node *current_elem, \
t_node *first_or_last_elem)
{
	int		flag;

	flag = 0;
	current_elem = *node;
	while (current_elem)
	{
		if (current_elem->start_or_end == 1 && current_elem->previous != NULL)
		{
			if (!(first_or_last_elem = eject_elem(node, 1)))
				break ;
			flag = rebuild_struct_norminete(node, flag, \
			first_or_last_elem, current_elem);
		}
		else if (current_elem->start_or_end == 2 && current_elem->next != NULL)
		{
			if (!(first_or_last_elem = eject_elem(node, 2)))
				break ;
			flag = rebuild_struct_norminete_2(node, flag, \
			first_or_last_elem, current_elem);
		}
		else if (flag == 2)
			break ;
		current_elem = current_elem->next;
	}
}

void	check_start_end(t_lem_arifmetic *env_math)
{
	if (env_math->first != 1 || env_math->last != 1)
		error();
}

int		init_struct(t_lem_arifmetic *env_math, t_links **links, t_node **node)
{
	t_node	*first_or_last_elem;
	t_node	*current_elem;

	first_or_last_elem = NULL;
	current_elem = NULL;
	get_ants(&env_math);
	parse_map(env_math, links, node);
	check_start_end(env_math);
	rebuild_struct(node, current_elem, first_or_last_elem);
	add_id_in_nodes(*node, env_math);
	if (check_duplicate(*node) == -1)
		error();
	return (1);
}
