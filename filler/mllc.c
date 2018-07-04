/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mllc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkotenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 12:06:54 by dkotenko          #+#    #+#             */
/*   Updated: 2018/02/20 12:06:55 by dkotenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	mllc_field(t_field **new, t_field **two, t_field *re, t_sum *sum)
{
	(*new) = (t_field*)malloc(sizeof(t_field) * sum->x_fielt * sum->y_fielt);
	(*new) = rewrite_field(re, (*new), sum);
	(*two) = (t_field*)malloc(sizeof(t_field) * sum->x_fielt * sum->y_fielt);
	(*two) = rewrite_field(re, (*two), sum);
}

void	mllc_token(t_field **new, t_field **two, t_field *re, t_sum *sum)
{
	(*new) = (t_field*)malloc(sizeof(t_field) * sum->x_token * sum->y_token);
	(*new) = rewrite_token(re, (*new), sum);
	(*two) = (t_field*)malloc(sizeof(t_field) * sum->x_token * sum->y_token);
	(*two) = rewrite_token(re, (*two), sum);
}
