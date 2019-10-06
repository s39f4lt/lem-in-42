/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgendry <rgendry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 15:06:43 by idunaver          #+#    #+#             */
/*   Updated: 2019/10/02 18:57:58 by rgendry          ###   ########.fr       */
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
	char			*name;
	struct s_node	*next;
}					t_node;

typedef struct		s_link
{
	char			**name;
	struct s_link	*next;
}					t_link;

void	validation();
void	get_ants(t_lem *lem);
void	get_data(t_lem *lem);
int		check_char(char *line, char c);
void	error(void);

#endif
