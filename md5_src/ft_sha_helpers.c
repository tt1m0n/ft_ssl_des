/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sha_helpers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlogin <xlogin@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/01 18:06:00 by xlogin            #+#    #+#             */
/*   Updated: 2018/09/01 18:06:00 by xlogin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sha.h"

void	append_length_to_padding(t_sha_224_256 *sha)
{
	sha->bitlen += sha->datalen * SS;
	sha->data[63] = (t_uchar)sha->bitlen;
	sha->data[62] = (t_uchar)(sha->bitlen >> SS * 1);
	sha->data[61] = (t_uchar)(sha->bitlen >> SS * 2);
	sha->data[60] = (t_uchar)(sha->bitlen >> SS * 3);
	sha->data[59] = (t_uchar)(sha->bitlen >> SS * 4);
	sha->data[58] = (t_uchar)(sha->bitlen >> SS * 5);
	sha->data[57] = (t_uchar)(sha->bitlen >> SS * 6);
	sha->data[56] = (t_uchar)(sha->bitlen >> SS * 7);
}

void	little_endian_to_big(t_sha_224_256 *sha,\
						t_uchar *hash, t_sha_type type)
{
	t_uint i;

	i = START_VALUE;
	while (i < 4)
	{
		hash[i] = (t_uchar)(sha->start_word[0] >> (MAX_SHIFT - i * SS));
		hash[i + INT_STEP * 1] = (t_uchar)(sha->start_word[1] >> \
										(MAX_SHIFT - i * SS));
		hash[i + INT_STEP * 2] = (t_uchar)(sha->start_word[2] >> \
										(MAX_SHIFT - i * SS));
		hash[i + INT_STEP * 3] = (t_uchar)(sha->start_word[3] >> \
										(MAX_SHIFT - i * SS));
		hash[i + INT_STEP * 4] = (t_uchar)(sha->start_word[4] >> \
										(MAX_SHIFT - i * SS));
		hash[i + INT_STEP * 5] = (t_uchar)(sha->start_word[5] >> \
										(MAX_SHIFT - i * SS));
		hash[i + INT_STEP * 6] = (t_uchar)(sha->start_word[6] >> \
										(MAX_SHIFT - i * SS));
		if (type == sha_256)
			hash[i + INT_STEP * 7] = (t_uchar)(sha->start_word[7] >> \
										(MAX_SHIFT - i * SS));
		i++;
	}
}

void	append_length_to_padding_1(t_sha_384_512 *sha)
{
	sha->bitlen += sha->datalen * SS;
	sha->data[127] = (t_uchar)sha->bitlen;
	sha->data[126] = (t_uchar)(sha->bitlen >> SS * 1);
	sha->data[125] = (t_uchar)(sha->bitlen >> SS * 2);
	sha->data[124] = (t_uchar)(sha->bitlen >> SS * 3);
	sha->data[123] = (t_uchar)(sha->bitlen >> SS * 4);
	sha->data[122] = (t_uchar)(sha->bitlen >> SS * 5);
	sha->data[121] = (t_uchar)(sha->bitlen >> SS * 6);
	sha->data[120] = (t_uchar)(sha->bitlen >> SS * 7);
	sha->data[119] = 0;
	sha->data[118] = 0;
	sha->data[117] = 0;
	sha->data[116] = 0;
	sha->data[115] = 0;
	sha->data[114] = 0;
	sha->data[113] = 0;
	sha->data[112] = 0;
}

void	little_endian_to_big_1(t_sha_384_512 *sha,\
							unsigned char *hash, t_sha_type type)
{
	t_uint i;

	i = START_VALUE;
	while (i < 8)
	{
		hash[i] = (t_uchar)(sha->start_word[0] >> (MAX_SHIFT_1 - i * SS));
		hash[i + LONG_STEP * 1] = (t_uchar)(sha->start_word[1] >> \
									(MAX_SHIFT_1 - i * SS));
		hash[i + LONG_STEP * 2] = (t_uchar)(sha->start_word[2] >> \
									(MAX_SHIFT_1 - i * SS));
		hash[i + LONG_STEP * 3] = (t_uchar)(sha->start_word[3] >> \
									(MAX_SHIFT_1 - i * SS));
		hash[i + LONG_STEP * 4] = (t_uchar)(sha->start_word[4] >> \
									(MAX_SHIFT_1 - i * SS));
		hash[i + LONG_STEP * 5] = (t_uchar)(sha->start_word[5] >> \
									(MAX_SHIFT_1 - i * SS));
		if (type == sha_512)
		{
			hash[i + LONG_STEP * 6] = (t_uchar)(sha->start_word[6] >> \
										(MAX_SHIFT_1 - i * SS));
			hash[i + LONG_STEP * 7] = (t_uchar)(sha->start_word[7] >> \
										(MAX_SHIFT_1 - i * SS));
		}
		i++;
	}
}
