/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkotenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 16:59:14 by dkotenko          #+#    #+#             */
/*   Updated: 2018/02/09 16:59:17 by dkotenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_field		*reading_t(t_sum *sum, t_field *flr_token)
{
	char		*str;
	char		*str_free;
	long int	x;
	long int	y;
	long int	i;

	i = 0;
	y = -1;
	str = NULL;
	while (sum->y_token > ++y)
	{
		get_next_line(0, &str);
		str_free = str;
		x = -1;
		while (sum->x_token > ++x)
		{
			flr_token[i].x = x;
			flr_token[i].y = y;
			flr_token[i].point = (*str);
			i++;
			str++;
		}
	}
	free(str_free);
	return (flr_token);
}

t_field		*token(t_sum *sum)
{
	t_field		*flr_token;

	flr_token = (t_field*)malloc(sizeof(t_field) * sum->x_token * sum->y_token);
	flr_token = reading_t(sum, flr_token);
	return (flr_token);
}
