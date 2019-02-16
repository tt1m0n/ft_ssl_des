/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_base64_decrypt.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omakovsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 18:52:20 by omakovsk          #+#    #+#             */
/*   Updated: 2019/02/16 18:52:21 by omakovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_base64.h"
#include "ft_crypt_operations.h"

void	base64_decrypt(t_crypt_info *crypt_info)
{
	unsigned char *decrypt_text;

	decrypt_text = read_crypt_text(crypt_info);
	if (!decrypt_text)
		return ;
	base64_decrypt_operations(decrypt_text, crypt_info);
}
