/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yperra-f <yperra-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 15:06:43 by idunaver          #+#    #+#             */
/*   Updated: 2019/10/24 21:52:18 by yperra-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# define PATTERN_NODE "^[0-9a-zA-Z_]+[ ][0-9]+[ ][0-9]+$"
# define PATTERN_LINKS "^[0-9a-zA-Z_]+[-][0-9a-zA-Z_]+$"

# include "libft.h"
# include <stdio.h>
# include <limits.h>
# include <fcntl.h>
# include <regex.h>

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
	int					i_a;
	int					i_g;
	int					count;
	char				*ants;
	char				*book;
	int					first;
	int					last;
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
	int					count;
	int					length;
	t_path				*way;
}						t_group;

int						check_repeat_coord(int *x, int *y);
t_path					*init_struct_path(t_struct *struct_pointer, \
t_node *end);
t_struct				*init_struct_res(t_node *end);
t_struct				*init_list_for_path(t_node *end, t_struct *path);
void					error(void);
void					get_ants(t_lem_arifmetic **env_math);
void					add_id_in_nodes(t_node *node, \
t_lem_arifmetic *env_math);
void					lem_in(void);
void					check_cross_line(t_lem_arifmetic *env_math);
t_node					*search_address(t_node *node, t_links *links, \
t_node *current_elem);
void					first_init_nulling(t_links **links, t_node **node, \
t_struct **struct_pointer, t_lem_arifmetic *env_math);
t_links					*init_links(char **links);
void					add_links(t_links *begin_list, char **links);
void					start_mid_end_elem(t_node *new_elem, int flag);
t_node					*init_node(char *name, int count_connect, int flag);
void					add_node(t_node **begin_list, char *name, \
int count_connect, int flag);
t_node					*eject_elem(t_node **node, int flag);
void					add_node_elem(t_node **node, \
t_node *current_elem, int flag);
int						calc_path_for_ants(t_struct *path, \
t_lem_arifmetic *env_math);
void					sort_path(t_struct **path);
t_struct				*swap_elems(t_struct **current, \
t_struct **next, t_struct **prev);
int						calc_length_one_path(t_path *path);
int						calc_count_path(t_struct *struct_pointer, \
int ants, int count_path);
void					push_queque(t_queque **queque, t_node *node);
t_queque				*init_queque(t_node *node);
void					pop_queque(t_queque **queque);
void					quick_sort(int *av, int left, int right, int len);
int						search_index(int *av, int number, int len);
int						quick_select(int *av, int start, int medium, int end);
void					print_adj_matrix(int **matrix, int count_rooms);
void					clear_adj_matrix(int **matrix, int lines);
void					add_links_at_adj_matrix(int **matrix, t_node *node);
int						**init_adj_matrix(int count_rooms, t_node *node);
void					fill_matrix(t_node *node, t_lem_arifmetic *env_math);
t_node					*breadth_first_search(t_node *node, \
t_lem_arifmetic *env_math);
int						check_matrix(int **matrix, int x, int y);
void					print_queque(t_queque *queque);
t_node					*end_is_found(t_node *node, t_lem_arifmetic *env_math, \
t_queque **queque, t_node *end);
t_node					*end_node(t_node *node);
void					null_accept_and_matrix(t_node *node, \
t_lem_arifmetic *env_math);
void					null_parent(t_node *node, t_lem_arifmetic *env_math);
void					null_links(t_node *node, t_lem_arifmetic *env_math);
void					free_queque(t_queque **queque);
void					free_nodes(t_node **nodes);
void					free_links(t_links **links);
void					ft_free(char **elem);
t_struct				*free_struct(t_struct **path);
void					free_path(t_path **path);
void					free_group(t_group	**group);
void					free_ants(t_ant	**ants);
void					first_elem_node(t_lem_arifmetic **env_math, \
t_node **node);
void					ft_connect(t_links **links, char **elem);
void					ft_node(t_node **node, char **elem, int flag);
void					last_elem_node(t_lem_arifmetic **env_math, \
t_node **node);
void					parse_map(t_lem_arifmetic *env_math, \
t_links **links, t_node **node);
void					cat_in_book(t_lem_arifmetic **env_math);
char					*ft_strjoin_extra(char	*s1, char *s2);
void					print_list(t_links *links, t_node *node);
void					print_array(char **array);
void					print_path(t_struct *struct_pointer);
void					rebuild_struct(t_node **node, t_node *current_elem, \
t_node *first_or_last_elem);
int						init_struct(t_lem_arifmetic *env_math, \
t_links **links, t_node **node);
int						array_node(t_node *node, t_links *links);
void					init_node_arr(t_node *node, t_links *links);
void					count_connect(t_node *node, t_links *links);
void					go_ants(t_lem_arifmetic *env_math, \
t_struct *pointer_struct, t_node *node);
int						set_ants(t_group *group, t_ant *ants, \
t_lem_arifmetic *env_math, t_node *node);
int						print_line(t_ant *ants, \
t_lem_arifmetic *env_math, int end, t_node *node);
void					split_ants(t_lem_arifmetic *env_math, t_group *group);
void					dist_of_remaining_ants(int ants, t_group *group, \
t_lem_arifmetic *env_math);
void					all_free(t_struct **struct_pointer, \
t_lem_arifmetic *env_math, t_node **node);
int						check_duplicate(t_node *node);
t_group					*init_group(t_lem_arifmetic *env_math, \
t_struct *pointer_struct);
t_ant					*init_ant(t_lem_arifmetic *env_math);
int						ft_regex(char *line, char *pattern);
void					search_address_norminete_2(t_node *current_elem, \
t_links *links, t_node *node);
void					search_address_norminete(t_node *current_elem, \
t_links *links, t_node *node);
t_node					*bfs_norminete(t_node *node);
void					add_node_elem_norminete(t_node *current_elem, \
t_node *first_elem, t_node **node);

#endif
