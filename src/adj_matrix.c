/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adj_matrix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idunaver <idunaver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 18:32:38 by idunaver          #+#    #+#             */
/*   Updated: 2019/10/10 19:43:31 by idunaver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

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

int		**init_adj_matrix(int count_rooms)
{
	int	**matrix;
	int	lines;
	int	numbers;

	lines = 0;
	numbers = 0;
	if (!(matrix = (int **)malloc(count_rooms * sizeof(int *))))
		error();
	while (lines != count_rooms)
	{
		if (!(matrix[lines] = (int *)malloc(count_rooms * sizeof(int))))
		{
			clear_adj_matrix(matrix, lines);
			error();
		}
		while (numbers != count_rooms - 1)
		{
			matrix[lines][numbers] = 0;
			numbers++;
		}
		numbers = 0;
		lines++;
	}
	return (matrix);
}

void	add_links_at_adj_matrix(int **matrix, t_node *node)
{
	t_node	*tmp;
	int		room;
	int		count_links;
	int		connect;

	count_links = 0;
	room = 0;
	tmp = node;
	if (!tmp)
		return ;
	while (tmp->next)
	{
		count_links = tmp->count_connect;
		while (count_links--)
			matrix[room][tmp->links[count_links - 1]->id] = 1;
		tmp = tmp->next;
	}
}
