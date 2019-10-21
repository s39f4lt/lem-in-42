/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idunaver <idunaver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 16:10:27 by idunaver          #+#    #+#             */
/*   Updated: 2019/10/21 21:22:55 by idunaver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	rebuild_struct(t_node **node)
{
	int		flag;
	t_node	*first_or_last_elem;
	t_node	*current_elem;

	flag = 0;
	current_elem = *node;
	while (current_elem)
	{
		if (current_elem->start_or_end == 1 && current_elem->previous != NULL)
		{
			if (!(first_or_last_elem = eject_elem(node, 1)))
				break ;
			add_node_elem(node, first_or_last_elem, 1);
			flag++;
			current_elem = *node;
		}
		else if (current_elem->start_or_end == 2 && current_elem->next != NULL)
		{
			if (!(first_or_last_elem = eject_elem(node, 2)))
				break ;
			add_node_elem(node, first_or_last_elem, 2);
			flag++;
			current_elem = *node;
		}
		else if (flag == 2)
			break ;
		current_elem = current_elem->next;
	}
}

int		init_struct(t_lem_arifmetic *env_math, t_links **links, t_node **node)
{
	get_ants(&env_math);
	parse_map(env_math, links, node);
	printf("%s\n", env_math->book);
	ft_strdel(&env_math->book);
	rebuild_struct(node);
	add_id_in_nodes(*node, env_math);
	return (1);
}
