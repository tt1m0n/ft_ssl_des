/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cbc_pre_post_block.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omakovsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 18:53:23 by omakovsk          #+#    #+#             */
/*   Updated: 2019/02/16 18:53:26 by omakovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_des.h"

void			cbc_pre_block(t_crypt_info *crypt_info, unsigned char *block)
{
	if (!crypt_info->flags.d)
	{
		data_xor(block, crypt_info->flags.in_vector, 8);
	}
}

void			cbc_post_block(t_crypt_info *crypt_info, unsigned char *block,
								unsigned int i, unsigned char *text)
{
	if (crypt_info->flags.d)
	{
		data_xor(block, crypt_info->flags.in_vector, 8);
		free(crypt_info->flags.in_vector);
		crypt_info->flags.in_vector = create_same(&(text[i - 8]), 8);
	}
	else
		crypt_info->flags.in_vector = create_same(block, 8);
}
