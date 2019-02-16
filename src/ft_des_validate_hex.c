/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_des_validate_hex.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omakovsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 18:56:19 by omakovsk          #+#    #+#             */
/*   Updated: 2019/02/16 18:56:21 by omakovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_des.h"

unsigned char		*get_hex_string(char *argv)
{
	unsigned char *res;
	unsigned char *hexres;

	res = (unsigned char *)ft_strnew(24 * 2);
	if (ft_strlen(argv) <= (24 * 2))
		ft_memcpy((void*)res, argv, ft_strlen(argv));
	else
		ft_memcpy((void*)res, argv, 24 * 2);
	if (!is_hex_string(res))
	{
		free(res);
		return (NULL);
	}
	hexres = des_rewrite(res);
	free(res);
	return (hexres);
}

unsigned char		*des_rewrite(unsigned char *key)
{
	int				i;
	int				k;
	unsigned char	*rewrite;

	rewrite = (unsigned char *)ft_strnew(DES_KEY_LEN);
	if (rewrite)
	{
		i = -1;
		k = 0;
		while (++i < DES_KEY_LEN)
		{
			rewrite[i] = get_hex_val(key[k], key[k + 1]);
			k += 2;
		}
	}
	return (rewrite);
}

int					is_hex_string(unsigned char *str)
{
	while (*str)
	{
		if (!is_hex_char(*str))
			return (0);
		str++;
	}
	return (1);
}

int					is_hex_char(char c)
{
	if (ft_isdigit(c))
		return (1);
	if ((c >= 'a') && (c <= 'f'))
		return (1);
	if ((c >= 'A') && (c <= 'F'))
		return (1);
	return (0);
}

unsigned char		get_hex_val(unsigned char first, unsigned char second)
{
	unsigned char	ret;

	ret = 0;
	if (second)
	{
		if (ft_isdigit(second))
			ret += (second - '0');
		else
			ret += (10 + (ft_toupper(second) - 'A'));
	}
	if (first)
	{
		if (ft_isdigit(first))
			ret += (first - '0') << 4;
		else
			ret += (10 + (ft_toupper(first) - 'A')) << 4;
	}
	return (ret);
}
