/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tracking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkotenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 19:02:13 by dkotenko          #+#    #+#             */
/*   Updated: 2018/02/19 19:02:14 by dkotenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		trckng(t_field *field, t_field *token, t_sum *sum)
{
	long int		i;
	long int		j;

	i = 0;
	while (i < (sum->x_token * sum->y_token))
	{
		j = 0;
		while (!(j == -1))
		{
			if (token[i].point == '.' && i++)
				j = -2;
			else if (token[i].x == field[j].x && token[i].y == field[j].y)
			{
				if (field[j].point == '.' || field[j].point == '+')
				{
					i++;
					j = -2;
				}
				else
					return (0);
			}
			j++;
		}
	}
	return (1);
}
