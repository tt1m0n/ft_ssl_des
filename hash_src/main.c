/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omakovsk <omakovsk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/25 15:59:00 by omakovsk          #+#    #+#             */
/*   Updated: 2018/09/02 14:56:31 by omakovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_md5.h"
#include "ft_sha.h"
#include "ft_parse_and_read.h"
#include "../crypt_src/ft_base64.h"
#include "../global/ft_global.h"
#include "../crypt_src/ft_crypt_operations.h"
#include "../crypt_src/ft_flags_operations.h"

void    zero_crypt_info_struct(t_crypt_info *crypt_info)
{
    crypt_info->crypt_type = unknown_type;
    crypt_info->cryptptr = 0;
    zero_crypt_flags(&crypt_info->flags);
    crypt_info->data_len = 0;
}

t_hash_ptr	find_hash_type(char *hash)
{
	int i;

	i = START_VALUE;
	while (g_hash_name[i] != 0)
	{
		if (ft_strcmp(g_hash_name[i], hash) == 0)
			return (g_hash_function[i]);
		i++;
	}
	return (0);
}

t_crypt_ptr	find_crypt_type(char *crypt_type)
{
	int i;

	i = START_VALUE;
	while (g_crypt_name[i] != 0)
	{
		if (ft_strcmp(g_crypt_name[i], crypt_type) == 0)
			return (g_crypt_function[i]);
		i++;
	}
	return (0);
}

int			hash_info_operations(char **argv, t_hash_info *hash_info)
{
	if (!*argv)
		return (read_hash_info(hash_info, STDIN, 1));
	while (*argv && (*argv)[0] == '-')
	{
		if (parse_flags(hash_info, &argv) == UNKNOWN_FLAG)
			return (print_error(hash_info->hashptr, no_flag, *argv));
		argv++;
	}
	while (*argv)
		read_hash_info(hash_info, *argv++, 1);
	return (0);
}

int			main(int argc, char **argv)
{
	t_hash_info 	hash_info;
	t_crypt_info	crypt_info;

	hash_info.flags = 0;
	hash_info.hashptr = 0;
	zero_crypt_info_struct(&crypt_info);
	argv[argc] = NULL;
	if (argc == 1)
		ft_printf(USAGE_STRING);
	else
	{
		if (!(hash_info.hashptr = find_hash_type(argv[1])) &&
			!(crypt_info.cryptptr = find_crypt_type(argv[1])))
			return (print_error(0, error_command, *argv));
		if (hash_info.hashptr)
			return hash_info_operations(argv + 2, &hash_info);
		else if (crypt_info.cryptptr)
			crypt_info_operations(argv + 2, &crypt_info);
	}
	return (0);
}
