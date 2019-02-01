#include "ft_des.h"

#define L56(a,b,c) ((key[a] & b) << c)
#define R56(a,b,c) ((key[a] & b) >> c)

#define L48(a,b,c) ((key[a] & b) << c)
#define R48(a,b,c) ((key[a] & b) >> c)

#define GETKY(a,b) (key[a] & b)

unsigned char		*des_key_reduction(unsigned char *key, int it)
{
	unsigned char	*reduction;
	int				i;

	reduction = (unsigned char *)ft_strnew(7);
	if (!reduction)
		return (NULL);
	while (++it < 3)
	{
		i = -1;
		while (++i < 8)
			reduction[it] += ((key[i] & (128 >> it)) << it) >> (7 - i);
	}
	reduction[3] += L56(7, 16, 3) + L56(6, 16, 2) + L56(5, 16, 1);
	reduction[3] += L56(4, 16, 0) + L56(7, 2, 2) + L56(6, 2, 1);
	reduction[3] += L56(5, 2, 0) + R56(4, 2, 1);
	reduction[4] += L56(3, 2, 6) + L56(2, 2, 5) + L56(1, 2, 4);
	reduction[4] += L56(0, 2, 3) + L56(7, 4, 1) + L56(6, 4, 0);
	reduction[4] += R56(5, 4, 1) + R56(4, 4, 2);
	reduction[5] += L56(3, 4, 5) + L56(2, 4, 4) + L56(1, 4, 3);
	reduction[5] += L56(0, 4, 2) + R56(7, 8, 0) + R56(6, 8, 1);
	reduction[5] += R56(5, 8, 2) + R56(4, 8, 3);
	reduction[6] += L56(3, 8, 4) + L56(2, 8, 3) + L56(1, 8, 2);
	reduction[6] += L56(0, 8, 1) + R56(3, 16, 1) + R56(2, 16, 2);
	reduction[6] += R56(1, 16, 3) + R56(0, 16, 4);
	return (reduction);
}

void			des_key_r_rotation(unsigned char *key, int num)
{
	unsigned char	left;
	unsigned char	right;

	left = (key[3] & ((3 << (2 + num)) & ~15)) << (4 - num);
	right = (key[6] & (3 >> (2 - num))) << (4 - num);
	key[6] = (key[6] >> num) + (key[5] << (8 - num));
	key[5] = (key[5] >> num) + (key[4] << (8 - num));
	key[4] = (key[4] >> num) + (key[3] << (8 - num));
	key[3] = (key[3] >> num) + (key[2] << (8 - num));
	key[3] = (key[3] & ~((3 << (4 - num)) & 15)) + (right);
	key[2] = (key[2] >> num) + (key[1] << (8 - num));
	key[1] = (key[1] >> num) + (key[0] << (8 - num));
	key[0] = (key[0] >> num) + left;
}

void			des_key_l_rotation(unsigned char *key, int num)
{
	unsigned char	left;
	unsigned char	right;

	left = (key[0] >> (8 - num)) << 4;
	right = (key[3] & 15) >> (4 - num);
	key[0] = (key[0] << num) + (key[1] >> (8 - num));
	key[1] = (key[1] << num) + (key[2] >> (8 - num));
	key[2] = (key[2] << num) + (key[3] >> (8 - num));
	key[3] = (key[3] << num) + (key[4] >> (8 - num));
	key[3] = (key[3] & ~((3 << (num + 2)) & ~15)) + (left);
	key[4] = (key[4] << num) + (key[5] >> (8 - num));
	key[5] = (key[5] << num) + (key[6] >> (8 - num));
	key[6] = (key[6] << num) + right;
}


/*
** Input is 7 chars, 56 bytes
** Output is 6 chars, 48 bytes
*/

unsigned char	*des_get_subkey(unsigned char *key)
{
	unsigned char	*sub;

	sub = (unsigned char *)ft_strnew(6);
	if (!sub)
		return (NULL);
	sub[0] += L48(1, 4, 5) + R48(2, 128, 1) + GETKY(1, 32);
	sub[0] += L48(2, 1, 4) + R48(0, 128, 4) + R48(0, 8, 1);
	sub[0] += R48(0, 32, 4) + R48(3, 16, 4);
	sub[1] += L48(1, 2, 6) + L48(0, 4, 4) + L48(2, 8, 2);
	sub[1] += R48(1, 64, 2) + L48(2, 2, 2) + R48(2, 32, 3);
	sub[1] += R48(1, 16, 3) + R48(0, 16, 4);
	sub[2] += L48(3, 64, 1) + L48(0, 1, 6) + L48(1, 1, 5);
	sub[2] += L48(0, 2, 3) + R48(3, 32, 2) + R48(2, 16, 2);
	sub[2] += R48(1, 8, 2) + R48(0, 64, 6);
	sub[3] += GETKY(5, 128) + L48(6, 16, 2) + L48(3, 2, 4);
	sub[3] += L48(4, 8, 1) + L48(5, 2, 2) + L48(6, 2, 1);
	sub[3] += R48(3, 4, 1) + GETKY(4, 1);
	sub[4] += L48(6, 32, 2) + L48(5, 8, 3) + R48(4, 128, 2);
	sub[4] += L48(5, 1, 4) + R48(5, 16, 1) + R48(6, 128, 5);
	sub[4] += GETKY(4, 2) + GETKY(6, 1);
	sub[5] += L48(4, 64, 1) + L48(6, 8, 3) + L48(5, 4, 3);
	sub[5] += R48(5, 64, 2) + R48(6, 64, 3) + R48(4, 16, 2);
	sub[5] += R48(3, 8, 2) + GETKY(3, 1);
	return (sub);
}