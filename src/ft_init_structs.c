/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_structs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlogin <xlogin@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/02 13:52:00 by xlogin            #+#    #+#             */
/*   Updated: 2018/09/02 13:52:00 by xlogin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_md5.h"
#include "ft_sha.h"

void	init_sha_224_256_struct(t_sha_224_256 *sha)
{
	int i;

	i = START_VALUE;
	sha->bitlen = 0;
	sha->datalen = 0;
	while (i < MAX_SIZE_OF_WORD)
		sha->data[i++] = 0;
}

void	init_sha_384_512_struct(t_sha_384_512 *sha)
{
	int i;

	i = START_VALUE;
	sha->bitlen = 0;
	sha->datalen = 0;
	while (i < MAX_SIZE_OF_WORD_1)
		sha->data[i++] = 0;
}

void	init_md5_struct(t_md5_info *md5)
{
	int i;

	i = START_VALUE;
	md5->lo = 0;
	md5->hi = 0;
	md5->a = 0;
	md5->b = 0;
	md5->c = 0;
	md5->d = 0;
	while (i < 64)
		md5->buffer[i++] = 0;
	i = START_VALUE;
	while (i < 16)
		md5->block[i++] = 0;
}
