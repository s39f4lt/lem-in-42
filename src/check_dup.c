/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_dup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idunaver <idunaver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 17:55:08 by idunaver          #+#    #+#             */
/*   Updated: 2019/10/24 18:30:49 by idunaver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		check_duplicate(t_node *node)
{
	t_node	*elem;
	t_node	*copy;

	elem = NULL;
	copy = NULL;
	if (!node && !node->next)
		return (0);
	elem = node;
	copy = node->next;
	while (elem)
	{
		while (copy)
		{
			if (ft_strcmp(elem->name, copy->name) == 0)
				return (-1);
			copy = copy->next;
		}
		elem = elem->next;
		if (elem && elem->next)
			copy = elem->next;
		else
			break ;
	}
	return (1);
}
