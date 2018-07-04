/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distance.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkotenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/10 13:25:46 by dkotenko          #+#    #+#             */
/*   Updated: 2018/02/10 13:27:05 by dkotenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int			d_free(t_field *flr_field, long int i, t_sum *sum)
{
	if (flr_field[i + 1].point == '.' || flr_field[i - 1].point == '.'\
	|| flr_field[i + sum->x_fielt].point == '.'\
	|| flr_field[i - sum->x_fielt].point == '.')
		return (1);
	return (0);
}

t_dpoint	compare(t_dpoint dpoint, t_field *flr_field, long int i, t_sum *sum)
{
	long int	j;
	t_dpoint	dpoint_temp;

	j = 0;
	while (j < (sum->x_fielt * sum->y_fielt))
	{
		if (flr_field[j].point == sum->he && d_free(flr_field, j, sum) == 1)
		{
			dpoint_temp.d = vector_distance(flr_field[j].x, flr_field[j].y,\
			flr_field[i].x, flr_field[i].y);
			if (dpoint_temp.d < dpoint.d || dpoint.d == -1)
			{
				dpoint.x = flr_field[i].x;
				dpoint.y = flr_field[i].y;
				dpoint.d = dpoint_temp.d;
				dpoint.xh = flr_field[j].x;
				dpoint.yh = flr_field[j].y;
			}
		}
		j++;
	}
	return (dpoint);
}

int			dpoint_write(t_dpoint *dpoint, t_field *flr_field, int i)
{
	dpoint->x = flr_field[i].x;
	dpoint->y = flr_field[i].y;
	dpoint->d = 10000;
	return (-2);
}

t_dpoint	distance(t_field *flr_field, t_sum *sum)
{
	long int	i;
	t_dpoint	dpoint;

	i = 0;
	dpoint.xh = sum->x_fielt - 1;
	dpoint.yh = sum->y_fielt - 1;
	dpoint.d = -1;
	while (i < (sum->x_fielt * sum->y_fielt))
	{
		if ((flr_field[i].point == sum->me) && d_free(flr_field, i, sum) == 1)
			dpoint = compare(dpoint, flr_field, i, sum);
		i++;
	}
	if (dpoint.d == -1)
	{
		i = 0;
		while (i != -1)
		{
			if (flr_field[i].point == sum->me)
				i = dpoint_write(&dpoint, flr_field, i);
			i++;
		}
	}
	return (dpoint);
}
