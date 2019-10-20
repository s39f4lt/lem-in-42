/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idunaver <idunaver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 20:31:32 by idunaver          #+#    #+#             */
/*   Updated: 2019/10/20 21:13:45 by idunaver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	cat_in_book(t_lem_arifmetic **env_math)
{
	(*env_math)->tmp = ft_strjoin((*env_math)->book, ft_strcat((*env_math)->line, "\n"));
	free((*env_math)->book);
	free((*env_math)->line);
	(*env_math)->line = NULL;
	(*env_math)->book = ft_strdup((*env_math)->tmp);
	free((*env_math)->tmp);
	(*env_math)->tmp = NULL;

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

int		init_struct(t_lem_arifmetic *env_math, t_links **links, t_node **node)
{
	get_ants(&env_math);
	while (get_next_line(0, &env_math->line) > 0)
	{
		// cat_in_book(&env_math);
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
			free(env_math->line);
			error();
		}
	}
	printf("%s\n", env_math->book);
	rebuild_struct(node);
	add_id_in_nodes(*node, env_math);
	return (1);
}