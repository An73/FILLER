/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_plus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkotenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 11:52:23 by dkotenko          #+#    #+#             */
/*   Updated: 2018/02/12 11:52:25 by dkotenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		read_plus_field(t_field *flr_field, t_sum *sum)
{
	long int		i;

	i = 0;
	while (i < (sum->x_fielt * sum->y_fielt))
	{
		if (flr_field[i].point == sum->me)
			return (0);
		i++;
	}
	return (1);
}

int		read_plus_token(t_field *flr_token, t_sum *sum)
{
	long int		i;

	i = 0;
	while (i < (sum->x_token * sum->y_token))
	{
		if (flr_token[i].point == '*')
			return (0);
		i++;
	}
	return (1);
}
