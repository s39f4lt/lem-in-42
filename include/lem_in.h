/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idunaver <idunaver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 15:06:43 by idunaver          #+#    #+#             */
/*   Updated: 2019/10/11 17:21:51 by idunaver         ###   ########.fr       */
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
	int					iter;
	int					id;
	int					start_or_end;
	int					accept;
	struct s_node		*next;
	struct s_node		*previous;
	struct s_node		**links;
	struct s_node		*parent;
}						t_node;

typedef struct			s_links
{
	char				**link;
	struct s_links		*next;
	struct s_links		*prev;
}						t_links;

typedef struct			s_lem_arifmetic
{
	char				*line;
	int					count_ants;
	int					**matrix;
	int					count_rooms;
	int					path;
}						t_lem_arifmetic;

typedef struct			s_queque
{
	t_node				*name;
	struct s_queque		*next;
}						t_queque;

void					error(void);
void					add_node(t_node **begin_list, char *name, \
int count_connect, int flag);
t_node					*init_node(char *name, int count_connect, int flag);
void					free_nodes(t_node *nodes);
void					get_ants(t_lem_arifmetic *env_math);
void					quick_sort(int *av, int left, int right, int len);
int						search_index(int *av, int number, int len);
int						quick_select(int *av, int start, int medium, int end);
int						check_repeat_coord(int *x, int *y);
t_links					*init_links(char **links);
void					add_links(t_links *begin_list, char **links);
void					free_links(t_links *links);
void					lem_in(void);
void					print_array(char **array);
t_node					*eject_elem(t_node **node, int flag);
void					add_node_elem(t_node **node, \
t_node *current_elem, int flag);
void					add_id_in_nodes(t_node *node, \
t_lem_arifmetic *env_math);
int						**init_adj_matrix(int count_rooms, t_node *node);
void					print_adj_matrix(int **matrix, int count_rooms);
void					breadth_first_search(t_node *node, t_lem_arifmetic *env_math);
void					push_queque(t_queque **queque, t_node *node);
t_queque				*init_queque(t_node *node);
void					pop_queque(t_queque **queque);
void					free_queque(t_queque *queque);
void					add_links_at_adj_matrix(int **matrix, t_node *node);
void					clear_adj_matrix(int **matrix, int lines);

#endif
