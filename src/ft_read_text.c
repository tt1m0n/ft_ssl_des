/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_text.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omakovsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 18:56:56 by omakovsk          #+#    #+#             */
/*   Updated: 2019/02/16 18:56:57 by omakovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_crypt_operations.h"

static char		*append_data(char *str, char *buff, unsigned int l,
								unsigned int r)
{
	char			*final;
	unsigned int	i;

	final = ft_strnew(l + r);
	i = 0;
	while (i < l)
	{
		final[i] = str[i];
		i++;
	}
	i = 0;
	while (i < r)
	{
		final[i + l] = buff[i];
		i++;
	}
	free(str);
	return (final);
}

unsigned char	*take_crypt_text_from_output(int fd, t_crypt_info *crypt_info)
{
	char			*need_to_crypt;
	char			tmp_buffer[BUFFER_SIZE + 1];
	unsigned int	ret_len;
	char			*tmp;

	ft_bzero(tmp_buffer, sizeof(char) * BUFFER_SIZE + 1);
	need_to_crypt = ft_strnew(0);
	while ((ret_len = read(fd, tmp_buffer, BUFFER_SIZE)) > 0)
	{
		need_to_crypt = append_data(need_to_crypt, tmp_buffer,
				crypt_info->data_len, ret_len);
		crypt_info->data_len += ret_len;
		ft_bzero(tmp_buffer, sizeof(char) * BUFFER_SIZE + 1);
	}
	if (fd)
		close(fd);
	if (!ft_memcmp("Salted__", need_to_crypt, 8) && crypt_info->data_len > 16)
	{
		crypt_info->data_len -= 16;
		tmp = need_to_crypt;
		need_to_crypt = ft_strnew(crypt_info->data_len);
		ft_memcpy(need_to_crypt, &tmp[16], crypt_info->data_len);
		free(tmp);
	}
	return ((unsigned char*)need_to_crypt);
}
