/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkotenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 12:43:40 by dkotenko          #+#    #+#             */
/*   Updated: 2018/02/09 12:43:42 by dkotenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		main(void)
{
	char	*str;
	int		i;
	char	me;
	char	he;

	i = 0;
	get_next_line(0, &str);
	if (ft_strstr(str, "p1") != NULL)
	{
		me = 'O';
		he = 'X';
	}
	else
	{
		me = 'X';
		he = 'O';
	}
	while (i == 0)
		i = base_flr(me, he);
}
