/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adj_matrix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idunaver <idunaver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 18:32:38 by idunaver          #+#    #+#             */
/*   Updated: 2019/10/18 19:29:04 by idunaver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

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
	while (lines >= 0)
	{
		free(matrix[lines]);
		lines--;
	}
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
		while (count_links--)
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
