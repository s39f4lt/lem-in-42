/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_free_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idunaver <idunaver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 19:47:50 by idunaver          #+#    #+#             */
/*   Updated: 2019/10/21 18:00:27 by idunaver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	free_queque(t_queque **queque)
{
	t_queque	*tmp;
	t_queque	*copy;

	if (!queque || !(*queque))
		return ;
	tmp = NULL;
	copy = *queque;
	while (copy)
	{
		if (copy->next)
			tmp = copy->next;
		ft_memdel((void**)&copy);
		copy = tmp;
		tmp = NULL;
	}
	*queque = NULL;
}

void	free_nodes(t_node **nodes)
{
	t_node		*tmp;
	t_node	*copy;

	if (!nodes || !(*nodes))
		return ;
	tmp = NULL;
	copy = *nodes;
	while (copy)
	{
		if (copy->next)
			tmp = copy->next;
		ft_strdel(&copy->name);
		ft_memdel((void**)&copy->links);		
		ft_memdel((void**)&copy);
		copy = tmp;
		tmp = NULL;
	}
	*nodes = NULL;
}

void	free_links(t_links **links)
{
	t_links	*tmp;
	t_links	*copy;

	tmp = NULL;
	copy = *links;
	while (copy)
	{
		if (copy->next)
			tmp = copy->next;
		ft_free(copy->link);
		ft_memdel((void**)&copy);
		copy = tmp;
		tmp = NULL;
	}
	*links = NULL;
}

void	ft_free(char **elem)
{
	int	i;

	if (!elem)
		return ;
	i = -1;
	while (elem[++i])
		ft_strdel(&elem[i]);
	free(elem);
	elem = NULL;
}
