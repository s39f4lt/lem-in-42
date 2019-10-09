/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idunaver <idunaver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 15:56:58 by idunaver          #+#    #+#             */
/*   Updated: 2019/10/09 21:00:49 by idunaver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	print_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		printf("array[%d] - %s\n", i,  array[i]);
		i++;
	}
}

void	ft_free(char **elem)
{
	char	**null_elem;

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

void	init_struct(t_lem_arifmetic *env_math, \
t_links **links, t_node **node)
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
		printf("%d\n", node->count_connect);
		node = node->next;
	}
	printf("\nlink\n");
	while (links)
	{
		print_array(links->link);
		links = links->next;
	}
}

void	count_connect(t_node *node, t_links *links)
{
	t_links	*first_elem_links;

	first_elem_links = links;
	while (node)
	{
		links = first_elem_links;
		while (links)
		{
			if (!ft_strcmp(links->link[0], node->name))
				node->count_connect++;
			links = links->next;
		}
		links = first_elem_links;
		while (links)
		{
			if (!ft_strcmp(links->link[1], node->name))
				node->count_connect++;
			links = links->next;
		}
		node = node->next;
	}
}

t_node	*search_address(t_node *node, t_links *links, \
t_node *current_elem)
{
	t_node	*first_elem;

	first_elem = current_elem;
	while (links)
	{
		if (!ft_strcmp(node->name, links->link[0]))
		{
			current_elem = first_elem;
			while (current_elem)
			{
				if (!ft_strcmp(current_elem->name, links->link[1]))
				{
					node->links[node->iter++] = current_elem;
					break ;
				}
				current_elem = current_elem->next;
			}
		}
		links = links->next;
	}
	node->links[node->iter] = NULL;
	return (NULL);
}

void	init_node_arr(t_node *node, t_links *links)
{
	t_node	*first_elem;

	first_elem = node;
	while (node)
	{
		node->iter = 0;
		node->links = (t_node **)malloc(sizeof(t_node *) \
		* (node->count_connect + 1));
		search_address(node, links, first_elem);
		// int i = 0;
		// while (node->links[i])
		// {
		// 	printf("%s\n", node->name);
		// 	printf("%s\n", node->links[i]->name);
		// 	i++;
		// }
		node = node->next;
	}
}

void	array_node(t_node *node, t_links *links)
{
	count_connect(node, links);
	init_node_arr(node, links);
}

void	lem_in(void)
{
	t_lem_arifmetic	env_math;
	t_links 		*links;
	t_node			*node;
	
	links = NULL;
	node = NULL;
	init_struct(&env_math, &links, &node);
	array_node(node, links);
	// print_list(links, node);
}
