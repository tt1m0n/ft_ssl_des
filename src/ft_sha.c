/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sha.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omakovsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/02 12:28:11 by omakovsk          #+#    #+#             */
/*   Updated: 2018/09/02 12:28:13 by omakovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sha.h"

void	sha_update_words(t_sha_224_256 *sha_info,\
			const t_uchar *data, size_t len)
{
	t_uint i;

	i = START_VALUE;
	while ((size_t)i < len)
	{
		sha_info->data[sha_info->datalen] = data[i];
		sha_info->datalen++;
		if (sha_info->datalen == MAX_SIZE_OF_WORD)
		{
			sha_transform_words(sha_info);
			sha_info->bitlen += MAX_SIZE_OF_WORD * SS;
			sha_info->datalen = START_VALUE;
		}
		i++;
	}
}

void	sha_transform_words(t_sha_224_256 *sha)
{
	t_uint i;
	t_uint tmp[NUM_OF_START_WORDS];
	t_uint new_data[MAX_SIZE_OF_WORD];

	i = START_VALUE;
	sha_data_transformation(sha, &new_data);
	while (i < NUM_OF_START_WORDS)
	{
		tmp[i] = sha->start_word[i];
		i++;
	}
	sha_compression_cycle(&tmp, &new_data);
	i = START_VALUE;
	while (i < NUM_OF_START_WORDS)
	{
		sha->start_word[i] += tmp[i];
		i++;
	}
}

void	sha_data_transformation(t_sha_224_256 *sha,\
					t_uint (*new_data)[MAX_SIZE_OF_WORD])
{
	t_uchar *data;
	t_uint	i;
	t_uint	j;

	data = sha->data;
	i = START_VALUE;
	j = START_VALUE;
	while (i < 16)
	{
		(*new_data)[i] = (data[j] << SS * 3) | \
		(data[j + 1] << SS * 2) | (data[j + 2] << SS) | \
		(data[j + 3]);
		i++;
		j += 4;
	}
	while (i < MAX_SIZE_OF_WORD)
	{
		(*new_data)[i] = (RR_32((*new_data)[i - 2], 17) ^ \
		RR_32((*new_data)[i - 2], 19) ^ SHIFT_R((*new_data)[i - 2], 10)) + \
		(*new_data)[i - 7] + (RR_32((*new_data)[i - 15], 7) ^ \
		RR_32((*new_data)[i - 15], 18) ^ SHIFT_R((*new_data)[i - 15], 3)) + \
		(*new_data)[i - 16];
		i++;
	}
}

void	sha_compression_cycle(t_uint (*tmp)[NUM_OF_START_WORDS],\
							t_uint (*new_data)[MAX_SIZE_OF_WORD])
{
	t_uint i;
	t_uint helpers1;
	t_uint helpers2;

	i = START_VALUE;
	while (i < MAX_SIZE_OF_WORD)
	{
		helpers1 = (*tmp)[7] + (RR_32((*tmp)[4], 6) ^ RR_32((*tmp)[4], 11) ^ \
			RR_32((*tmp)[4], 25)) + CH((*tmp)[4], (*tmp)[5], (*tmp)[6]) + \
			g_sha_word[i] + (*new_data)[i];
		helpers2 = (RR_32((*tmp)[0], 2) ^ RR_32((*tmp)[0], 13) ^ \
			RR_32((*tmp)[0], 22)) + MAJ((*tmp)[0], (*tmp)[1], (*tmp)[2]);
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

void	sha_final(t_sha_224_256 *sha, t_uchar *hash, t_sha_type type)
{
	t_uint i;

	i = sha->datalen;
	if (sha->datalen < MESSAGE_BYTE_SIZE)
	{
		sha->data[i++] = START_PADDING;
		while (i < MESSAGE_BYTE_SIZE)
			sha->data[i++] = ZERO_BIT;
	}
	else
	{
		sha->data[i++] = START_PADDING;
		while (i < MAX_SIZE_OF_WORD)
			sha->data[i++] = ZERO_BIT;
		sha_transform_words(sha);
		ft_memset(sha->data, ZERO_BIT, MESSAGE_BYTE_SIZE);
	}
	append_length_to_padding(sha);
	sha_transform_words(sha);
	little_endian_to_big(sha, hash, type);
}
