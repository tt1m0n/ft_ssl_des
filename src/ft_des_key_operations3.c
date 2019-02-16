/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_des_key_operations3.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omakovsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 18:55:21 by omakovsk          #+#    #+#             */
/*   Updated: 2019/02/16 18:55:22 by omakovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_des.h"

void				whilesalt(t_iter *z, t_crypt_info *crypt_info, size_t ctr)
{
	if (z->i <= 15)
	{
		z->ff = (z->sec & z->third) | ((~z->sec) & z->fourth);
		z->g = z->i;
	}
	else if (z->i <= 31)
	{
		z->ff = (z->fourth & z->sec) | ((~z->fourth) & z->third);
		z->g = (5 * z->i + 1) % 16;
	}
	else if (z->i <= 47)
	{
		z->ff = z->sec ^ z->third ^ z->fourth;
		z->g = (3 * z->i + 5) % 16;
	}
	else if (z->i <= 63)
	{
		z->ff = z->third ^ (z->sec | (~z->fourth));
		z->g = (7 * z->i) % 16;
	}
	z->ff = z->ff + z->first + g_ks[z->i] + crypt_info->salt_help[z->g + ctr];
	z->first = z->fourth;
	z->fourth = z->third;
	z->third = z->sec;
	z->sec = z->sec + ((z->ff << g_s[z->i]) | (z->ff >> (32 - g_s[z->i])));
}

unsigned long long	*handle_pass(t_key_help key_help)
{
	unsigned long long	*ret;

	ret = ft_memalloc(sizeof(unsigned long long) * 2);
	ret[0] = key_help.second;
	ret[0] <<= 32;
	ret[0] += key_help.first;
	ret[1] = key_help.fourth;
	ret[1] <<= 32;
	ret[1] += key_help.third;
	return (ret);
}

void				revert_eight_bytes(char *data, size_t len)
{
	size_t	i;

	i = 0;
	if (len % 8 != 0)
	{
		ft_printf("Incorrect byte amount\n");
		exit(0);
	}
	while (i < len)
	{
		revert_bytes(&data[i]);
		i += 8;
	}
}

void				revert_bytes(char *data)
{
	char	tmp[8];

	tmp[0] = data[0];
	tmp[1] = data[1];
	tmp[2] = data[2];
	tmp[3] = data[3];
	tmp[4] = data[4];
	tmp[5] = data[5];
	tmp[6] = data[6];
	tmp[7] = data[7];
	data[7] = tmp[0];
	data[6] = tmp[1];
	data[5] = tmp[2];
	data[4] = tmp[3];
	data[3] = tmp[4];
	data[2] = tmp[5];
	data[1] = tmp[6];
	data[0] = tmp[7];
}
