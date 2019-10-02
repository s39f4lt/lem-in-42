/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgendry <rgendry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 17:21:20 by rgendry           #+#    #+#             */
/*   Updated: 2019/10/02 20:19:52 by rgendry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		check_comment(char *line)
{
	if (!line)
		error();
	ft_printf("%s\n", line);
	if (line[0] == '#' && (ft_strcmp(line, "##start") || ft_strcmp(line, "##end")))
		return (1);
	return (0);
}

void	get_ants(t_lem *lem)
{
	int		i;
	char	*line;

	i = 0;
	get_next_line(0, &line);
	while (check_comment(line) == 1)
	{
		free(line);
		get_next_line(0, &line);
	}
	while (line[i])
	{
		if (line[i] < '0' && line[i] > '9')
			error();
		i++;
	}
	lem->ants = ft_atoi(line);
	free(line);
	if (lem->ants < 1)
		error();
}

void	set_data(char *line, t_lem *lem)
{
	if (check_char(line, ' '))
		get_node(line, lem);
	else if (check_char(line, '-'))
		get_link(line, lem);
}

void	get_data(t_lem *lem)
{
	char	*line;

	line = NULL;
	while (get_next_line(0, &line))
	{
		if (!check_comment(line))
			set_data(line, lem);
	}
}
