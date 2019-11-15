/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_book.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idunaver <idunaver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 15:18:00 by idunaver          #+#    #+#             */
/*   Updated: 2019/10/24 18:39:00 by idunaver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	cat_in_book(t_lem_arifmetic **env_math)
{
	char	*copy;

	copy = ft_strnew(ft_strlen((*env_math)->book) + \
	ft_strlen((*env_math)->line) + 1);
	ft_strcat(copy, (*env_math)->book);
	ft_strcat(copy, (*env_math)->line);
	ft_strcat(copy, "\n");
	ft_strdel(&(*env_math)->line);
	ft_strdel(&(*env_math)->book);
	(*env_math)->book = copy;
}
