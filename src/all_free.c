/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idunaver <idunaver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 15:43:09 by idunaver          #+#    #+#             */
/*   Updated: 2019/10/24 18:35:12 by idunaver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	all_free(t_struct **struct_pointer, \
t_lem_arifmetic *env_math, t_node **node)
{
	ft_strdel(&env_math->book);
	free_nodes(node);
	free_struct(struct_pointer);
	clear_adj_matrix(env_math->matrix, env_math->count_rooms);
}
