/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgendry <rgendry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 16:58:29 by rgendry           #+#    #+#             */
/*   Updated: 2019/10/02 18:57:42 by rgendry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_lem	*make_lem()
{
	t_lem	*new;

	if (!(new = (t_lem*)malloc(sizeof(t_lem))))
		return (NULL);
	new->ants = 0;
	new->end = NULL;
	new->start = NULL;
	new->nodes = NULL;
	new->links = NULL;
	return (new);
}

void	validation()
{
	t_lem *lem;

	lem = make_lem();
	get_ants(lem);
	get_data(lem);
}
