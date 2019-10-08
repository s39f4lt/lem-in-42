/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgendry <rgendry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 16:58:29 by rgendry           #+#    #+#             */
/*   Updated: 2019/10/05 20:33:12 by rgendry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	print_lem(t_lem *lem)
{
	ft_printf("ANTS: %d\n", lem->ants);
	ft_printf("SIZE: %d\n", lem->size);
	ft_printf("START: %s\n", lem->start);
	ft_printf("END: %s\n", lem->end);
	while (lem->nodes)
	{
		ft_printf("NAME: %s\n", lem->nodes->name);
		lem->nodes = lem->nodes->next;
	}
	while (lem->links)
	{
		ft_printf("LINK: %s-", lem->links->name1);
		ft_printf("%s\n", lem->links->name2);
		lem->links = lem->links->next;
	}
}

t_lem	*make_lem(void)
{
	t_lem	*new;

	if (!(new = (t_lem*)malloc(sizeof(t_lem))))
		return (NULL);
	new->ants = 0;
	new->size = 0;
	new->start = NULL;
	new->end = NULL;
	new->nodes = NULL;
	new->links = NULL;
	return (new);
}

void	validation(void)
{
	t_lem *lem;

	lem = make_lem();
	get_ants(lem);
	get_data(lem);
	print_lem(lem);
}
