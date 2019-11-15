/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adj_matrix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yperra-f <yperra-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 18:32:38 by idunaver          #+#    #+#             */
/*   Updated: 2019/10/23 20:11:07 by yperra-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	fill_matrix(t_node *node, t_lem_arifmetic *env_math)
{
	t_node	*end;

	if (!node || !env_math)
		return ;
	end = end_node(node);
	env_math->path++;
	while (end->parent)
	{
		env_math->matrix[end->parent->id][end->id] = env_math->path;
		end = end->parent;
	}
}

void	print_adj_matrix(int **matrix, int count_rooms)
{
	int	lines;
	int links;

	links = 0;
	lines = 0;
	while (lines <= count_rooms - 1)
	{
		printf("%d|", lines);
		while (links <= count_rooms - 1)
		{
			printf("%d", matrix[lines][links]);
			links++;
		}
		printf("\n");
		links = 0;
		lines++;
	}
	printf("\n");
}

void	clear_adj_matrix(int **matrix, int lines)
{
	while (--lines >= 0)
		free(matrix[lines]);
	free(matrix);
	return ;
}

void	add_links_at_adj_matrix(int **matrix, t_node *node)
{
	int		count_links;

	count_links = 0;
	if (!node)
		return ;
	while (node)
	{
		count_links = node->count_connect;
		while (count_links-- && node->links[count_links])
			matrix[node->id][node->links[count_links]->id] = 1;
		node = node->next;
	}
}

int		**init_adj_matrix(int count_rooms, t_node *node)
{
	int	**matrix;
	int	lines;
	int	numbers;

	lines = 0;
	numbers = 0;
	if (!(matrix = (int **)malloc(count_rooms * sizeof(int *))))
		error();
	while (lines < count_rooms)
	{
		if (!(matrix[lines] = (int *)malloc(count_rooms * sizeof(int))))
		{
			clear_adj_matrix(matrix, lines);
			error();
		}
		while (numbers <= count_rooms - 1)
		{
			matrix[lines][numbers] = 0;
			numbers++;
		}
		numbers = 0;
		lines++;
	}
	add_links_at_adj_matrix(matrix, node);
	return (matrix);
}
