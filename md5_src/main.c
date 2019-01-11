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

#include "ft_global.h"
#include "ft_md5.h"
#include "ft_sha.h"
#include "ft_parse_and_read.h"

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

int			printf_no_flag_error(t_hash_ptr hash_type)
{
	ft_printf("usage: ");
	if (hash_type == md5)
		ft_printf("md5 ");
	if (hash_type == sha224)
		ft_printf("sha224 ");
	if (hash_type == sha256)
		ft_printf("sha256 ");
	if (hash_type == sha384)
		ft_printf("sha384 ");
	if (hash_type == sha512)
		ft_printf("sha512 ");
	ft_printf("[-pqrtx] [-s string] [files ...]\n");
	return (1);
}

int			print_error(t_hash_ptr hash_type,\
						t_error_type error_type, char *filename)
{
	if (error_type == no_flag)
		return (printf_no_flag_error(hash_type));
	if (hash_type == md5)
		ft_printf("md5: ");
	if (hash_type == sha224)
		ft_printf("sha224: ");
	if (hash_type == sha256)
		ft_printf("sha256: ");
	if (hash_type == sha384)
		ft_printf("sha384: ");
	if (hash_type == sha512)
		ft_printf("sha512: ");
	if (error_type == no_file)
		ft_printf("%s: No such file or directory\n", filename);
	if (error_type == try_open_dir)
		ft_printf("%s: Is a directory\n", filename);
	if (error_type == error_command)
	{
		ft_printf("Message Digest commands:\n");
		ft_printf("md5\nsha224\nsha256\nsha384\nsha512\n");
	}
	return (1);
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

int			main(int argc, char **argv)
{
	t_hash_info 	info;
	t_crypt_info	crypt_info;

	info.flags = 0;
	info.hashptr = 0;
	argv[argc] = NULL;
	if (argc == 1)
		ft_printf(USAGE_STRING);
	else
	{
		if (!(info.hashptr = find_hash_type(argv[1])) &&
			!crypt_info.cryptptr = find_crypt_type(argv[1]))
			return (print_error(0, error_command, *argv));
		argv = argv + 2;
		if (!crypt_info.cryptptr)

		if (*argv == NULL)
			return (read_hash_info(&info, STDIN, 1));
		while (*argv && (*argv)[0] == '-')
		{
			if (parse_flags(&info, &argv) == UNKNOWN_FLAG)
				return (print_error(info.hashptr, no_flag, *argv));
			argv++;
		}
		while (*argv)
			read_hash_info(&info, *argv++, 1);
	}
	return (0);
}
