/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_plus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkotenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 12:11:54 by dkotenko          #+#    #+#             */
/*   Updated: 2018/02/12 12:11:57 by dkotenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_field		*token_plus(t_field *flr_token, t_dpoint dpoint_token, t_sum *sum)
{
	long int		i;

	i = 0;
	while (i < (sum->x_token * sum->y_token))
	{
		if (flr_token[i].x == dpoint_token.x\
			&& flr_token[i].y == dpoint_token.y)
			flr_token[i].point = '+';
		i++;
	}
	return (flr_token);
}
