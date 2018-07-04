/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_flr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkotenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 19:35:46 by dkotenko          #+#    #+#             */
/*   Updated: 2018/02/19 19:35:48 by dkotenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		free_flr(t_field **one, t_field **two, t_field **three, t_field **four)
{
	free((*one));
	free((*two));
	free((*three));
	free((*four));
	return (0);
}
