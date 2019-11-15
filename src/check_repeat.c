/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_repeat.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idunaver <idunaver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 19:01:56 by idunaver          #+#    #+#             */
/*   Updated: 2019/10/07 19:52:37 by idunaver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	check_repeat_sorted_arr(int *arr, int len)
{
	int *tmp;

	tmp = arr;
	while (len--)
	{
		if (*tmp != *(tmp + 1))
			tmp++;
		else
			return (-1);
	}
	return (1);
}

int			check_repeat_coord(int *x, int *y)
{
	int	*tmp_x;
	int	*tmp_y;
	int	len_x;
	int	len_y;

	len_x = sizeof(x) / sizeof(*x);
	len_y = sizeof(y) / sizeof(*y);
	if (len_x == 1 && len_y == 1)
		return (1);
	if (len_x != 1)
	{
		tmp_x = x;
		quick_sort(tmp_x, 0, len_x - 1, len_x);
	}
	if (len_y != 1)
	{
		tmp_y = y;
		quick_sort(tmp_y, 0, len_y - 1, len_y);
	}
	if (check_repeat_sorted_arr(x, len_x) == -1)
		return (-1);
	if (check_repeat_sorted_arr(y, len_y) == -1)
		return (-1);
	return (1);
}
