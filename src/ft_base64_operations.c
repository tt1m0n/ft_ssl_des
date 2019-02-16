/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_base64_operations.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omakovsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 18:53:01 by omakovsk          #+#    #+#             */
/*   Updated: 2019/02/16 18:53:03 by omakovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_base64.h"

void	base64_operations(t_crypt_info *crypt_info)
{
	crypt_info->cryptptr(crypt_info);
}

void	base64(t_crypt_info *crypt_info)
{
	if (crypt_info->flags.d)
		base64_decrypt(crypt_info);
	else
		base64_encrypt(crypt_info);
}
