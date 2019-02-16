/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_base64_encrypt.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omakovsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 18:52:45 by omakovsk          #+#    #+#             */
/*   Updated: 2019/02/16 18:52:48 by omakovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_base64.h"
#include "ft_crypt_operations.h"

void			base64_encrypt(t_crypt_info *crypt_info)
{
	unsigned char *crypt_text;

	crypt_text = read_crypt_text(crypt_info);
	if (!crypt_text)
		return ;
	base64_encrypt_operations(crypt_text, crypt_info);
	free(crypt_text);
}
