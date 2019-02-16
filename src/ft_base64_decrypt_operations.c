/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_base64_decrypt_operations.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omakovsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 18:52:30 by omakovsk          #+#    #+#             */
/*   Updated: 2019/02/16 18:52:32 by omakovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_base64.h"
#include "ft_crypt_operations.h"

void			base64_decrypt_operations(unsigned char *decrypt_text,
												t_crypt_info *crypt_info)
{
	unsigned char *result;

	result = base64_decrypt_alghoritm(decrypt_text, crypt_info->data_len);
	if (result)
	{
		base64_result_output(result, crypt_info, ft_strlen((char *)result));
		free(result);
	}
}

unsigned char	*base64_decrypt_alghoritm(unsigned char *decrypt_text,
												unsigned int data_len)
{
	unsigned int	newlen;
	unsigned int	i;
	unsigned char	*result;
	unsigned int	result_len;
	int				ret;

	base64_trim_decode((char *)decrypt_text);
	newlen = (unsigned)ft_strlen((char*)decrypt_text);
	result_len = (newlen / 4) * 3;
	result = (unsigned char *)ft_strnew(result_len);
	if (!result)
		return (NULL);
	i = 0;
	while (i < result_len)
	{
		ret = four_to_three(&(result[i]), decrypt_text, KEY);
		if (ret == -1)
		{
			free(result);
			return (NULL);
		}
		i += 3;
		decrypt_text += 4;
	}
	return (result);
}

void			base64_trim_decode(char *str)
{
	unsigned int	start;
	unsigned int	end;

	start = 0;
	end = 0;
	while (str[end])
	{
		if (!ft_isspace(str[end]))
		{
			str[start] = str[end];
			start++;
		}
		end++;
	}
}

int				four_to_three(unsigned char *res, unsigned char *dec, char *key)
{
	int				i;
	int				j;
	unsigned char	help[4];

	i = -1;
	while (++i < 4)
	{
		if (!(ft_isalpha(dec[i]) || ft_isdigit(dec[i]) || dec[i] == '+' ||
				dec[i] == '/' || dec[i] == '='))
			return (-1);
	}
	i = -1;
	while (++i < 64)
	{
		j = -1;
		while (++j < 4)
			if (dec[j] == key[i])
				help[j] = i;
	}
	return (copy_over(help, dec, res));
}

int				copy_over(unsigned char *help, unsigned char *dec,
												unsigned char *res)
{
	int		i;
	int		ret;

	ret = 0;
	i = -1;
	while (++i < 4)
	{
		if (dec[i] == '=')
		{
			ret++;
			help[i] = 0;
		}
	}
	res[0] = (help[0] << 2) | (help[1] >> 4);
	res[1] = ((help[1] & 15) << 4) | (help[2] >> 2);
	res[2] = ((help[2] & 3) << 6) | help[3];
	return (ret);
}
