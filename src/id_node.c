/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   id_node.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idunaver <idunaver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 19:59:00 by idunaver          #+#    #+#             */
/*   Updated: 2019/10/10 20:02:14 by idunaver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	add_id_in_nodes(t_node *node)
{
	t_node	*tmp;
	int		id;

	id = 0;
	tmp = node;
	if (!tmp)
		return ;
	while (tmp->next)
	{
		tmp->id = id++;
		tmp = tmp->next;
	}
}
