/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgendry <rgendry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 17:21:20 by rgendry           #+#    #+#             */
/*   Updated: 2019/10/05 20:32:27 by rgendry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	set_start(t_lem *lem)
{
	char	*line;
	char	**data;

	if (lem->start)
		error();
	get_next_line(0, &line);
	ft_printf("%s\n", line);
	data = ft_strsplit(line, ' ');
	if (arr_len(data) != 3 || !(check_int(data[1])) || !(check_int(data[2])))
	{
		free_arr(&data);
		ft_strdel(&line);
		error();
	}
	if (check_node(data[0], lem))
	{
		add_node(create_node(data[0]), lem);
		lem->start = ft_strdup(data[0]);
	}
	lem->size++;
	free_arr(&data);
	ft_strdel(&line);
}

void	set_end(t_lem *lem)
{
	char	*line;
	char	**data;

	if (lem->end)
		error();
	get_next_line(0, &line);
	ft_printf("%s\n", line);
	data = ft_strsplit(line, ' ');
	if (arr_len(data) != 3 || !(check_int(data[1])) || !(check_int(data[2])))
	{
		free_arr(&data);
		ft_strdel(&line);
		error();
	}
	if (check_node(data[0], lem))
	{
		add_node(create_node(data[0]), lem);
		lem->end = ft_strdup(data[0]);
	}
	lem->size++;
	free_arr(&data);
	ft_strdel(&line);
}

int		check_comment(char **line, t_lem *lem)
{
	if (!**line)
		error();
	ft_printf("%s\n", *line);
	if (!(ft_strcmp(*line, "##start")))
	{
		ft_strdel(line);
		set_start(lem);
	}
	else if (!(ft_strcmp(*line, "##end")))
	{
		ft_strdel(line);
		set_end(lem);
	}
	else if ((*line)[0] == '#')
	{
		ft_strdel(line);
		return (1);
	}
	return (0);
}

void	get_ants(t_lem *lem)
{
	int		i;
	char	*line;

	i = 0;
	get_next_line(0, &line);
	while (check_comment(&line, lem) == 1)
		get_next_line(0, &line);
	while (line[i])
	{
		if (!(line[i] >= '0' && line[i] <= '9'))
			error();
		i++;
	}
	lem->ants = ft_atoi(line);
	ft_strdel(&line);
	if (lem->ants < 1)
		error();
}

void	get_data(t_lem *lem)
{
	char	*line;

	line = NULL;
	while (get_next_line(0, &line))
	{
		if (!check_comment(&line, lem))
		{
			if (check_char(line, ' '))
				get_node(line, lem);
			else if (check_char(line, '-'))
				get_link(line, lem);
		}
	}
	if (!(lem->start) || !(lem->end) || !lem->links || !lem->nodes)
		error();
}
