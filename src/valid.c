/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idunaver <idunaver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 20:31:32 by idunaver          #+#    #+#             */
/*   Updated: 2019/10/21 18:19:36 by idunaver         ###   ########.fr       */
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

void	last_elem_node(t_lem_arifmetic **env_math, t_node **node)
{
	cat_in_book(env_math);
	while (get_next_line(0, &(*env_math)->line) > 0)
	{
		if ((*env_math)->line[0] == '#')
		{
			cat_in_book(env_math);
			continue ;
		}
		else if (ft_strchr((*env_math)->line, ' '))
		{
			ft_node(node, ft_strsplit((*env_math)->line, ' '), 2);
			cat_in_book(env_math);
			break ;
		}
		else
			error();
	}
}

void	first_elem_node(t_lem_arifmetic **env_math, t_node **node)
{
	cat_in_book(env_math);
	while (get_next_line(0, &(*env_math)->line) > 0)
	{
		if ((*env_math)->line[0] == '#')
		{
			cat_in_book(env_math);
			continue ;
		}
		else if (ft_strchr((*env_math)->line, ' '))
		{
			ft_node(node, ft_strsplit((*env_math)->line, ' '), 1);
			cat_in_book(env_math);
			break ;
		}
		else
			error();
	}
}

void	parse_map(t_lem_arifmetic *env_math, t_links **links, t_node **node)
{
	while (get_next_line(0, &env_math->line) > 0)
	{
		if (!ft_strcmp(env_math->line, "##start"))
			first_elem_node(&env_math, node);
		else if (!ft_strcmp(env_math->line, "##end"))
			last_elem_node(&env_math, node);
		else if (ft_strchr(env_math->line, ' '))
		{
			ft_node(node, ft_strsplit(env_math->line, ' '), 0);
			cat_in_book(&env_math);
		}
		else if (ft_strchr(env_math->line, '-'))
		{
			ft_connect(links, ft_strsplit(env_math->line, '-'));
			cat_in_book(&env_math);
		}
		else if (env_math->line[0] == '#')
			continue ;
		else
		{
			ft_strdel(&env_math->line);
			error();
		}
		ft_strdel(&env_math->line);
	}
}
