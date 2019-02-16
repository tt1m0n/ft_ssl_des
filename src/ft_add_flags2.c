/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_flags2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omakovsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 18:51:35 by omakovsk          #+#    #+#             */
/*   Updated: 2019/02/16 18:51:38 by omakovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../global/ft_global.h"
#include "ft_crypt_operations.h"
#include "ft_des.h"

int		add_o_flag(char ***argv, t_crypt_info *info)
{
	info->flags.o = 1;
	(*argv)++;
	info->flags.output_file = **argv;
	if (!info->flags.output_file)
	{
		ft_printf("missing file argument for -o\n\n");
		print_crypt_flags_usage(NULL, info->crypt_type);
		return (0);
	}
	return (1);
}

int		add_p_flag(char ***argv, t_crypt_info *info)
{
	info->flags.p = 1;
	(*argv)++;
	info->flags.password = (unsigned char*)**argv;
	if (!info->flags.password)
	{
		ft_printf("missing source argument for -p\n\n");
		print_crypt_flags_usage(NULL, info->crypt_type);
		return (0);
	}
	return (1);
}

int		add_s_flag(char ***argv, t_crypt_info *info)
{
	info->flags.s = 1;
	(*argv)++;
	if (!**argv)
	{
		ft_printf("missing salt argument for -k\n\n");
		print_crypt_flags_usage(NULL, info->crypt_type);
		return (0);
	}
	info->flags.salt = get_hex_string(**argv);
	if (!info->flags.salt)
	{
		ft_printf("invalid salt value\n");
		return (0);
	}
	return (1);
}

int		add_v_flag(char ***argv, t_crypt_info *info)
{
	info->flags.v = 1;
	(*argv)++;
	if (!**argv)
	{
		ft_printf("missing IV argument for -v\n\n");
		print_crypt_flags_usage(NULL, info->crypt_type);
		return (0);
	}
	info->flags.in_vector = get_hex_string(**argv);
	if (!info->flags.in_vector)
	{
		ft_printf("invalid hex iv value\n");
		return (0);
	}
	return (1);
}

int		add_show_flag(char ***argv, t_crypt_info *info)
{
	(void)argv;
	info->flags.show = 1;
	return (1);
}
