/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idunaver <idunaver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 15:56:58 by idunaver          #+#    #+#             */
/*   Updated: 2019/10/06 21:30:02 by idunaver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		count_nodes(t_lem *lem)
{
	t_lem	*tmp;
	int		count;

	count = 0;
	tmp = lem;
	while (tmp->nodes->next)
	{
		count++;
		tmp->nodes = tmp->nodes->next;
	}
	return (count);
}

int		**create_adjacency_matrix(t_lem	*lem)
{
	int **matrix;
	int	count_n;
	int tmp;

	tmp = 0;
	count_n = count_nodes(lem);
	if (!(matrix = (int **)malloc((count_n + 1) * sizeof(int *))))
		exit(EXIT_FAILURE);
	while (tmp != )
}

int		main(void)
{
	// validation();
	
	return (0);
}
