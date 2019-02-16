/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_flags1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omakovsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 18:51:29 by omakovsk          #+#    #+#             */
/*   Updated: 2019/02/16 18:51:31 by omakovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../global/ft_global.h"
#include "ft_crypt_operations.h"
#include "ft_des.h"

int		add_a_flag(char ***argv, t_crypt_info *info)
{
	(void)argv;
	info->flags.a = 1;
	return (1);
}

int		add_d_flag(char ***argv, t_crypt_info *info)
{
	(void)argv;
	info->flags.d = 1;
	return (1);
}

int		add_e_flag(char ***argv, t_crypt_info *info)
{
	(void)argv;
	info->flags.d = 0;
	return (1);
}

int		add_i_flag(char ***argv, t_crypt_info *info)
{
	info->flags.i = 1;
	(*argv)++;
	info->flags.input_file = **argv;
	if (!info->flags.input_file)
	{
		ft_printf("missing file argument for -i\n\n");
		print_crypt_flags_usage(NULL, info->crypt_type);
		return (0);
	}
	return (1);
}

int		add_k_flag(char ***argv, t_crypt_info *info)
{
	info->flags.k = 1;
	(*argv)++;
	if (!**argv)
	{
		ft_printf("missing key argument for -k\n\n");
		print_crypt_flags_usage(NULL, info->crypt_type);
		return (0);
	}
	info->flags.key = get_hex_string(**argv);
	if (!info->flags.key)
	{
		ft_printf("invalid hex key value\n");
		return (0);
	}
	return (1);
}
