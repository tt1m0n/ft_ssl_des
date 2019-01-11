/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_md5.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omakovsk <omakovsk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/25 15:59:00 by omakovsk          #+#    #+#             */
/*   Updated: 2018/09/02 09:42:02 by omakovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MD5_H
# define FT_MD5_H

# include "../global/ft_global.h"

# define F(x, y, z) ((z) ^ ((x) & ((y) ^ (z))))
# define G(x, y, z) ((y) ^ ((z) & ((x) ^ (y))))
# define H(x, y, z) (((x) ^ (y)) ^ (z))
# define H2(x, y, z) ((x) ^ ((y) ^ (z)))
# define I(x, y, z)	((y) ^ ((x) | ~(z)))

# define GET(n) (c->block[(n)])

typedef struct	s_md5_info
{
	t_uint	lo;
	t_uint	hi;
	t_uint	a;
	t_uint	b;
	t_uint	c;
	t_uint	d;
	t_uchar	buffer[64];
	t_uint	block[16];
}				t_md5_info;

/*
** main functions
*/
void			md5_init_start_words(t_md5_info *md5);
void			md5_update_words(t_md5_info *md5, const void *data,\
									t_ulong size);
void			md5_final(t_uchar *result, t_md5_info *md5);

/*
** rounds
*/
void			md5_round1(t_uint *t, t_md5_info *c, const t_uchar *p);
void			md5_round2(t_uint *t, t_md5_info *c);
void			md5_round3(t_uint *t, t_md5_info *c);
void			md5_round4(t_uint *t, t_md5_info *c);

/*
** init struct
*/
void			init_md5_struct(t_md5_info *md5);

/*
** instead defines
*/
t_uint			set(int n, t_md5_info *ctx, const t_uchar *ptr);
void			step(t_uint first, t_uint *tmp, t_uint *tmpb, int shift);
void			out(t_uchar *dst, t_uint src);

#endif
