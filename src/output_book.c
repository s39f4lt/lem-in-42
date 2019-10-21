/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_book.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idunaver <idunaver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 15:18:00 by idunaver          #+#    #+#             */
/*   Updated: 2019/10/21 17:15:20 by idunaver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

// char	*ft_strjoin_extra(char *s1, char *s2)
// {
// 	char	*result;

// 	result = ft_strjoin(s1, s2);
// 	ft_strdel(&s1);
// 	return (result);
// }

void	cat_in_book(t_lem_arifmetic **env_math)
{
	char	*copy;

	copy = ft_strnew(ft_strlen((*env_math)->book) + ft_strlen((*env_math)->line) + 1);
	//(*env_math)->book = ft_strjoin_extra((*env_math)->book, \
	//ft_strcat((*env_math)->line, "\n"));
	ft_strcat(copy, (*env_math)->book);
	ft_strcat(copy, (*env_math)->line);
	ft_strcat(copy, "\n");
	ft_strdel(&(*env_math)->line);
	ft_strdel(&(*env_math)->book);
	(*env_math)->book = copy;
}
