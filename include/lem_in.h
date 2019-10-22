/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idunaver <idunaver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 15:06:43 by idunaver          #+#    #+#             */
/*   Updated: 2019/10/22 22:14:00 by idunaver         ###   ########.fr       */
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
	char				*start;
	int					count_ants;
	int					**matrix;
	int					count_rooms;
	int					path;
	int					count_path;
	char				*ants;
	char				*book;
}						t_lem_arifmetic;

typedef struct			s_queque
{
	t_node				*name;
	struct s_queque		*next;
}						t_queque;

typedef struct			s_path
{
	char				*name;
	struct s_path		*next;
}						t_path;

typedef struct			s_struct
{
	t_path				*path;
	int					length;
	struct s_struct		*next;
}						t_struct;

typedef struct			s_ant
{
	int					id;
	int					length;
	t_path				*node;
	t_path				*path;
}						t_ant;


typedef struct			s_group
{
	int 				count;
	int					length;
	t_path				*way;
}						t_group;


/* check_repeat */
int						check_repeat_coord(int *x, int *y);
/* create_path */
t_path					*init_struct_path(t_struct *struct_pointer, t_node *end);
t_struct				*init_struct_res(t_node *end);
t_struct				*init_list_for_path(t_node *end, t_struct *path);
/* error */
void					error(void);
/* get_ants */
void					get_ants(t_lem_arifmetic **env_math);
/* id_node */
void					add_id_in_nodes(t_node *node, t_lem_arifmetic *env_math);
/* lem_in */
void					lem_in(void);
void					check_cross_line(t_lem_arifmetic *env_math);
t_node					*search_address(t_node *node, t_links *links, t_node *current_elem);
void					first_init_nulling(t_links **links, t_node **node, t_struct **struct_pointer, t_lem_arifmetic *env_math);
/* links */
t_links					*init_links(char **links);
void					add_links(t_links *begin_list, char **links);
/* node */
void					start_mid_end_elem(t_node *new_elem, int flag);
t_node					*init_node(char *name, int count_connect, int flag);
void					add_node(t_node **begin_list, char *name, int count_connect, int flag);
t_node					*eject_elem(t_node **node, int flag);
void					add_node_elem(t_node **node, t_node *current_elem, int flag);
/* path_for_ants */
int						calc_path_for_ants(t_struct *path, t_lem_arifmetic *env_math);
void					sort_path(t_struct **path);
t_struct				*swap_elems(t_struct **current, t_struct **next, t_struct **prev);
int						calc_length_one_path(t_path *path);
int						calc_count_path(t_struct *struct_pointer, int ants, int count_path);
/* queque */
void					push_queque(t_queque **queque, t_node *node);
t_queque				*init_queque(t_node *node);
void					pop_queque(t_queque **queque);
/* quick_sort */
void					quick_sort(int *av, int left, int right, int len);
int						search_index(int *av, int number, int len);
int						quick_select(int *av, int start, int medium, int end);
/* adj_matrix */
void					print_adj_matrix(int **matrix, int count_rooms);
void					clear_adj_matrix(int **matrix, int lines);
void					add_links_at_adj_matrix(int **matrix, t_node *node);
int						**init_adj_matrix(int count_rooms, t_node *node);
void					fill_matrix(t_node *node, t_lem_arifmetic *env_math);
/* breadth_first_search */
t_node					*breadth_first_search(t_node *node, \
t_lem_arifmetic *env_math);
int						check_matrix(int **matrix, int x, int y);
void					print_queque(t_queque *queque);
t_node					*end_is_found(t_node *node, t_lem_arifmetic *env_math, t_queque **queque, t_node *end);
t_node					*end_node(t_node *node);
/* nuller */
void					null_accept_and_matrix(t_node *node, t_lem_arifmetic *env_math);
void					null_parent(t_node *node, t_lem_arifmetic *env_math);
void					null_links(t_node *node, t_lem_arifmetic *env_math);
/* all_free_1 */
void					free_queque(t_queque **queque);
void					free_nodes(t_node **nodes);
void					free_links(t_links **links);
void					ft_free(char **elem);
/* all_free_2 */
t_struct				*free_struct(t_struct **path);
void					free_path(t_path **path);
/* valid */
void					first_elem_node(t_lem_arifmetic **env_math, t_node **node);
void					ft_connect(t_links **links, char **elem);
void					ft_node(t_node **node, char **elem, int flag);
void					last_elem_node(t_lem_arifmetic **env_math, t_node **node);
void					parse_map(t_lem_arifmetic *env_math, t_links **links, t_node **node);
/* output_book */
void					cat_in_book(t_lem_arifmetic **env_math);
char					*ft_strjoin_extra(char	*s1, char *s2);
/* prints */
void					print_list(t_links *links, t_node *node);
void					print_array(char **array);
void					print_path(t_struct *struct_pointer);
/* init_struct */
void					rebuild_struct(t_node **node);
int						init_struct(t_lem_arifmetic *env_math, t_links **links, t_node **node);
/* array_node */
int						array_node(t_node *node, t_links *links);
void					init_node_arr(t_node *node, t_links *links);
void					count_connect(t_node *node, t_links *links);
/* print_result */
void					go_ants(t_lem_arifmetic *env_math, t_struct *pointer_struct);

#endif
