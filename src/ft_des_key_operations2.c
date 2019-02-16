/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_des_key_operations2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omakovsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 18:55:15 by omakovsk          #+#    #+#             */
/*   Updated: 2019/02/16 18:55:16 by omakovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_des.h"

void				add_byte(t_crypt_info *crypt_info)
{
	char	*snew;
	char	*tmp;

	tmp = crypt_info->flags.password;
	crypt_info->flags.pass_len++;
	snew = ft_memalloc(crypt_info->flags.pass_len);
	crypt_info->flags.password = (char *)ft_memcpy(snew,
			crypt_info->flags.password, crypt_info->flags.pass_len - 1);
	free(tmp);
}

void				block_end(t_crypt_info *crypt_info)
{
	char				*tmp;
	char				*ctmp;
	unsigned long long	*max;

	max = ft_memalloc(8);
	*max = 8 * crypt_info->flags.temp_len;
	crypt_info->flags.pass_len += 8;
	tmp = crypt_info->flags.password;
	ctmp = ft_memalloc(crypt_info->flags.pass_len);
	crypt_info->flags.password = ft_memcpy(ctmp, crypt_info->flags.password,
			crypt_info->flags.pass_len - 8);
	ft_memcpy(&crypt_info->flags.password[crypt_info->flags.pass_len - 8],
			(void*)max, 8);
	free(tmp);
	free(max);
}

unsigned long long	*hash_pass(t_crypt_info *crypt_info)
{
	t_key_help		key_help;
	t_iter			iter;
	unsigned int	ctr;
	size_t			d;

	init_key_help(&key_help);
	init_iter(&iter, &key_help);
	ctr = 0;
	d = 0;
	while (d < crypt_info->flags.pass_len)
	{
		init_iter(&iter, &key_help);
		while (++iter.i < 64)
			whilesalt(&iter, crypt_info, ctr);
		ctr += 16;
		key_help.first += iter.first;
		key_help.second += iter.sec;
		key_help.third += iter.third;
		key_help.fourth += iter.fourth;
		d += 64;
	}
	return (handle_pass(key_help));
}

void				init_key_help(t_key_help *key_help)
{
	key_help->first = 0x67452301;
	key_help->second = 0xefcdab89;
	key_help->third = 0x98badcfe;
	key_help->fourth = 0x10325476;
}

void				init_iter(t_iter *iter, t_key_help *key_help)
{
	iter->first = key_help->first;
	iter->sec = key_help->second;
	iter->third = key_help->third;
	iter->fourth = key_help->fourth;
	iter->i = -1;
}
