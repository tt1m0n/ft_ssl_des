/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_start_words.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlogin <xlogin@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/01 17:46:00 by xlogin            #+#    #+#             */
/*   Updated: 2018/09/01 17:46:00 by xlogin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sha.h"
#include "ft_md5.h"

void	md5_init_start_words(t_md5_info *md5)
{
	md5->a = 0x67452301;
	md5->b = 0xefcdab89;
	md5->c = 0x98badcfe;
	md5->d = 0x10325476;
	md5->lo = 0;
	md5->hi = 0;
}

void	sha224_init_start_words(t_uint *info)
{
	info[0] = 0xc1059ed8;
	info[1] = 0x367cd507;
	info[2] = 0x3070dd17;
	info[3] = 0xf70e5939;
	info[4] = 0xffc00b31;
	info[5] = 0x68581511;
	info[6] = 0x64f98fa7;
	info[7] = 0xbefa4fa4;
}

void	sha256_init_start_words(t_uint *info)
{
	info[0] = 0x6a09e667;
	info[1] = 0xbb67ae85;
	info[2] = 0x3c6ef372;
	info[3] = 0xa54ff53a;
	info[4] = 0x510e527f;
	info[5] = 0x9b05688c;
	info[6] = 0x1f83d9ab;
	info[7] = 0x5be0cd19;
}

void	sha384_init_start_words(t_ulong *info)
{
	info[0] = 0xcbbb9d5dc1059ed8;
	info[1] = 0x629a292a367cd507;
	info[2] = 0x9159015a3070dd17;
	info[3] = 0x152fecd8f70e5939;
	info[4] = 0x67332667ffc00b31;
	info[5] = 0x8eb44a8768581511;
	info[6] = 0xdb0c2e0d64f98fa7;
	info[7] = 0x47b5481dbefa4fa4;
}

void	sha512_init_start_words(t_ulong *info)
{
	info[0] = 0x6a09e667f3bcc908;
	info[1] = 0xbb67ae8584caa73b;
	info[2] = 0x3c6ef372fe94f82b;
	info[3] = 0xa54ff53a5f1d36f1;
	info[4] = 0x510e527fade682d1;
	info[5] = 0x9b05688c2b3e6c1f;
	info[6] = 0x1f83d9abfb41bd6b;
	info[7] = 0x5be0cd19137e2179;
}
