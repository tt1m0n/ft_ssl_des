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

#include "../global/ft_global.h"
#include "ft_md5.h"
#include "ft_sha.h"
#include "../crypt_src/ft_base64.h"
#include "ft_parse_and_read.h"
#include "../global/print_error.h"
#include "../crypt_src/crypt_operations.h"

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

void	test(char* a, int* flags, char* filename)
{
	(void)a;
	(void)flags;
	(void)filename;
}


t_crypt_ptr	find_crypt_type(char *hash)
{
//	int i;
//
//	i = START_VALUE;
//	while (g_crypt_name[i] != 0)
//	{
//		if (ft_strcmp(g_crypt_name[i], hash) == 0)
//			return (g_crypt_name[i]);
//		i++;
//	}
//	return (0);
	(void)hash;
	return test;
}

char		*take_text_from_file(int fd)
{
	char	*need_to_hash;
	char	*tmp_buffer;
	char	*ptr_to_free;

	need_to_hash = ft_memalloc(1);
	tmp_buffer = ft_memalloc(BUFFER_SIZE);
	while (read(fd, tmp_buffer, BUFFER_SIZE - 1))
	{
		ptr_to_free = need_to_hash;
		need_to_hash = ft_strjoin(need_to_hash, tmp_buffer);
		free(ptr_to_free);
		ft_memset(tmp_buffer, 0, BUFFER_SIZE);
	}
	free(tmp_buffer);
	if (fd)
		close(fd);
	return (need_to_hash);
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
	crypt_info.cryptptr = 0;
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
