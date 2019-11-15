/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idunaver <idunaver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 12:54:14 by yperra-f          #+#    #+#             */
/*   Updated: 2019/10/07 19:10:37 by idunaver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int				quick_select(int *av, int start, int medium, int end)
{
	if (av[start] > av[medium])
	{
		if (av[start] < av[end])
			return (av[start]);
		else if (av[end] > av[medium])
			return (av[end]);
		else
			return (av[medium]);
	}
	else
	{
		if (av[start] > av[end])
			return (av[start]);
		else if (av[end] > av[medium])
			return (av[medium]);
		else
			return (av[medium]);
	}
	return (0);
}

static	void	swap_num(int *av, int index1, int index2)
{
	int tmp;

	tmp = av[index1];
	av[index1] = av[index2];
	av[index2] = tmp;
}

int				search_index(int *av, int number, int len)
{
	int i;

	i = 0;
	while (len--)
	{
		if (av[i++] == number)
			return (--i);
	}
	return (0);
}

void			quick_sort(int *av, int left, int right, int len)
{
	int pivot;
	int l_left;
	int r_right;

	if (left < right)
	{
		l_left = left;
		r_right = right;
		pivot = quick_select(av, left, (right + left) / 2, right);
		while (left < right)
		{
			while (av[left] <= pivot && left < right)
				left++;
			while (av[right] > pivot)
				right--;
			if (left < right)
				swap_num(av, left, right);
		}
		swap_num(av, search_index(av, pivot, len), right);
		pivot = right;
		quick_sort(av, l_left, pivot - 1, len);
		quick_sort(av, pivot + 1, r_right, len);
	}
}
