/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_des3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omakovsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 18:54:17 by omakovsk          #+#    #+#             */
/*   Updated: 2019/02/16 18:54:18 by omakovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_des.h"
#include "ft_base64.h"
#include "ft_crypt_operations.h"

void			des3_crypt(t_crypt_info *crypt_info)
{
	unsigned char	*temp;
	unsigned char	*crypt;

	if (!crypt_info->flags.v && (crypt_info->cryptptr != des3_ecb))
		return ((void)ft_printf("iv undefined\n"));
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
		des_action(crypt_info, crypt, 1);
	else
		ft_printf("Message not multiple of block length\n");
}

void			des3_message(t_crypt_info *crypt_info, unsigned char **text)
{
	unsigned char	*done;
	unsigned char	*block;
	unsigned char	**keys;
	unsigned int	i;

	done = (unsigned char *)ft_strnew(0);
	i = 0;
	while (i < crypt_info->data_len)
	{
		keys = init_des3_keys(crypt_info->flags.key);
		block = set_block(&(*text)[i], i, crypt_info->data_len);
		i += 8;
		if (crypt_info->cryptptr != des3_ecb)
			cbc_pre_block(crypt_info, block);
		block = des3_common_block(block, keys, crypt_info->flags.d);
		if (crypt_info->cryptptr != des3_ecb)
			cbc_post_block(crypt_info, block, i, *text);
		done = append(done, block, i - 8, 8);
		destroy_des3_keys(keys);
	}
	des_pad(crypt_info, i, done, text);
}

void			destroy_des3_keys(unsigned char **keys)
{
	int		i;

	if (keys)
	{
		i = -1;
		while (++i < 3)
			if (keys[i])
				free(keys[i]);
		free(keys);
	}
}

unsigned char	*des3_common_block(unsigned char *block,
								unsigned char **keys, int d)
{
	if (!d)
	{
		block = des_common_block(block, keys[0], d);
		block = des_common_block(block, keys[1], !d);
		block = des_common_block(block, keys[2], d);
	}
	else
	{
		block = des_common_block(block, keys[2], d);
		block = des_common_block(block, keys[1], !d);
		block = des_common_block(block, keys[0], d);
	}
	return (block);
}
