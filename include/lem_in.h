/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idunaver <idunaver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 15:06:43 by idunaver          #+#    #+#             */
/*   Updated: 2019/10/07 21:33:08 by idunaver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "libft.h"
# include <stdio.h>
# include <limits.h>
# include <fcntl.h>

typedef struct			s_node
{
	char				*name;
	int					level;
	int					count_connect;
	struct s_node		*next;
	struct s_node		*previous;
	struct s_node		**links;
}						t_node;

typedef struct			s_links
{
	char				**link;
	struct s_links		*next;
	struct s_links		*prev;
}						t_links;

typedef struct			s_lem_arifmetic
{
	char				**line;
	int					count_ants;
}						t_lem_arifmetic;

void					error(void);
void					add_node(t_node *begin_list, char *name, \
int count_connect);
t_node					*init_node(char *name, int count_connect);
void					free_nodes(t_node *nodes);
void					get_ants(t_lem_arifmetic *env_math);
int						validation_of_ants(char *line);
void					quick_sort(int *av, int left, int right, int len);
int						search_index(int *av, int number, int len);
int						quick_select(int *av, int start, int medium, int end);
int						check_repeat_coord(int *x, int *y);
t_links					*init_links(char **links);
void					add_links(t_links *begin_list, char **links);
void					free_links(t_links *links);
int						count_links(t_links *links);

#endif
