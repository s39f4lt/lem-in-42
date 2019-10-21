/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prints.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idunaver <idunaver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 16:02:49 by idunaver          #+#    #+#             */
/*   Updated: 2019/10/21 20:24:03 by idunaver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	print_array(char **array)
{
	int i;

	i = 0;
	while (array[i])
	{
		printf("array[%d] - %s\n", i, array[i]);
		i++;
	}
}

void	print_list(t_links *links, t_node *node)
{
	printf("node\n\n");
	while (node)
	{
		printf("name - %s\n", node->name);
		printf("accept - %d\n", node->accept);
		node->parent ? printf("parent: %s\n", node->parent->name) \
		: printf("NULL\n");
		node = node->next;
	}
	links = NULL;
}

void	print_path(t_struct *struct_pointer)
{
	t_struct	*head;
	t_path		*copy;

	head = struct_pointer;
	while (struct_pointer)
	{
		printf("\nlength - %d", struct_pointer->length);
		printf("\n");
		copy = struct_pointer->path;
		while (copy)
		{
			printf("%s\n", copy->name);
			copy = copy->next;
		}
		struct_pointer = struct_pointer->next;
	}
	struct_pointer = head;
}
