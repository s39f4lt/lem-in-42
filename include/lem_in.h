/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgendry <rgendry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 15:06:43 by idunaver          #+#    #+#             */
/*   Updated: 2019/10/08 19:51:46 by rgendry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "libft.h"
# include <stdio.h>
# include <limits.h>
# include <fcntl.h>

typedef struct		s_lem
{
	int				ants;
	int				size;
	char			*start;
	char			*end;
	struct s_node	*nodes;
	struct s_link	*links;
	struct s_index	*index_map;
}					t_lem;

typedef struct		s_node
{
	char			*name;
	struct s_node	*next;
}					t_node;

typedef struct		s_link
{
	char			*name1;
	char			*name2;
	struct s_link	*next;
}					t_link;

typedef struct		s_index
{
	int				index;
	char			*name;
}					t_index;

void	validation();
void	get_ants(t_lem *lem);
void	get_data(t_lem *lem);
void	get_node(char *line, t_lem *lem);
void	add_node(t_node *node, t_lem *lem);
t_node	*create_node(char *name);
void	get_link(char *line, t_lem *lem);
void	index_map(t_lem *lem);
int		check_node(char *name, t_lem *lem);
int		check_char(char *line, char c);
int		check_int(char *str);
void	free_arr(char ***arr);
int		arr_len(char **arr);
void	error(void);

#endif
