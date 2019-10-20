/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_free_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idunaver <idunaver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 19:47:50 by idunaver          #+#    #+#             */
/*   Updated: 2019/10/20 21:23:59 by idunaver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	free_queque(t_queque **queque)
{
	t_queque	*tmp;

	tmp = NULL;
	while (*queque)
	{
		if ((*queque)->next)
			tmp = (*queque)->next;
		free(*queque);
		*queque = tmp;
		tmp = NULL;
	}
}

void	free_nodes(t_node *nodes)
{
	t_node	*tmp;

	tmp = NULL;
	while (nodes)
	{
		if (nodes->next)
			tmp = nodes->next;
		free(nodes);
		nodes = NULL;
		nodes = tmp;
		tmp = NULL;
	}
}

void	free_links(t_links *links)
{
	t_links	*tmp;

	tmp = NULL;
	while (links)
	{
		if (links->next)
			tmp = links->next;
		free(links);
		links = NULL;
		links = tmp;
		tmp = NULL;
	}
}

void	ft_free(char **elem)
{
	char **null_elem;

	null_elem = elem;
	while (*elem)
	{
		free(*elem);
		elem++;
	}
	null_elem = NULL;
}
