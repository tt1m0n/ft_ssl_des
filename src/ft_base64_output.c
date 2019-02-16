/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_base64_output.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omakovsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 18:53:11 by omakovsk          #+#    #+#             */
/*   Updated: 2019/02/16 18:53:13 by omakovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_base64.h"

void	base64_result_output(unsigned char *result,
						t_crypt_info *crypt_info, unsigned int len)
{
	unsigned int i;

	i = 1;
	if (result)
	{
		if (crypt_info->flags.output_file)
			write_to_file(result, len, crypt_info->flags.output_file,
					crypt_info->flags.d);
		else
		{
			while (i <= len)
			{
				write(1, result, 1);
				if ((i % 64) == 0 && i + 1 <= len && !crypt_info->flags.d)
					write(1, "\n", 1);
				i++;
				result++;
			}
			if (!crypt_info->flags.d)
				write(1, "\n", 1);
		}
	}
}

void	write_to_file(unsigned char *result, unsigned int len,
						char *filename, uint8_t is_decode)
{
	int				fd;
	unsigned int	i;

	i = 1;
	fd = open(filename, O_WRONLY | O_CREAT, 0644);
	if (fd == -1)
		ft_printf("unable to open file %s\n", filename);
	while (i <= len)
	{
		if (write(fd, result, 1) == -1)
		{
			ft_printf("unable to write to file %s\n", filename);
			return ;
		}
		if ((i % 64) == 0)
			write(fd, "\n", 1);
		i++;
		result++;
	}
	if (!is_decode && write(fd, "\n", 1) == -1)
		ft_printf("unable to write to file %s\n", filename);
}
