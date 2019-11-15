/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_elems.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yperra-f <yperra-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 20:28:41 by yperra-f          #+#    #+#             */
/*   Updated: 2019/10/24 20:29:17 by yperra-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_connect(t_links **links, char **elem)
{
	if (!*links)
		*links = init_links(elem);
	else
		add_links(*links, elem);
}

void	ft_node(t_node **node, char **elem, int flag)
{
	if (!*node)
		*node = init_node(elem[0], 0, flag);
	else
		add_node(node, elem[0], 0, flag);
	ft_free(elem);
}
