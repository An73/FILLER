/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rewrite.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkotenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 10:13:15 by dkotenko          #+#    #+#             */
/*   Updated: 2018/02/12 10:13:18 by dkotenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_field		*rewrite_field(t_field *flr_field, t_field *re_field, t_sum *sum)
{
	int		i;

	i = 0;
	while (i < (sum->x_fielt * sum->y_fielt))
	{
		re_field[i] = flr_field[i];
		i++;
	}
	return (re_field);
}

t_field		*rewrite_field_dot(t_field *flr_field,\
t_field *re_field, t_sum *sum)
{
	int		i;

	i = 0;
	while (i < (sum->x_fielt * sum->y_fielt))
	{
		if (re_field[i].point != '.')
			re_field[i] = flr_field[i];
		i++;
	}
	return (re_field);
}

t_field		*rewrite_token(t_field *flr_token, t_field *re_token, t_sum *sum)
{
	int		i;

	i = 0;
	while (i < (sum->x_token * sum->y_token))
	{
		re_token[i] = flr_token[i];
		i++;
	}
	return (re_token);
}

t_field		*rewrite_token_dot(t_field *flr_token,\
t_field *re_token, t_sum *sum)
{
	int		i;

	i = 0;
	while (i < (sum->x_token * sum->y_token))
	{
		if (i == 0 || re_token[i].point != '.')
			re_token[i] = flr_token[i];
		i++;
	}
	return (re_token);
}
