/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_flr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkotenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/10 11:22:28 by dkotenko          #+#    #+#             */
/*   Updated: 2018/02/10 11:22:31 by dkotenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	print_result(int y, int x)
{
	ft_putnbr(y);
	write(1, " ", 1);
	ft_putnbr(x);
	write(1, "\n", 1);
}

int		base_flr(char me, char he)
{
	t_sum		sum;
	t_field		*flr_field;
	t_field		*flr_token;
	t_dpoint	dpoint;
	int			res;

	sum.me = me;
	sum.he = he;
	atoi_map_fielt(&sum);
	flr_field = field(&sum);
	dpoint = distance(flr_field, &sum);
	atoi_map_token(&sum);
	flr_token = token(&sum);
	res = bust_run(dpoint, &flr_token, flr_field, &sum);
	if (res == 1)
		print_result(0, 0);
	else
		print_result(flr_token[0].y, flr_token[0].x);
	free(flr_token);
	free(flr_field);
	return (res);
}
