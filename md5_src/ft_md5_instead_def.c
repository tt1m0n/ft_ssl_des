/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_md5_instead_def.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlogin <xlogin@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/02 11:52:00 by xlogin            #+#    #+#             */
/*   Updated: 2018/09/02 11:52:00 by xlogin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_md5.h"

void	out(t_uchar *dst, t_uint src)
{
	(dst)[0] = (t_uchar)(src);
	(dst)[1] = (t_uchar)((src) >> 8);
	(dst)[2] = (t_uchar)((src) >> 16);
	(dst)[3] = (t_uchar)((src) >> 24);
}

t_uint	set(int n, t_md5_info *ctx, const t_uchar *ptr)
{
	(ctx->block[(n)] = (t_uint)ptr[(n) * 4] | \
	((t_uint)ptr[(n) * 4 + 1] << 8) | \
	((t_uint)ptr[(n) * 4 + 2] << 16) | \
	((t_uint)ptr[(n) * 4 + 3] << 24));
	return (ctx->block[n]);
}

void	step(t_uint first, t_uint *tmp, t_uint *tmpb, int shift)
{
	*tmp += first;
	*tmp = (*tmp << shift) | ((*tmp & 0xffffffff) >> (32 - shift));
	*tmp += *tmpb;
}
