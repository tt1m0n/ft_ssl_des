/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_des_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omakovsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 18:55:30 by omakovsk          #+#    #+#             */
/*   Updated: 2019/02/16 18:55:32 by omakovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_des.h"

void	des_operations(t_crypt_info *crypt_info)
{
	crypt_info->cryptptr(crypt_info);
}

void	des(t_crypt_info *crypt_info)
{
	des_crypt(crypt_info);
}

void	des_cbc(t_crypt_info *crypt_info)
{
	des_crypt(crypt_info);
}

void	des_ecb(t_crypt_info *crypt_info)
{
	des_crypt(crypt_info);
}
