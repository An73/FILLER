/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkotenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 16:56:58 by dkotenko          #+#    #+#             */
/*   Updated: 2018/02/09 16:57:58 by dkotenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	atoi_map_fielt(t_sum *sum)
{
	char		*str;
	char		*str_free;

	get_next_line(0, &str);
	sum->y_fielt = 0;
	sum->x_fielt = 0;
	str_free = str;
	while (!(*str >= '0' && *str <= '9'))
		str++;
	while (*str >= '0' && *str <= '9')
	{
		sum->y_fielt = sum->y_fielt * 10 + *str - '0';
		str++;
	}
	str++;
	while (*str >= '0' && *str <= '9')
	{
		sum->x_fielt = sum->x_fielt * 10 + *str - '0';
		str++;
	}
	free(str_free);
}

void	atoi_map_token(t_sum *sum)
{
	char		*str;
	char		*str_free;

	get_next_line(0, &str);
	sum->y_token = 0;
	sum->x_token = 0;
	str_free = str;
	while (!(*str >= '0' && *str <= '9'))
		str++;
	while (*str >= '0' && *str <= '9')
	{
		sum->y_token = sum->y_token * 10 + *str - '0';
		str++;
	}
	str++;
	while (*str >= '0' && *str <= '9')
	{
		sum->x_token = sum->x_token * 10 + *str - '0';
		str++;
	}
	free(str_free);
}
