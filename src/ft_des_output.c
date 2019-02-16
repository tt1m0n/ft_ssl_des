/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_des_output.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omakovsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 18:55:38 by omakovsk          #+#    #+#             */
/*   Updated: 2019/02/16 18:55:40 by omakovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_des.h"

void	des_cbc_result_output(t_crypt_info *crypt_info,
								unsigned char *result)
{
	unsigned int i;

	i = 1;
	if (result)
	{
		if (crypt_info->flags.output_file)
			write_des_to_file(result, crypt_info);
		else
		{
			write(1, (char*)result, crypt_info->data_len);
			if (crypt_info->flags.a && !crypt_info->flags.d)
				write(1, "\n", 1);
		}
	}
}

void	write_des_to_file(unsigned char *result, t_crypt_info *crypt_info)
{
	int				fd;
	char			*filename;

	filename = crypt_info->flags.output_file;
	fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
		ft_printf("unable to open file %s\n", filename);
	if (write(fd, (char*)result, crypt_info->data_len) == -1)
	{
		ft_printf("unable to write to file %s\n", filename);
		return ;
	}
	if (crypt_info->flags.d || !crypt_info->flags.a)
		return ;
	if (write(fd, "\n", 1) == -1)
		ft_printf("unable to write to file %s\n", filename);
}
