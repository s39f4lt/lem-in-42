/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yperra-f <yperra-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 15:56:58 by idunaver          #+#    #+#             */
/*   Updated: 2019/10/07 21:24:49 by yperra-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	init_room(t_lem_arifmetic *env_math, t_node *node, char **elem)
{
	if (!node)
		node = init_node(elem[0], 0);
	else
		add_node(node, elem[0], 0);
}

void	init_connect(t_lem_arifmetic **env_math, t_links *links, char **elem)
{
	if (!links)
		links = init_links(elem);
	else
		add_links(links, elem);
}

void	init_struct(t_lem_arifmetic *env_math, t_links *links, t_node *node)
{
	while (get_next_line(0, &env_math->line) > 0)
	{
		if (ft_strchr(env_math->line, ' '))
			init_room(env_math, node, ft_strsplit(env_math->line, ' '));
		else if (ft_strchr(env_math->line, '-'))
			init_connect(env_math, links, ft_strsplit(env_math->line, '-'));
		else if (env_math->line[0] == '#')
			continue ;
		else
		{
			free(env_math->line);
			error();
		}
		free(env_math->line);
	}
}

int		main(void)
{
	t_lem_arifmetic env_math;
	t_links 		*links;
	t_node			*node;
	
	init_struct(&env_math, &links, &node);
	return (0);
}
