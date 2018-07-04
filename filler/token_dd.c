/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_dd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkotenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 17:30:29 by dkotenko          #+#    #+#             */
/*   Updated: 2018/02/19 17:30:31 by dkotenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int			token_dd_field(t_field **flr_token, int xp, int yp, int j)
{
	(*flr_token)[j].x = (*flr_token)[j].x + xp;
	(*flr_token)[j].y = (*flr_token)[j].y + yp;
	j++;
	return (j);
}

t_field		*token_dd(t_field *flr_token,\
	long int i, t_dpoint dpoint, t_sum *sum)
{
	long int		xp;
	long int		yp;

	xp = dpoint.x - flr_token[i].x;
	yp = dpoint.y - flr_token[i].y;
	i = -1;
	if (xp < 0 || yp < 0)
	{
		flr_token[0].x = -4;
		return (flr_token);
	}
	while (i++ < (sum->x_token * sum->y_token))
	{
		if (((flr_token[i].x + xp) >= sum->x_fielt ||\
		(flr_token[i].y + yp) >= sum->y_fielt)\
		|| ((flr_token[i].x + xp) < 0 || (flr_token[i].y + yp) < 0))
		{
			flr_token[0].x = -4;
			return (flr_token);
		}
	}
	i = 0;
	while (i < (sum->x_token * sum->y_token))
		i = token_dd_field(&flr_token, xp, yp, i);
	return (flr_token);
}
