/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main_hash_function.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlogin <xlogin@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/01 17:52:00 by xlogin            #+#    #+#             */
/*   Updated: 2019/02/16 18:57:48 by omakovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../global/ft_global.h"
#include "ft_md5.h"
#include "ft_sha.h"
#include "ft_parse_and_read.h"

void	sha224(char *need_hash, int *flags, char *filename)
{
	t_uchar			buf[SHA224_OUTPUT_SIZE];
	t_sha_224_256	sha;
	t_uint			i;

	init_sha_224_256_struct(&sha);
	i = START_VALUE;
	sha224_init_start_words(sha.start_word);
	sha_update_words(&sha, (t_uchar *)need_hash, ft_strlen(need_hash));
	sha_final(&sha, buf, sha_224);
	if (*flags == 0 && filename[0] != 0)
		ft_printf("SHA224 (%s) = ", filename);
	if (*flags == S)
		ft_printf("SHA224 (\"%s\") = ", need_hash);
	while (i < SHA224_OUTPUT_SIZE)
		ft_printf("%02x", buf[i++]);
	common_hash_parse(flags, need_hash, filename);
}

void	sha256(char *need_hash, int *flags, char *filename)
{
	t_uchar			buf[SHA256_OUTPUT_SIZE];
	t_sha_224_256	sha;
	t_uint			i;

	init_sha_224_256_struct(&sha);
	i = START_VALUE;
	sha256_init_start_words(sha.start_word);
	sha_update_words(&sha, (t_uchar *)need_hash, ft_strlen(need_hash));
	sha_final(&sha, buf, sha_256);
	if (*flags == 0 && filename[0] != 0)
		ft_printf("SHA256 (%s) = ", filename);
	if (*flags == S)
		ft_printf("SHA256 (\"%s\") = ", need_hash);
	while (i < SHA256_OUTPUT_SIZE)
		ft_printf("%02x", buf[i++]);
	common_hash_parse(flags, need_hash, filename);
}

void	sha384(char *need_hash, int *flags, char *filename)
{
	t_uchar			buf[SHA384_OUTPUT_SIZE];
	t_sha_384_512	sha;
	t_uint			i;

	init_sha_384_512_struct(&sha);
	i = START_VALUE;
	sha384_init_start_words(sha.start_word);
	sha_update_words_1(&sha, (t_uchar *)need_hash, ft_strlen(need_hash));
	sha_final_1(&sha, buf, sha_384);
	if (*flags == 0 && filename[0] != 0)
		ft_printf("SHA384 (%s) = ", filename);
	if (*flags == S)
		ft_printf("SHA384 (\"%s\") = ", need_hash);
	while (i < SHA384_OUTPUT_SIZE)
		ft_printf("%02x", buf[i++]);
	common_hash_parse(flags, need_hash, filename);
}

void	sha512(char *need_hash, int *flags, char *filename)
{
	t_uchar			buf[SHA512_OUTPUT_SIZE];
	t_sha_384_512	sha;
	t_uint			i;

	init_sha_384_512_struct(&sha);
	i = START_VALUE;
	sha512_init_start_words(sha.start_word);
	sha_update_words_1(&sha, (t_uchar *)need_hash, ft_strlen(need_hash));
	sha_final_1(&sha, buf, sha_512);
	if (*flags == 0 && filename[0] != 0)
		ft_printf("SHA512 (%s) = ", filename);
	if (*flags == S)
		ft_printf("SHA512 (\"%s\") = ", need_hash);
	while (i < SHA512_OUTPUT_SIZE)
		ft_printf("%02x", buf[i++]);
	common_hash_parse(flags, need_hash, filename);
}

void	md5(char *need_hash, int *flags, char *filename)
{
	t_uchar		buf[MD5_OUTPUT_SIZE];
	t_md5_info	md5;
	t_uint		i;

	init_md5_struct(&md5);
	i = START_VALUE;
	md5_init_start_words(&md5);
	md5_update_words(&md5, (void *)need_hash, ft_strlen(need_hash));
	md5_final(buf, &md5);
	if (*flags == 0 && filename[0] != 0)
		ft_printf("MD5 (%s) = ", filename);
	if (*flags == S)
		ft_printf("MD5 (\"%s\") = ", need_hash);
	while (i < MD5_OUTPUT_SIZE)
		ft_printf("%02x", buf[i++]);
	common_hash_parse(flags, need_hash, filename);
}
