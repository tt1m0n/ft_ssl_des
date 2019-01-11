/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_md5_rounds.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlogin <xlogin@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/02 11:49:00 by xlogin            #+#    #+#             */
/*   Updated: 2018/09/02 11:49:00 by xlogin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_md5.h"

void	md5_round1(t_uint *t, t_md5_info *c, const t_uchar *p)
{
	step(F(t[1], t[2], t[3]) + set(0, c, p) + 0xd76aa478, &t[0], &t[1], 7);
	step(F(t[0], t[1], t[2]) + set(1, c, p) + 0xe8c7b756, &t[3], &t[0], 12);
	step(F(t[3], t[0], t[1]) + set(2, c, p) + 0x242070db, &t[2], &t[3], 17);
	step(F(t[2], t[3], t[0]) + set(3, c, p) + 0xc1bdceee, &t[1], &t[2], 22);
	step(F(t[1], t[2], t[3]) + set(4, c, p) + 0xf57c0faf, &t[0], &t[1], 7);
	step(F(t[0], t[1], t[2]) + set(5, c, p) + 0x4787c62a, &t[3], &t[0], 12);
	step(F(t[3], t[0], t[1]) + set(6, c, p) + 0xa8304613, &t[2], &t[3], 17);
	step(F(t[2], t[3], t[0]) + set(7, c, p) + 0xfd469501, &t[1], &t[2], 22);
	step(F(t[1], t[2], t[3]) + set(8, c, p) + 0x698098d8, &t[0], &t[1], 7);
	step(F(t[0], t[1], t[2]) + set(9, c, p) + 0x8b44f7af, &t[3], &t[0], 12);
	step(F(t[3], t[0], t[1]) + set(10, c, p) + 0xffff5bb1, &t[2], &t[3], 17);
	step(F(t[2], t[3], t[0]) + set(11, c, p) + 0x895cd7be, &t[1], &t[2], 22);
	step(F(t[1], t[2], t[3]) + set(12, c, p) + 0x6b901122, &t[0], &t[1], 7);
	step(F(t[0], t[1], t[2]) + set(13, c, p) + 0xfd987193, &t[3], &t[0], 12);
	step(F(t[3], t[0], t[1]) + set(14, c, p) + 0xa679438e, &t[2], &t[3], 17);
	step(F(t[2], t[3], t[0]) + set(15, c, p) + 0x49b40821, &t[1], &t[2], 22);
}

void	md5_round2(t_uint *t, t_md5_info *c)
{
	step(G(t[1], t[2], t[3]) + GET(1) + 0xf61e2562, &t[0], &t[1], 5);
	step(G(t[0], t[1], t[2]) + GET(6) + 0xc040b340, &t[3], &t[0], 9);
	step(G(t[3], t[0], t[1]) + GET(11) + 0x265e5a51, &t[2], &t[3], 14);
	step(G(t[2], t[3], t[0]) + GET(0) + 0xe9b6c7aa, &t[1], &t[2], 20);
	step(G(t[1], t[2], t[3]) + GET(5) + 0xd62f105d, &t[0], &t[1], 5);
	step(G(t[0], t[1], t[2]) + GET(10) + 0x02441453, &t[3], &t[0], 9);
	step(G(t[3], t[0], t[1]) + GET(15) + 0xd8a1e681, &t[2], &t[3], 14);
	step(G(t[2], t[3], t[0]) + GET(4) + 0xe7d3fbc8, &t[1], &t[2], 20);
	step(G(t[1], t[2], t[3]) + GET(9) + 0x21e1cde6, &t[0], &t[1], 5);
	step(G(t[0], t[1], t[2]) + GET(14) + 0xc33707d6, &t[3], &t[0], 9);
	step(G(t[3], t[0], t[1]) + GET(3) + 0xf4d50d87, &t[2], &t[3], 14);
	step(G(t[2], t[3], t[0]) + GET(8) + 0x455a14ed, &t[1], &t[2], 20);
	step(G(t[1], t[2], t[3]) + GET(13) + 0xa9e3e905, &t[0], &t[1], 5);
	step(G(t[0], t[1], t[2]) + GET(2) + 0xfcefa3f8, &t[3], &t[0], 9);
	step(G(t[3], t[0], t[1]) + GET(7) + 0x676f02d9, &t[2], &t[3], 14);
	step(G(t[2], t[3], t[0]) + GET(12) + 0x8d2a4c8a, &t[1], &t[2], 20);
}

void	md5_round3(t_uint *t, t_md5_info *c)
{
	step(H(t[1], t[2], t[3]) + GET(5) + 0xfffa3942, &t[0], &t[1], 4);
	step(H2(t[0], t[1], t[2]) + GET(8) + 0x8771f681, &t[3], &t[0], 11);
	step(H(t[3], t[0], t[1]) + GET(11) + 0x6d9d6122, &t[2], &t[3], 16);
	step(H2(t[2], t[3], t[0]) + GET(14) + 0xfde5380c, &t[1], &t[2], 23);
	step(H(t[1], t[2], t[3]) + GET(1) + 0xa4beea44, &t[0], &t[1], 4);
	step(H2(t[0], t[1], t[2]) + GET(4) + 0x4bdecfa9, &t[3], &t[0], 11);
	step(H(t[3], t[0], t[1]) + GET(7) + 0xf6bb4b60, &t[2], &t[3], 16);
	step(H2(t[2], t[3], t[0]) + GET(10) + 0xbebfbc70, &t[1], &t[2], 23);
	step(H(t[1], t[2], t[3]) + GET(13) + 0x289b7ec6, &t[0], &t[1], 4);
	step(H2(t[0], t[1], t[2]) + GET(0) + 0xeaa127fa, &t[3], &t[0], 11);
	step(H(t[3], t[0], t[1]) + GET(3) + 0xd4ef3085, &t[2], &t[3], 16);
	step(H(t[2], t[3], t[0]) + GET(6) + 0x04881d05, &t[1], &t[2], 23);
	step(H(t[1], t[2], t[3]) + GET(9) + 0xd9d4d039, &t[0], &t[1], 4);
	step(H2(t[0], t[1], t[2]) + GET(12) + 0xe6db99e5, &t[3], &t[0], 11);
	step(H(t[3], t[0], t[1]) + GET(15) + 0x1fa27cf8, &t[2], &t[3], 16);
	step(H2(t[2], t[3], t[0]) + GET(2) + 0xc4ac5665, &t[1], &t[2], 23);
}

void	md5_round4(t_uint *t, t_md5_info *c)
{
	step(I(t[1], t[2], t[3]) + GET(0) + 0xf4292244, &t[0], &t[1], 6);
	step(I(t[0], t[1], t[2]) + GET(7) + 0x432aff97, &t[3], &t[0], 10);
	step(I(t[3], t[0], t[1]) + GET(14) + 0xab9423a7, &t[2], &t[3], 15);
	step(I(t[2], t[3], t[0]) + GET(5) + 0xfc93a039, &t[1], &t[2], 21);
	step(I(t[1], t[2], t[3]) + GET(12) + 0x655b59c3, &t[0], &t[1], 6);
	step(I(t[0], t[1], t[2]) + GET(3) + 0x8f0ccc92, &t[3], &t[0], 10);
	step(I(t[3], t[0], t[1]) + GET(10) + 0xffeff47d, &t[2], &t[3], 15);
	step(I(t[2], t[3], t[0]) + GET(1) + 0x85845dd1, &t[1], &t[2], 21);
	step(I(t[1], t[2], t[3]) + GET(8) + 0x6fa87e4f, &t[0], &t[1], 6);
	step(I(t[0], t[1], t[2]) + GET(15) + 0xfe2ce6e0, &t[3], &t[0], 10);
	step(I(t[3], t[0], t[1]) + GET(6) + 0xa3014314, &t[2], &t[3], 15);
	step(I(t[2], t[3], t[0]) + GET(13) + 0x4e0811a1, &t[1], &t[2], 21);
	step(I(t[1], t[2], t[3]) + GET(4) + 0xf7537e82, &t[0], &t[1], 6);
	step(I(t[0], t[1], t[2]) + GET(11) + 0xbd3af235, &t[3], &t[0], 10);
	step(I(t[3], t[0], t[1]) + GET(2) + 0x2ad7d2bb, &t[2], &t[3], 15);
	step(I(t[2], t[3], t[0]) + GET(9) + 0xeb86d391, &t[1], &t[2], 21);
}
