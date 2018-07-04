/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bust_run.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkotenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 12:06:37 by dkotenko          #+#    #+#             */
/*   Updated: 2018/02/20 12:06:38 by dkotenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_field		*plus_field(t_field *flr_field, t_dpoint dpoint)
{
	long int	i;

	i = 0;
	while (!(flr_field[i].x == dpoint.x && flr_field[i].y == dpoint.y))
		i++;
	flr_field[i].point = '+';
	return (flr_field);
}

t_field		*re_td(t_field **t_plus, t_field *t_backup,\
	t_field **flr_token, t_sum *sum)
{
	(*t_plus) = rewrite_token_dot(t_backup, (*t_plus), sum);
	(*flr_token) = rewrite_token_dot(t_backup, (*flr_token), sum);
	return ((*flr_token));
}

t_field		*f_plus_d(t_field *f_plus, t_dpoint *dpoint, t_sum *sum)
{
	f_plus = plus_field(f_plus, (*dpoint));
	if (read_plus_field(f_plus, sum) == 0)
		(*dpoint) = distance(f_plus, sum);
	return (f_plus);
}

int			bust_run(t_dpoint dpoint, t_field **flr_token,\
	t_field *flr_field, t_sum *sum)
{
	t_field		*f_backup;
	t_field		*f_plus;
	t_field		*t_plus;
	t_field		*t_backup;
	t_dpoint	dpoint_token;

	mllc_field(&f_plus, &f_backup, flr_field, sum);
	mllc_token(&t_plus, &t_backup, (*flr_token), sum);
	while (read_plus_field(f_plus, sum) == 0)
	{
		while (read_plus_token(t_plus, sum) == 0)
		{
			flr_field = plus_field(flr_field, dpoint);
			(*flr_token) = rewrite_token_dot(t_plus, (*flr_token), sum);
			dpoint_token = distance_token((*flr_token), sum, dpoint);
			(*flr_token) = token_field((*flr_token), dpoint_token, dpoint, sum);
			if ((*flr_token)[0].x != -1 && trckng(flr_field, (*flr_token), sum))
				return (free_flr(&f_plus, &t_plus, &f_backup, &t_backup));
			t_plus = token_plus(t_plus, dpoint_token, sum);
			flr_field = rewrite_field_dot(f_backup, flr_field, sum);
		}
		(*flr_token) = re_td(&t_plus, t_backup, flr_token, sum);
		f_plus = f_plus_d(f_plus, &dpoint, sum);
	}
	return (1);
}
