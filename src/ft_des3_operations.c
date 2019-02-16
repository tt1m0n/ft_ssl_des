/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_des3_operations.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omakovsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 18:54:24 by omakovsk          #+#    #+#             */
/*   Updated: 2019/02/16 18:54:25 by omakovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_des.h"

void			des3(t_crypt_info *crypt_info)
{
	des3_crypt(crypt_info);
}

void			des3_ecb(t_crypt_info *crypt_info)
{
	des3_crypt(crypt_info);
}

void			des3_cbc(t_crypt_info *crypt_info)
{
	des3_crypt(crypt_info);
}
