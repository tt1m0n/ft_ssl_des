/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sha_384_512.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlogin <xlogin@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/01 11:34:00 by xlogin            #+#    #+#             */
/*   Updated: 2018/09/01 11:34:00 by xlogin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sha.h"

void	sha_update_words_1(t_sha_384_512 *sha_info,\
					const unsigned char *data, size_t len)
{
	t_uint i;

	i = START_VALUE;
	while ((size_t)i < len)
	{
		sha_info->data[sha_info->datalen] = data[i];
		sha_info->datalen++;
		if (sha_info->datalen == MAX_SIZE_OF_WORD_1)
		{
			sha_transform_words_1(sha_info);
			sha_info->bitlen += MAX_SIZE_OF_WORD_1 * SS;
			sha_info->datalen = START_VALUE;
		}
		i++;
	}
}

void	sha_transform_words_1(t_sha_384_512 *sha)
{
	t_uint	i;
	t_ulong	tmp[NUM_OF_START_WORDS];
	t_ulong	new_data[80];

	sha_data_transformation_1(sha, &new_data);
	i = START_VALUE;
	while (i < NUM_OF_START_WORDS)
	{
		tmp[i] = sha->start_word[i];
		i++;
	}
	sha_compression_cycle_1(&tmp, &new_data);
	i = START_VALUE;
	while (i < NUM_OF_START_WORDS)
	{
		sha->start_word[i] += tmp[i];
		i++;
	}
}

void	sha_data_transformation_1(t_sha_384_512 *sha, t_ulong (*n_d)[80])
{
	t_uchar	*data;
	t_uint	i;
	t_uint	j;

	data = sha->data;
	i = START_VALUE;
	j = START_VALUE;
	while (i < 16)
	{
		(*n_d)[i++] = ((t_ulong)data[j] << SS * 7) | \
		((t_ulong)data[j + 1] << SS * 6) | ((t_ulong)data[j + 2] << SS * 5) | \
		((t_ulong)data[j + 3] << SS * 4) | ((t_ulong)data[j + 4] << SS * 3) | \
		((t_ulong)data[j + 5] << SS * 2) | ((t_ulong)data[j + 6] << SS * 1) | \
		((t_ulong)data[j + 7]);
		j += 8;
	}
	while (i < 80)
	{
		(*n_d)[i] = (RR_64((*n_d)[i - 2], 19) ^ \
		RR_64((*n_d)[i - 2], 61) ^ SHIFT_R((*n_d)[i - 2], 6)) + \
		(*n_d)[i - 7] + (RR_64((*n_d)[i - 15], 1) ^ \
		RR_64((*n_d)[i - 15], 8) ^ SHIFT_R((*n_d)[i - 15], 7)) + \
		(*n_d)[i - 16];
		i++;
	}
}

void	sha_compression_cycle_1(t_ulong (*tmp)[NUM_OF_START_WORDS],\
								t_ulong (*new_data)[80])
{
	t_uint	i;
	t_ulong helpers1;
	t_ulong helpers2;

	i = START_VALUE;
	while (i < 80)
	{
		helpers1 = (*tmp)[7] + (RR_64((*tmp)[4], 14) ^ RR_64((*tmp)[4], 18) ^ \
			RR_64((*tmp)[4], 41)) + CH((*tmp)[4], (*tmp)[5], (*tmp)[6]) + \
			g_sha1_word[i] + (*new_data)[i];
		helpers2 = (RR_64((*tmp)[0], 28) ^ RR_64((*tmp)[0], 34) ^ \
			RR_64((*tmp)[0], 39)) + MAJ((*tmp)[0], (*tmp)[1], (*tmp)[2]);
		(*tmp)[7] = (*tmp)[6];
		(*tmp)[6] = (*tmp)[5];
		(*tmp)[5] = (*tmp)[4];
		(*tmp)[4] = (*tmp)[3] + helpers1;
		(*tmp)[3] = (*tmp)[2];
		(*tmp)[2] = (*tmp)[1];
		(*tmp)[1] = (*tmp)[0];
		(*tmp)[0] = helpers1 + helpers2;
		i++;
	}
}

void	sha_final_1(t_sha_384_512 *sha, unsigned char *hash, t_sha_type type)
{
	t_ulong i;

	i = sha->datalen;
	if (sha->datalen < MESSAGE_BYTE_SIZE_1)
	{
		sha->data[i++] = START_PADDING;
		while (i < MESSAGE_BYTE_SIZE_1)
			sha->data[i++] = ZERO_BIT;
	}
	else
	{
		sha->data[i++] = START_PADDING;
		while (i < MAX_SIZE_OF_WORD_1)
			sha->data[i++] = ZERO_BIT;
		sha_transform_words_1(sha);
		ft_memset(sha->data, ZERO_BIT, MESSAGE_BYTE_SIZE_1);
	}
	append_length_to_padding_1(sha);
	sha_transform_words_1(sha);
	little_endian_to_big_1(sha, hash, type);
}
