/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_crypt_operations.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omakovsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 18:53:37 by omakovsk          #+#    #+#             */
/*   Updated: 2019/02/16 18:53:38 by omakovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_global.h"
#include "ft_base64.h"
#include "ft_des.h"
#include "ft_crypt_operations.h"
#include "ft_flags_operations.h"

void			crypt_info_operations(char **argv, t_crypt_info *crypt_info)
{
	if (crypt_info->cryptptr == base64)
		crypt_info->crypt_type = base64_type;
	else
		crypt_info->crypt_type = des_type;
	zero_crypt_flags(&crypt_info->flags);
	if (!is_parse_crypt_flags(argv, crypt_info))
		return ;
	if (crypt_info->crypt_type == base64_type)
		base64_operations(crypt_info);
	else
		des_operations(crypt_info);
}

unsigned char	*read_crypt_text(t_crypt_info *crypt_info)
{
	int fd;

	fd = 0;
	if (crypt_info->flags.input_file)
		fd = open(crypt_info->flags.input_file, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("%s: Noo such file or directory\n",
				crypt_info->flags.input_file);
		return (NULL);
	}
	if (read(fd, NULL, 0) == -1)
	{
		ft_printf("%s: Is a directory\n", crypt_info->flags.input_file);
		return (NULL);
	}
	return (take_crypt_text_from_output(fd, crypt_info));
}

int				ft_isspace(int c)
{
	if (c == ' ' || c == '\n' || c == '\t')
		return (1);
	if (c == '\v' || c == '\f' || c == '\r')
		return (1);
	return (0);
}

void			get_crypt_password(t_crypt_info *crypt_info)
{
	char *temp;

	if (crypt_info->flags.p || crypt_info->flags.k)
		return ;
	temp = getpass("enter des-cbc encryption password:");
	crypt_info->flags.password = ft_strnew(ft_strlen(temp) + 1);
	ft_strcpy(crypt_info->flags.password, temp);
	temp = getpass("Verifying - enter des-cbc encryption password:");
	if (!crypt_info->flags.password[0] && !temp[0])
	{
		free(crypt_info->flags.password);
		crypt_info->flags.password = NULL;
		return ;
	}
	if (ft_strcmp(crypt_info->flags.password, temp))
	{
		free(crypt_info->flags.password);
		crypt_info->flags.password = NULL;
		ft_printf("Verify failure\nbad password read\n");
		return ;
	}
}
