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

t_crypt_ptr	find_hash_type(char *hash)
{
	int i;

	i = START_VALUE;
	while (g_crypt_name[i] != 0)
	{
		if (ft_strcmp(g_crypt_name[i], hash) == 0)
			return (g_crypt_name[i]);
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
		ft_printf("md5\nsha224\nsha256\nsha384\nsha512\n\n");
		ft_printf("Cipher commands:\nbase64\ndes\ndes-ecb\ndes-cbc\n");
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

void		base64_operations(char **argv, t_crypt_info *crypt_info)
{
	(void)argv;
	(void)crypt_info;
}

void		des_operations(char **argv, t_crypt_info *crypt_info)
{
	(void)argv;
	(void)crypt_info;
}

//void		zero_crypt_flags(t_crypt_flags *flags)
//{
//	flags->a = 0;
//	flags->d = 0;
//	flags->input_file = NULL;
//	flags->key = NULL;
//	flags->output_file = NULL;
//	flags->password = NULL;
//	flags->salt = NULL;
//	flags->in_vector = NULL;
//}

int 		printf_crypt_flags_usage(char *argument)
{
	ft_printf("unknown options \'%s\'\n\n", argument);
	ft_printf("-a   decode/encode the input/output in base64, depending on the encrypt mode\n");
	ft_printf("-d   decrypt mode\n");
	ft_printf("-e   encrypt mode\n");
	ft_printf("-i   input file for message is the next argument\n");
	ft_printf("-k   key in hex is the next argument\n");
	ft_printf("-o   output file for message is the next argument\n");
	ft_printf("-p   password in ascii is the next argument\n");
	ft_printf("-s   salt in hex is the next argument\n");
	ft_printf("-v   initialization vector in hex is the next argument\n");

	return (0);
}

int			is_parse_crypt_flags(char **argv, t_crypt_flags *flags)
{
	if (!*argv)
		return 1;
	if (*argv[0] != "-")
		print_crypt_flags_usage(*argv);
	while ()
}

void		crypt_info_operations(char **argv, t_crypt_info *crypt_info)
{
	if (!is_parse_crypt_flags(argv, &crypt_info->flags))
		return ;
	if (crypt_info->cryptptr == null)
		base64_operations(argv, crypt_info);
	else
		des_operations(argv, crypt_info);
}

int			main(int argc, char **argv)
{
	t_hash_info 	hash_info;
	t_crypt_info	crypt_info;

	hash_info.flags = 0;
	hash_info.hashptr = 0;
	crypt_info.cryptptr = 0;
	crypt_info.flags = {};
	argv[argc] = NULL;
	if (argc == 1)
		ft_printf(USAGE_STRING);
	else
	{
		if (!(hash_info.hashptr = find_hash_type(argv[1])) &&
			!crypt_info.cryptptr = find_crypt_type(argv[1]))
			return (print_error(0, error_command, *argv));
		if (hash_info.hashptr)
			return hash_info_operations(argv + 2, &hash_info);
		if (crypt_info.cryptptr)
			crypt_info_operations(argv + 2, &crypt_info);
	}
	return (0);
}
