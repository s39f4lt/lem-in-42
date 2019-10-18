/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idunaver <idunaver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 20:31:32 by idunaver          #+#    #+#             */
/*   Updated: 2019/10/18 20:32:07 by idunaver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		init_struct(t_lem_arifmetic *env_math, t_links **links, t_node **node)
{
	// if ((env_math->count_ants = get_ants(env_math)) <= 0)
	// 	return (0);
	get_ants(env_math);
	printf("ants: %d\n", env_math->count_ants);
	while (get_next_line(0, &env_math->line) > 0)
	{
		if (!ft_strcmp(env_math->line, "##start"))
			first_elem_node(node);
		else if (!ft_strcmp(env_math->line, "##end"))
			last_elem_node(node);
		else if (ft_strchr(env_math->line, ' '))
			ft_node(node, ft_strsplit(env_math->line, ' '), 0);
		else if (ft_strchr(env_math->line, '-'))
			ft_connect(links, ft_strsplit(env_math->line, '-'));
		else if (env_math->line[0] == '#')
			continue ;
		else
		{
			free(env_math->line);
			error();
		}
		free(env_math->line);
	}
	rebuild_struct(node);
	add_id_in_nodes(*node, env_math);
	return (1);
}