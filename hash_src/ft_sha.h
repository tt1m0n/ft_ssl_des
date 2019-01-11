/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sha.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omakovsk <omakovsk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/25 15:59:00 by omakovsk          #+#    #+#             */
/*   Updated: 2018/08/25 15:59:00 by omakovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SHA_H
# define FT_SHA_H

# include "../libft/libft.h"
# include "../global/ft_global.h"

# define RR_32(x, n) (((x) >> (n)) | ((x) << (32 - (n))))
# define RR_64(x, n) (((x) >> (n)) | ((x) << (64 - (n))))
# define SHIFT_R(x, n) ((x) >> (n))

# define CH(x, y, z) (((x) & (y)) ^ (~(x) & (z)))
# define MAJ(x, y, z) (((x) & (y)) ^ ((x) & (z)) ^ ((y) & (z)))

# define ZERO_BIT				0x00
# define START_PADDING			0x80
# define NUM_OF_START_WORDS		8
# define MAX_SIZE_OF_WORD		64
# define MAX_SIZE_OF_WORD_1		128
# define SS						8
# define MAX_SHIFT				24
# define MAX_SHIFT_1			56
# define INT_STEP				4
# define LONG_STEP				8
# define MESSAGE_BYTE_SIZE		56
# define MESSAGE_BYTE_SIZE_1	112

typedef struct	s_sha_224_256
{
	t_uchar	data[MAX_SIZE_OF_WORD];
	t_uint	datalen;
	t_ulong	bitlen;
	t_uint	start_word[NUM_OF_START_WORDS];
}				t_sha_224_256;

typedef struct	s_sha_384_512
{
	t_uchar	data[MAX_SIZE_OF_WORD_1];
	t_uint	datalen;
	t_ulong	bitlen;
	t_ulong	start_word[NUM_OF_START_WORDS];
}				t_sha_384_512;

/*
** init start words
*/
void			sha256_init_start_words(t_uint *info);
void			sha224_init_start_words(t_uint *info);
void			sha384_init_start_words(t_ulong *info);
void			sha512_init_start_words(t_ulong *info);

/*
** update words
*/
void			sha_update_words(t_sha_224_256 *sha_info,\
								const unsigned char *data, size_t len);
void			sha_update_words_1(t_sha_384_512 *sha_info,\
								const unsigned char *data, size_t len);
void			sha_transform_words(t_sha_224_256 *sha);
void			sha_transform_words_1(t_sha_384_512 *sha);
void			sha_data_transformation(t_sha_224_256 *sha,\
									t_uint (*new_data)[MAX_SIZE_OF_WORD]);
void			sha_data_transformation_1(t_sha_384_512 *sha,\
											t_ulong (*n_d)[80]);
void			sha_compression_cycle(t_uint (*tmp)[NUM_OF_START_WORDS], \
										t_uint (*new_data)[MAX_SIZE_OF_WORD]);
void			sha_compression_cycle_1(t_ulong (*tmp)[NUM_OF_START_WORDS],
										t_ulong (*new_data)[80]);

/*
** init struct
*/
void			init_sha_224_256_struct(t_sha_224_256 *sha);
void			init_sha_384_512_struct(t_sha_384_512 *sha);

/*
** final
*/
void			sha_final(t_sha_224_256 *sha, unsigned char *hash,\
							t_sha_type type);
void			sha_final_1(t_sha_384_512 *sha, unsigned char *hash,\
							t_sha_type type);

void			append_length_to_padding(t_sha_224_256 *sha);
void			append_length_to_padding_1(t_sha_384_512 *sha);

void			little_endian_to_big(t_sha_224_256 *sha, unsigned char *hash,\
									t_sha_type type);
void			little_endian_to_big_1(t_sha_384_512 *sha, unsigned char *hash,\
									t_sha_type type);

#endif
