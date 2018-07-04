/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkotenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 14:04:26 by dkotenko          #+#    #+#             */
/*   Updated: 2018/01/03 15:42:44 by dkotenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FILLER_H
# define __FILLER_H
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include "./libft/includes/libft.h"
# define BUFF_SIZE 1

typedef struct	s_field
{
	long int	x;
	long int	y;
	char		point;
}				t_field;

typedef struct	s_sum
{
	long int		x_fielt;
	long int		y_fielt;
	long int		x_token;
	long int		y_token;
	char			me;
	char			he;
}				t_sum;

typedef struct	s_dpoint
{
	long int		x;
	long int		y;
	long int		d;
	long int		xh;
	long int		yh;
}				t_dpoint;

int				get_next_line(const int fd, char **line);
t_field			*field(t_sum *sum);
t_field			*token(t_sum *sum);
void			atoi_map_fielt(t_sum *sum);
void			atoi_map_token(t_sum *sum);
int				base_flr(char me, char he);
long int		vector_distance(long int x1, long int y1,\
	long int x2, long int y2);
t_dpoint		distance(t_field *flr_field, t_sum *sum);
t_dpoint		distance_token(t_field *flr_token,\
	t_sum *sum, t_dpoint distance_field);
t_field			*rewrite_field(t_field *flr_field,\
	t_field *re_field, t_sum *sum);
t_field			*rewrite_token(t_field *flr_field,\
	t_field *re_field, t_sum *sum);
t_field			*token_plus(t_field *flr_token,\
	t_dpoint dpoint_token, t_sum *sum);
int				read_plus_token(t_field *flr_token, t_sum *sum);
int				read_plus_field(t_field *flr_field,\
	t_sum *sum);
t_field			*rewrite_field_dot(t_field *flr_field,\
	t_field *re_field, t_sum *sum);
t_field			*rewrite_token_dot(t_field *flr_token,\
	t_field *re_token, t_sum *sum);
t_field			*token_dd(t_field *flr_token, long int i,\
	t_dpoint dpoint, t_sum *sum);
int				trckng(t_field *flr_field, t_field *flr_token, t_sum *sum);
t_field			*token_field(t_field *flr_token,\
	t_dpoint dpoint_token, t_dpoint dpoint, t_sum *sum);
int				free_flr(t_field **one, t_field **two,\
	t_field **three, t_field **four);
void			mllc_token(t_field **new, t_field **two,\
	t_field *re, t_sum *sum);
void			mllc_field(t_field **new, t_field **two,\
	t_field *re, t_sum *sum);
int				bust_run(t_dpoint dpoint, t_field **flr_token,\
	t_field *flr_field, t_sum *sum);

#endif
