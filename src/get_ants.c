/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ants.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idunaver <idunaver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 18:12:50 by idunaver          #+#    #+#             */
/*   Updated: 2019/10/07 18:43:29 by idunaver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		validation_of_ants(char *line)
{
	char	*tmp;
	int		first_number;

	first_number = 0;
	tmp = line;
	while (*line)
	{
		if (first_number == 0 && *line == 48)
			return (-1);
		else
			first_number = 1;
		if (*line >= 48 && *line <=57)
			line++;
		else
			return (-1);
	}
	return (1);
}

void	get_ants(t_lem_arifmetic *env_math)
{
	char	*line;

	line = NULL;
	while (get_next_line(0, &line) > 0)
	{
		if (line[0] == '#')
			break ;
	}
	if (line = NULL)
		error();
	if (validation_of_ants(line) == -1)
		error();
	env_math->count_ants = ft_atoi(line);
	free(line);
	if (env_math->count_ants <= 0)
		error();
}
