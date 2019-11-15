/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   regex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yperra-f <yperra-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 18:48:02 by idunaver          #+#    #+#             */
/*   Updated: 2019/10/24 21:19:41 by yperra-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		ft_regex(char *line, char *pattern)
{
	regex_t		preg;
	int			regerr;

	if (regcomp(&preg, pattern, REG_EXTENDED) != 0)
		error();
	regerr = regexec(&preg, line, 0, NULL, 0);
	regfree(&preg);
	if (regerr != 0)
		error();
	return (1);
}
