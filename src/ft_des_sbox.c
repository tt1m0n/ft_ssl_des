/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_des_sbox.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omakovsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 18:56:12 by omakovsk          #+#    #+#             */
/*   Updated: 2019/02/16 18:56:13 by omakovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_des.h"

/*
** Input char 6 bits of data
** Output char 4 bits of data
*/

unsigned char	des_sbox(unsigned char sixbits, unsigned char *box)
{
	unsigned char	index;

	index = 0;
	index += ((sixbits >> 5) & 1) * 32;
	index += (sixbits & 1) * 16;
	index += ((sixbits >> 1) & 15);
	return (box[(int)index]);
}

/*
** Input 48 bits, Output 32 bits
*/

unsigned char	*des_sbox_sub(unsigned char *six)
{
	unsigned char	*four;

	four = (unsigned char *)ft_strnew(4);
	if (!four)
		return (NULL);
	four[0] = des_sbox(six[0] >> 2, g_des_sbox_1) << 4;
	four[0] += des_sbox(((six[0] & 3) << 4) + (six[1] >> 4), g_des_sbox_2);
	four[1] = des_sbox(((six[1] & 15) << 2) + (six[2] >> 6), g_des_sbox_3) << 4;
	four[1] += des_sbox(six[2] & 63, g_des_sbox_4);
	four[2] = des_sbox(six[3] >> 2, g_des_sbox_5) << 4;
	four[2] += des_sbox(((six[3] & 3) << 4) + (six[4] >> 4), g_des_sbox_6);
	four[3] = des_sbox(((six[4] & 15) << 2) + (six[5] >> 6), g_des_sbox_7) << 4;
	four[3] += des_sbox(six[5] & 63, g_des_sbox_8);
	free(six);
	return (four);
}
