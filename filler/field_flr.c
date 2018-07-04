/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   field_flr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkotenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 16:09:36 by dkotenko          #+#    #+#             */
/*   Updated: 2018/02/09 16:09:37 by dkotenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include <stdio.h>

t_field		*reading(t_sum *sum, t_field *flr_field)
{
	char			*str;
	char			*str_free;
	long int		x;
	long int		y;
	long int		i;

	i = 0;
	y = -1;
	while (sum->y_fielt > ++y)
	{
		str = NULL;
		str_free = str;
		get_next_line(0, &str);
		str += 4;
		x = -1;
		while (sum->x_fielt > ++x)
		{
			flr_field[i].x = x;
			flr_field[i].y = y;
			flr_field[i++].point = (*str);
			str++;
		}
		free(str_free);
	}
	return (flr_field);
}

t_field		*field(t_sum *sum)
{
	char		*str;
	t_field		*flr_field;

	flr_field = (t_field*)malloc(sizeof(t_field) * sum->x_fielt * sum->y_fielt);
	get_next_line(0, &str);
	flr_field = reading(sum, flr_field);
	free(str);
	return (flr_field);
}
