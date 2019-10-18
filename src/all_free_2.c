/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_free_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idunaver <idunaver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 20:00:54 by idunaver          #+#    #+#             */
/*   Updated: 2019/10/18 20:22:16 by idunaver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		free_path(t_path *path)
{
	t_path	*next;

	next = NULL;
	while (path)
	{
		if (path->next)
			next = path->next;
		free(path);
		path = next;
		next = NULL;
	}
}

void		free_struct(t_struct *path)
{
	t_struct	*next;

	next = NULL;
	while (path)
	{
		if (path->next)
			next = path->next;
		free_path(path->path);
		path->length = 0;
		path->next = NULL;
		free(path);
		path = next;
		next = NULL;
	}
	return ;
}
