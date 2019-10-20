/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idunaver <idunaver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 15:56:58 by idunaver          #+#    #+#             */
/*   Updated: 2019/10/20 17:50:51 by idunaver         ###   ########.fr       */
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
	while (current_elem)
	{
		if (current_elem->start_or_end == 1 && current_elem->previous != NULL)
		{
			if (!(first_or_last_elem = eject_elem(node, 1)))
				break ;
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



void	print_list(t_links *links, t_node *node)
{
	printf("node\n\n");
	while (node)
	{
		printf("name - %s\n", node->name);
		printf("accept - %d\n", node->accept);
		node->parent ? printf("parent: %s\n", node->parent->name) : printf("NULL\n");
		// printf("%d\n", node->start_or_end);
		// printf("count_connect - %d\n", node->count_connect);
		// int i = 0;
		// while (node->links[i])
		// {
		// 	printf("links[0] - %s\n", node->links[i]->name);
		// 	i++;
		// }
		// printf("id - %d\n", node->id);
		node = node->next;
	}
	links = NULL;
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
		// if (!ft_strcmp(node->name, links->link[1]))
		// {
		// 	current_elem = first_elem;
		// 	while (current_elem)
		// 	{
		// 		if (!ft_strcmp(current_elem->name, links->link[0]))
		// 		{
		// 			node->links[node->iter++] = current_elem;
		// 			break ;
		// 		}
		// 		current_elem = current_elem->next;
		// 	}
		// }
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

int			array_node(t_node *node, t_links *links)
{
	count_connect(node, links);
	init_node_arr(node, links);
	return (1);
}

void		check_cross_line(t_lem_arifmetic *env_math)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (x != env_math->count_rooms - 1)
	{
		while (y != env_math->count_rooms - 1)
		{
			if (env_math->matrix[x][y] > 1 && env_math->matrix[y][x] > 1 && env_math->matrix[x][y] == env_math->matrix[y][x])
			{
				env_math->matrix[x][y] = 0;
				env_math->matrix[y][x] = 0;
			}
			y++;
		}
		x++;
		y = 0;
	}
}

void		print_path(t_struct *struct_pointer)
{
	while (struct_pointer)
	{
		printf("\nlength - %d", struct_pointer->length);
		printf("\n");
		while (struct_pointer->path)
		{
			printf("%s\n", struct_pointer->path->name);
			struct_pointer->path = struct_pointer->path->next;
		}
		struct_pointer = struct_pointer->next;
	}
}

void		lem_in(void)
{
	t_lem_arifmetic env_math;
	t_links 		*links;
	t_node			*node;
	t_node			*end;
	t_struct		*struct_pointer;
	
	links = NULL;
	node = NULL;
	struct_pointer = NULL;
	if (!init_struct(&env_math, &links, &node) || !array_node(node, links) || !(env_math.matrix = init_adj_matrix(env_math.count_rooms, node)))
		return ;
	env_math.path = 1;
	env_math.count_path = 0;
	while (1)
	{
		if (!(end = breadth_first_search(node, &env_math)) || !(struct_pointer = init_list_for_path(end, struct_pointer)))
			break ;
		if (env_math.count_path < calc_path_for_ants(struct_pointer, &env_math))
			env_math.count_path++;
		else
			break ;
	}
	print_path(struct_pointer);
	printf("\ncount-path: %d\n", env_math.count_path);
	// print_list(links, node);
}
