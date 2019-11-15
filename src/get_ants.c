/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ants.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yperra-f <yperra-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 18:12:50 by idunaver          #+#    #+#             */
/*   Updated: 2019/10/24 21:13:54 by yperra-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int		validation_of_ants(char *line)
{
	char	*tmp;
	int		first_number;

	first_number = 0;
	tmp = line;
	while (*tmp)
	{
		if (first_number == 0 && *tmp == 48)
			return (-1);
		else
			first_number = 1;
		if (*tmp >= 48 && *tmp <= 57)
			tmp++;
		else
			return (-1);
	}
	return (1);
}

void			get_ants(t_lem_arifmetic **env_math)
{
	while (get_next_line(0, &(*env_math)->line) > 0)
	{
		if ((*env_math)->line[0] != '#')
			break ;
		ft_strdel(&(*env_math)->line);
		error();
	}
	if ((*env_math)->line == NULL)
		error();
	if (validation_of_ants((*env_math)->line) == -1)
		error();
	(*env_math)->count_ants = ft_atoi((*env_math)->line);
	ft_strdel(&(*env_math)->line);
	if ((*env_math)->count_ants <= 0)
		error();
	(*env_math)->ants = ft_itoa((*env_math)->count_ants);
	(*env_math)->book = ft_strjoin((*env_math)->ants, "\n");
	free((*env_math)->ants);
}
