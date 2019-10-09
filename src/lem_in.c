/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idunaver <idunaver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 15:56:58 by idunaver          #+#    #+#             */
/*   Updated: 2019/10/09 15:29:31 by idunaver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	print_array(char **array)
{
	int i;

	i = 0;
	while (array[i])
	{
		printf("array[%d] - %s\n", i,  array[i]);
		i++;
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

void	init_room(t_node **node, char **elem)
{
	// check_room_valid(elem);
	if (!*node)
		*node = init_node(elem[0], 0);
	else
		add_node(node, elem[0], 0);
	ft_free(elem);
}

void	init_connect(t_links **links, char **elem)
{
	if (!*links)
		*links = init_links(elem);
	else
		add_links(links, elem);
	// ft_free(elem);
}

void	init_struct(t_lem_arifmetic *env_math, t_links **links, t_node **node)
{
	while (get_next_line(0, &env_math->line) > 0)
	{
		// write(1, "hello", 5);
		if (ft_strchr(env_math->line, ' '))
			init_room(node, ft_strsplit(env_math->line, ' '));
		else if (ft_strchr(env_math->line, '-'))
			init_connect(links, ft_strsplit(env_math->line, '-'));
		else if (env_math->line[0] == '#')
			continue ;
		else
		{
			free(env_math->line);
			error();
		}
		// printf("%s\n", env_math->line);
		free(env_math->line);
	}
}

void	print_list(t_links *links, t_node *node)
{
	printf("node\n\n");
	while (node)
	{
		printf("%s\n", node->name);
		node = node->next;
	}
	printf("\nlink\n");
	while (links)
	{
		print_array(links->link);
		links = links->next;
	}
}

void	lem_in(void)
{
	t_lem_arifmetic env_math;
	t_links 		*links;
	t_node			*node;
	
	links = NULL;
	node = NULL;
	init_struct(&env_math, &links, &node);
	print_list(links, node);
}
