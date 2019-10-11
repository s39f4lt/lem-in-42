/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idunaver <idunaver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 15:56:58 by idunaver          #+#    #+#             */
/*   Updated: 2019/10/11 17:41:35 by idunaver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	print_array(char **array)
{
	int i = 0;

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

void	ft_node(t_node **node, char **elem, int flag)
{
	if (!*node)
		*node = init_node(elem[0], 0, flag);
	else
		add_node(node, elem[0], 0, flag);
	ft_free(elem);
}

void	ft_connect(t_links **links, char **elem)
{
	if (!*links)
		*links = init_links(elem);
	else
		add_links(*links, elem);
}

void	first_elem_node(t_node **node)
{
	char *line;

	while (get_next_line(0, &line) > 0)
	{
		if (line[0] == '#' && ft_strcmp(line, "##end"))
			continue ;
		else if (ft_strchr(line, ' '))
		{
			ft_node(node, ft_strsplit(line, ' '), 1);
			free(line);
			break ;
		}
		else
			error();
		free(line);
	}
}

void	last_elem_node(t_node **node)
{
	char *line;

	while (get_next_line(0, &line) > 0)
	{
		if (line[0] == '#' && ft_strcmp(line, "##start"))
			continue ;
		else if (ft_strchr(line, ' '))
		{
			ft_node(node, ft_strsplit(line, ' '), 2);
			free(line);
			break ;
		}
		else
			error();
		free(line);
	}
}

void	rebuild_struct(t_node **node)
{
	int		flag;
	t_node	*first_or_last_elem;
	t_node	*current_elem;

	flag = 0;
	current_elem = *node;
	// write(1, "hello", 5);
	while (current_elem)
	{
		// printf("%d\n", current_elem->start_or_end);
		// write(1, "hello", 5);
		if (current_elem->start_or_end == 1 && current_elem->previous != NULL)
		{
			if (!(first_or_last_elem = eject_elem(node, 1)))
				break ;
			// printf("start_name - %s\n", first_or_last_elem->name);
			// printf("node->name - %s\n", (*node)->name);
			// write(1, "hello", 5);
			add_node_elem(node, first_or_last_elem, 1);
			flag++;
			current_elem = *node;
		}
		else if (current_elem->start_or_end == 2 && current_elem->next != NULL)
		{
			if (!(first_or_last_elem = eject_elem(node, 2)))
				break ;
			// printf("end_name - %s\n", first_or_last_elem->name);
			// printf("node->name - %s\n", (*node)->name);
			// write(1, "hello", 5);
			add_node_elem(node, first_or_last_elem, 2);
			flag++;
			current_elem = *node;
		}
		else if (flag == 2)
			break ;
		current_elem = current_elem->next;
	}
}

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
	// print_adj_matrix(env_math->matrix, env_math->count_rooms);
	return (1);
}

void	print_list(t_links *links, t_node *node)
{
	printf("node\n\n");
	while (node)
	{
		printf("name - %s\n", node->name);
		printf("%d\n", node->accept);
		node->parent ? printf("%s\n", node->parent->name) : printf("NULL\n");
		// printf("%d\n", node->start_or_end);
		// printf("count_connect - %d\n", node->count_connect);
		// printf("%s\n", node->links[0]->name);
		// printf("id - %d\n", node->id);
		node = node->next;
	}
	links = NULL;
	// printf("\nlink\n");
	// while (links)
	// {
	// 	print_array(links->link);
	// 	links = links->next;
	// }
}

void	count_connect(t_node *node, t_links *links)
{
	t_links *first_elem_links;

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
		// links = first_elem_links;
		// while (links)
		// {
		// 	if (!ft_strcmp(links->link[1], node->name))
		// 		node->count_connect++;
		// 	links = links->next;
		// }
		node = node->next;
	}
}

t_node	*search_address(t_node *node, t_links *links, t_node *current_elem)
{
	t_node *first_elem;

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
		node->links = (t_node **)malloc(sizeof(t_node *) * (node->count_connect + 1));
		search_address(node, links, first_elem);
		node = node->next;
	}
}

int		array_node(t_node *node, t_links *links)
{
	count_connect(node, links);
	init_node_arr(node, links);
	return (1);
}

void	lem_in(void)
{
	t_lem_arifmetic env_math;
	t_links 		*links;
	t_node			*node;
	
	links = NULL;
	node = NULL;
	if (!init_struct(&env_math, &links, &node) || !array_node(node, links) || \
	!(env_math.matrix = init_adj_matrix(env_math.count_rooms, node)))
		return ;
	env_math.path = 1;
	breadth_first_search(node, &env_math);
	print_list(links, node);
}
