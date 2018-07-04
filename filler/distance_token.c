/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distance_token.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkotenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/10 14:12:56 by dkotenko          #+#    #+#             */
/*   Updated: 2018/02/10 14:12:58 by dkotenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_dpoint	dist_token_temp(t_sum *sum, t_field *flr_token,\
t_dpoint distance_field, t_dpoint dpoint_token)
{
	t_dpoint		dpoint_temp;
	long int		j;

	j = 0;
	while (j < (sum->x_token * sum->y_token))
	{
		if (flr_token[j].point == '*')
		{
			dpoint_temp.d = vector_distance(flr_token[j].x,\
			flr_token[j].y, distance_field.xh, distance_field.yh);
			if (dpoint_token.d > dpoint_temp.d || dpoint_token.d == -1)
			{
				dpoint_token.d = dpoint_temp.d;
				dpoint_token.x = -5;
			}
		}
		j++;
	}
	return (dpoint_token);
}

t_dpoint	write_dpoint(t_field *flr_token, long int i)
{
	t_dpoint	dpoint_token;

	dpoint_token.x = flr_token[i].x;
	dpoint_token.y = flr_token[i].y;
	dpoint_token.d = 100000000;
	return (dpoint_token);
}

void		backup_token(t_field **flr_token_backup,\
t_dpoint *dpoint_token, t_field *flr_token, t_sum *sum)
{
	(*dpoint_token).d = -1;
	(*flr_token_backup) = (t_field*)malloc(sizeof(t_field)\
	* sum->x_token * sum->y_token);
	(*flr_token_backup) = rewrite_token(flr_token, (*flr_token_backup), sum);
}

t_dpoint	distance_token(t_field *flr_token,\
t_sum *sum, t_dpoint distance_field)
{
	t_dpoint	dpoint_token;
	t_field		*flr_token_backup;
	long int	i;

	i = -1;
	backup_token(&flr_token_backup, &dpoint_token, flr_token, sum);
	while (++i < (sum->x_token * sum->y_token))
	{
		if (flr_token[i].point == '*')
		{
			flr_token = token_dd(flr_token, i, distance_field, sum);
			if (flr_token[0].x != -4)
				dpoint_token = dist_token_temp(sum, flr_token,\
				distance_field, dpoint_token);
			if ((flr_token[0].x != -4 && dpoint_token.x == -5)\
			|| flr_token[0].x == -4)
			{
				flr_token = rewrite_token(flr_token_backup, flr_token, sum);
				dpoint_token = write_dpoint(flr_token, i);
			}
			flr_token = rewrite_token(flr_token_backup, flr_token, sum);
		}
	}
	free(flr_token_backup);
	return (dpoint_token);
}
