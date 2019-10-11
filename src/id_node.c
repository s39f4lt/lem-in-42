/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   id_node.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yperra-f <yperra-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 19:59:00 by idunaver          #+#    #+#             */
/*   Updated: 2019/10/11 11:52:45 by yperra-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	add_id_in_nodes(t_node *node, t_lem_arifmetic *env_math)
{
	int		id;

	id = 0;
	env_math->count_rooms = 0;
	if (!node)
		return ;
	while (node)
	{
		env_math->count_rooms++;
		node->id = id++;
		node = node->next;
	}
}
