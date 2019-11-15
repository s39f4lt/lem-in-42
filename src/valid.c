/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yperra-f <yperra-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 20:31:32 by idunaver          #+#    #+#             */
/*   Updated: 2019/10/24 21:46:37 by yperra-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	last_elem_node(t_lem_arifmetic **env_math, t_node **node)
{
	cat_in_book(env_math);
	(*env_math)->last++;
	while (get_next_line(0, &(*env_math)->line) > 0)
	{
		if (!ft_strcmp((*env_math)->line, "##end"))
			error();
		else if ((*env_math)->line[0] == '#')
		{
			cat_in_book(env_math);
			continue ;
		}
		else if ((*env_math)->line[0] == 'L')
			error();
		else if (ft_strchr((*env_math)->line, ' ') && \
		ft_regex((*env_math)->line, PATTERN_NODE))
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
	(*env_math)->first++;
	while (get_next_line(0, &(*env_math)->line) > 0)
	{
		if (!ft_strcmp((*env_math)->line, "##start"))
			error();
		else if ((*env_math)->line[0] == '#')
		{
			cat_in_book(env_math);
			continue ;
		}
		else if ((*env_math)->line[0] == 'L')
			error();
		else if (ft_strchr((*env_math)->line, ' ') && \
		ft_regex((*env_math)->line, PATTERN_NODE))
		{
			ft_node(node, ft_strsplit((*env_math)->line, ' '), 1);
			cat_in_book(env_math);
			break ;
		}
		else
			error();
	}
}

void	parse_map_norminete(t_lem_arifmetic *env_math, t_links **links)
{
	ft_connect(links, ft_strsplit(env_math->line, '-'));
	cat_in_book(&env_math);
}

void	parse_map_norminete_2(t_lem_arifmetic *env_math, t_node **node)
{
	ft_node(node, ft_strsplit(env_math->line, ' '), 0);
	cat_in_book(&env_math);
}

void	parse_map(t_lem_arifmetic *env_math, t_links **links, t_node **node)
{
	while (get_next_line(0, &env_math->line) > 0)
	{
		if (env_math->line[0] == 'L')
			error();
		else if (!ft_strcmp(env_math->line, "##start"))
			first_elem_node(&env_math, node);
		else if (!ft_strcmp(env_math->line, "##end"))
			last_elem_node(&env_math, node);
		else if (env_math->line[0] == '#')
		{
			ft_strdel(&env_math->line);
			continue ;
		}
		else if (ft_strchr(env_math->line, ' ') && \
		ft_regex(env_math->line, PATTERN_NODE))
			parse_map_norminete_2(env_math, node);
		else if (ft_strchr(env_math->line, '-') && \
		ft_regex(env_math->line, PATTERN_LINKS))
			parse_map_norminete(env_math, links);
		else
			error();
		ft_strdel(&env_math->line);
	}
}
