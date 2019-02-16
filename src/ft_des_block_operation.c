/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_des_block_operation.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omakovsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 18:54:38 by omakovsk          #+#    #+#             */
/*   Updated: 2019/02/16 18:54:40 by omakovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_des.h"

unsigned char	*set_block(unsigned char *str,
					unsigned int i, unsigned int len)
{
	unsigned char	*block;
	unsigned int	back;

	block = (unsigned char *)ft_strnew(8);
	if (len - i >= 8)
	{
		data_copy(block, str, 8);
	}
	else
	{
		data_copy(block, str, len - i);
		back = 7;
		while (back >= (len - i))
			block[back--] = 8 - (len - i);
	}
	return (block);
}

void			data_copy(unsigned char *dst,
					unsigned char *src, unsigned int len)
{
	unsigned int	i;

	i = 0;
	while (i < len)
	{
		dst[i] = src[i];
		i++;
	}
}

void			data_xor(unsigned char *str,
						unsigned char *vector, unsigned int len)
{
	unsigned int	i;

	i = 0;
	while (i < len)
	{
		str[i] = str[i] ^ vector[i];
		i++;
	}
}
