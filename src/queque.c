/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queque.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idunaver <idunaver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 16:37:49 by idunaver          #+#    #+#             */
/*   Updated: 2019/10/20 21:04:59 by idunaver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			pop_queque(t_queque **queque)
{
	t_queque	*tmp;

	tmp = NULL;
	if (!*queque)
		return ;
	if ((*queque)->next)
		tmp = (*queque)->next;
	(*queque)->name = NULL;
	free(*queque);
	*queque = tmp;
}

t_queque		*init_queque(t_node *node)
{
	t_queque	*new;

	if (!node)
		return (NULL);
	if (!(new = (t_queque *)malloc(sizeof(t_queque))))
		error();
	new->name = node;
	new->name->parent = NULL;
	new->next = NULL;
	return (new);
}

void			push_queque(t_queque **queque, t_node *node)
{
	t_queque	*new;
	t_queque	*head;

	new = NULL;
	head = *queque;
	if (node == NULL)
		return ;
	if (!*queque)
		*queque = init_queque(node);
	else
	{
		if (!(new = (t_queque *)malloc(sizeof(queque))))
		{
			free_queque(queque);
			error();
		}
		while ((*queque)->next)
			(*queque) = (*queque)->next;
		(*queque)->next = new;
		new->next = NULL;
		new->name = node;
		new->name->accept = 1;
		new->name->parent = head->name;
		*queque = head;
	}
}
