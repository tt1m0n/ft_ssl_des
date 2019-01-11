/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_md5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omakovsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/02 09:41:48 by omakovsk          #+#    #+#             */
/*   Updated: 2018/09/02 09:41:56 by omakovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "ft_md5.h"


void				md5_body_cycle(t_uint *tmp, t_md5_info *ctx,\
									const t_uchar *ptr)
{
	t_uint	saved_tmp[4];

	saved_tmp[0] = tmp[0];
	saved_tmp[1] = tmp[1];
	saved_tmp[2] = tmp[2];
	saved_tmp[3] = tmp[3];
	md5_round1(tmp, ctx, ptr);
	md5_round2(tmp, ctx);
	md5_round3(tmp, ctx);
	md5_round4(tmp, ctx);
	tmp[0] += saved_tmp[0];
	tmp[1] += saved_tmp[1];
	tmp[2] += saved_tmp[2];
	tmp[3] += saved_tmp[3];
}

static const void	*body(t_md5_info *ctx, const void *data, unsigned long size)
{
	const t_uchar	*ptr;
	t_uint			tmp[4];

	ptr = (const t_uchar*)data;
	tmp[0] = ctx->a;
	tmp[1] = ctx->b;
	tmp[2] = ctx->c;
	tmp[3] = ctx->d;
	while (size)
	{
		md5_body_cycle(tmp, ctx, ptr);
		ptr += 64;
		size -= 64;
	}
	ctx->a = tmp[0];
	ctx->b = tmp[1];
	ctx->c = tmp[2];
	ctx->d = tmp[3];
	return (ptr);
}

void				init_var(t_uint *saved_lo, t_ulong *used,\
							t_md5_info *md5, t_ulong size)
{
	*saved_lo = md5->lo;
	if ((md5->lo = (*saved_lo + size) & 0x1fffffff) < *saved_lo)
		md5->hi++;
	md5->hi += size >> 29;
	*used = *saved_lo & 0x3f;
}

void				md5_update_words(t_md5_info *md5, const void *data,\
										unsigned long size)
{
	t_uint	saved_lo;
	t_ulong	used;
	t_ulong	available;

	init_var(&saved_lo, &used, md5, size);
	if (used)
	{
		available = 64 - used;
		if (size < available)
		{
			ft_memcpy(&md5->buffer[used], data, size);
			return ;
		}
		ft_memcpy(&md5->buffer[used], data, available);
		data = (const t_uchar*)data + available;
		size -= available;
		body(md5, md5->buffer, 64);
	}
	if (size >= 64)
	{
		data = body(md5, data, size & ~(t_ulong)0x3f);
		size &= 0x3f;
	}
	ft_memcpy(md5->buffer, data, size);
}

void				md5_final(unsigned char *result, t_md5_info *ctx)
{
	t_ulong used;
	t_ulong available;

	used = ctx->lo & 0x3f;
	ctx->buffer[used++] = 0x80;
	available = 64 - used;
	if (available < 8)
	{
		ft_memset(&ctx->buffer[used], 0, available);
		body(ctx, ctx->buffer, 64);
		used = 0;
		available = 64;
	}
	ft_memset(&ctx->buffer[used], 0, available - 8);
	ctx->lo <<= 3;
	out(&ctx->buffer[56], ctx->lo);
	out(&ctx->buffer[60], ctx->hi);
	body(ctx, ctx->buffer, 64);
	out(&result[0], ctx->a);
	out(&result[4], ctx->b);
	out(&result[8], ctx->c);
	out(&result[12], ctx->d);
	ft_memset(ctx, 0, sizeof(*ctx));
}
