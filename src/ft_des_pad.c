/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_des_pad.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omakovsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 18:55:46 by omakovsk          #+#    #+#             */
/*   Updated: 2019/02/16 18:55:47 by omakovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_des.h"

void		handle_decode(t_crypt_info *crypt_info,
					unsigned int len, unsigned char *text)
{
	unsigned int	last_i;
	unsigned char	last;

	crypt_info->data_len = len;
	last_i = len - 1;
	last = text[last_i];
	if (last <= 8)
	{
		while ((text[last_i] == last) && (len - last_i) <= last)
		{
			last_i--;
			crypt_info->data_len--;
		}
		if (len - last_i != last + 1)
			crypt_info->data_len = len;
	}
}

void		des_pad(t_crypt_info *crypt_info, unsigned int i,
						unsigned char *str, unsigned char **text)
{
	free(*text);
	*text = str;
	if (i <= 0)
		return ;
	if (crypt_info->flags.d)
		handle_decode(crypt_info, i, *text);
}
