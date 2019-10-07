/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idunaver <idunaver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 15:06:43 by idunaver          #+#    #+#             */
/*   Updated: 2019/10/07 15:54:29 by idunaver         ###   ########.fr       */
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
	char			*start;
	char			*end;
	struct s_node	*nodes;
	struct s_link	*links;
}					t_lem;

typedef struct		s_node
{
	int				id;
	char			*name;
	int				x;
	int				y;
	struct s_node	*next;
}					t_node;

typedef struct		s_link
{
	char			**name;
	struct s_link	*next;
}					t_link;

// typedef struct		s_link
// {
// 	int				v;
// 	int				u;
// 	double			dist;
// 	struct s_link	*next;
// }					t_link;

typedef struct		s_path
{
	int				u;
	double			dist;
	struct s_path	*next;
}					t_path;

typedef struct		s_res
{
	int				ant;
	int				n;
	char			*name;
}					t_res;

typedef struct		s_env
{
	t_path			*queue;
	t_link			*link;
	t_path			**path;
	t_res			*res_path;
	int				ant;
	int				cnt;
	char			*start;
	char			*end;
	double			*dist;
	int				*res;
	int				size;
}					t_env;

void	validation();
void	get_ants(t_lem *lem);
void	get_data(t_lem *lem);
int		check_char(char *line, char c);
void	error(void);

#endif
