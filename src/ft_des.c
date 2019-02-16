/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_des.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omakovsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 18:54:00 by omakovsk          #+#    #+#             */
/*   Updated: 2019/02/16 18:54:02 by omakovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_des.h"
#include "ft_base64.h"
#include "ft_crypt_operations.h"

void	des_crypt(t_crypt_info *crypt_info)
{
	unsigned char	*temp;
	unsigned char	*crypt;

	if (!crypt_info->flags.v && crypt_info->cryptptr != des_ecb)
		return ((void)ft_printf("iv undefined\n"));
	get_crypt_key(crypt_info);
	if (crypt_info->flags.show)
		ft_print_show(crypt_info);
	if (!crypt_info->flags.key)
		return ;
	crypt = read_crypt_text(crypt_info);
	if (crypt && crypt_info->flags.d && crypt_info->flags.a)
	{
		temp = base64_decrypt_alghoritm(crypt, crypt_info->data_len);
		free(crypt);
		crypt = temp;
	}
	if (!crypt)
		return ;
	des_align_input(&crypt, crypt_info);
	if (!crypt_info->flags.d || ((crypt_info->data_len % 8) == 0))
		des_action(crypt_info, crypt, 0);
	else
		ft_printf("Message not multiple of block length\n");
}

void	des_action(t_crypt_info *crypt_info,
				unsigned char *crypt_text, uint8_t is_des3)
{
	unsigned char	*temp;

	if (is_des3)
		des3_message(crypt_info, &crypt_text);
	else
		des_message(crypt_info, &crypt_text);
	if (crypt_info->flags.a && !crypt_info->flags.d)
	{
		temp = base64_encrypt_alghoritm(crypt_text, crypt_info->data_len);
		free(crypt_text);
		crypt_text = temp;
		crypt_info->data_len = ft_strlen((char*)crypt_text);
	}
	des_cbc_result_output(crypt_info, crypt_text);
	if (crypt_text)
		free(crypt_text);
}

void	des_message(t_crypt_info *crypt_info, unsigned char **text)
{
	unsigned char	*done;
	unsigned char	*block;
	unsigned char	*subkey;
	unsigned int	i;

	done = (unsigned char *)ft_strnew(0);
	i = 0;
	while (i < crypt_info->data_len)
	{
		subkey = des_key_reduction(crypt_info->flags.key, -1);
		block = set_block(&(*text)[i], i, crypt_info->data_len);
		i += 8;
		if (crypt_info->cryptptr != des_ecb)
			cbc_pre_block(crypt_info, block);
		block = des_common_block(block, subkey, crypt_info->flags.d);
		if (crypt_info->cryptptr != des_ecb)
			cbc_post_block(crypt_info, block, i, *text);
		done = append(done, block, i - 8, 8);
		free(subkey);
	}
	des_pad(crypt_info, i, done, text);
}
