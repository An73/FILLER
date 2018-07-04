/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_field.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkotenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 19:10:06 by dkotenko          #+#    #+#             */
/*   Updated: 2018/02/19 19:10:08 by dkotenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_field		*token_null(t_field *flr_token)
{
	flr_token[0].x = -1;
	return (flr_token);
}

t_field		*token_field(t_field *flr_token,\
	t_dpoint dpoint_token, t_dpoint dpoint, t_sum *sum)
{
	long int		i;
	long int		xp;
	long int		yp;

	i = 0;
	if (dpoint_token.x > dpoint.x || dpoint_token.y > dpoint.y)
		return (token_null(flr_token));
	xp = dpoint.x - dpoint_token.x;
	yp = dpoint.y - dpoint_token.y;
	dpoint_token.x = dpoint.x;
	dpoint_token.y = dpoint.y;
	while (i < (sum->x_token * sum->y_token))
	{
		if (flr_token[i].point != '.' || i == 0)
		{
			flr_token[i].x = flr_token[i].x + xp;
			if (flr_token[i].x >= sum->x_fielt)
				return (token_null(flr_token));
			flr_token[i].y = flr_token[i].y + yp;
			if (flr_token[i].y >= sum->y_fielt)
				return (token_null(flr_token));
		}
		i++;
	}
	return (flr_token);
}
