/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_des_round.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omakovsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 18:55:55 by omakovsk          #+#    #+#             */
/*   Updated: 2019/02/16 18:55:57 by omakovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_des.h"

#define LSHIFT(a,b) (temp[a] << b)
#define RSHIFT(a,b) (temp[a] >> b)

#define LSHBY(a,b,c) ((str[a] & b) << c)
#define RSHBY(a,b,c) ((str[a] & b) >> c)

/*
** right - untouched
** temporary string contains right's workings
** left is modified by xor with temp to become the new right
*/

void			des_round(unsigned char *left, unsigned char *right,
								unsigned char *subkey)
{
	unsigned char	*temp;

	temp = des_expansion_perm(right);
	data_xor(temp, subkey, 6);
	temp = des_sbox_sub(temp);
	temp = des_pbox_perm(temp);
	data_xor(left, temp, 4);
	free(temp);
}

unsigned char	des_expansion(unsigned char fourth_byte)
{
	unsigned char	sixth_byte;

	sixth_byte = 0;
	sixth_byte += fourth_byte << 2;
	sixth_byte += (fourth_byte & 8) << 4;
	sixth_byte += (fourth_byte & 1);
	return (sixth_byte);
}

unsigned char	*des_expansion_perm(unsigned char *right)
{
	unsigned char	*expanded;
	unsigned char	temp[8];

	expanded = (unsigned char *)ft_strnew(6);
	temp[0] = des_expansion(right[0] >> 4);
	temp[1] = des_expansion(right[0] & 15);
	temp[2] = des_expansion(right[1] >> 4);
	temp[3] = des_expansion(right[1] & 15);
	temp[4] = des_expansion(right[2] >> 4);
	temp[5] = des_expansion(right[2] & 15);
	temp[6] = des_expansion(right[3] >> 4);
	temp[7] = des_expansion(right[3] & 15);
	expanded[0] = LSHIFT(7, 7) + LSHIFT(0, 1) + RSHIFT(1, 5);
	expanded[1] = LSHIFT(1, 3) + RSHIFT(2, 3);
	expanded[2] = LSHIFT(2, 5) + RSHIFT(3, 1) + RSHIFT(4, 7);
	expanded[3] = LSHIFT(3, 7) + LSHIFT(4, 1) + RSHIFT(5, 5);
	expanded[4] = LSHIFT(5, 3) + RSHIFT(6, 3);
	expanded[5] = LSHIFT(6, 5) + RSHIFT(7, 1) + RSHIFT(0, 7);
	return (expanded);
}

unsigned char	*des_pbox_perm(unsigned char *str)
{
	unsigned char	temp[4];

	ft_bzero(temp, sizeof(unsigned char) * 4);
	temp[0] = LSHBY(0, 2, 5) + LSHBY(2, 24, 1) + RSHBY(3, 16, 3);
	temp[0] += RSHBY(2, 128, 7) + (str[3] & 8);
	temp[0] += LSHBY(1, 1, 7) + RSHBY(1, 16, 2);
	temp[1] = (str[0] & 136) + LSHBY(1, 2, 5) + RSHBY(1, 64, 6);
	temp[1] += LSHBY(2, 2, 4) + RSHBY(2, 64, 4);
	temp[1] += (str[3] & 2) + RSHBY(3, 64, 2);
	temp[2] = LSHBY(0, 64, 1) + LSHBY(0, 1, 6) + RSHBY(0, 32, 4);
	temp[2] += LSHBY(2, 1, 5) + LSHBY(1, 4, 2) + RSHBY(1, 128, 7);
	temp[2] += LSHBY(3, 1, 3) + RSHBY(3, 32, 3);
	temp[3] = LSHBY(0, 4, 2) + RSHBY(0, 16, 3) + LSHBY(1, 8, 3);
	temp[3] += RSHBY(1, 32, 3) + LSHBY(2, 32, 2) + LSHBY(2, 4, 1);
	temp[3] += LSHBY(3, 4, 3) + RSHBY(3, 128, 7);
	data_copy(str, temp, 4);
	return (str);
}
