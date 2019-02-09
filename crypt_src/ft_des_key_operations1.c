#include "ft_des.h"
#include "ft_crypt_operations.h"

void		create_key(t_crypt_info *crypt_info)
{
	if (!crypt_info->flags.s)
		get_random_salt(crypt_info);
	ft_printf("Salted__%s", crypt_info->flags.salt);
	salt_password(crypt_info);
	get_key_after_salt(crypt_info);
}

void		get_crypt_key(t_crypt_info *crypt_info)
{
	if (crypt_info->flags.k)
		return;
	if (!crypt_info->flags.p)
		get_crypt_password(crypt_info);
	if (!crypt_info->flags.password)
		return;
	create_key(crypt_info);
}

void	get_key_after_salt(t_crypt_info *crypt_info)
{
	unsigned long long	*hold;

	hold = password_hash(crypt_info);
//	revert_eight_bytes((char*)hold, 16);

	//need to free key
	crypt_info->flags.key = (unsigned char*)ft_memalloc(8);
	ft_memcpy(crypt_info->flags.key, hold, 8);
	free(hold);

}

unsigned long long	*password_hash(t_crypt_info *crypt_info)
{
	crypt_info->flags.temp_len = crypt_info->flags.pass_len;
	pad_pass_salt(crypt_info);
	crypt_info->salt_help = (unsigned int *)crypt_info->flags.password;
	return (hash_pass(crypt_info));
}

void				pad_pass_salt(t_crypt_info *crypt_info)
{
	int				diff;
	unsigned char	*buff;
	size_t			tmp;

	buff = ft_memalloc(2);
	ft_memset(buff, 128, 1);
	tmp = crypt_info->flags.pass_len;
	diff = (tmp * 8) % 512;
	ft_memcpy(&crypt_info->flags.password[tmp], buff, 1);
	crypt_info->flags.pass_len++;
	diff += 8;
	while (diff % 512 != 448)
	{
		add_byte(crypt_info);
		diff += 8;
	}
	free(buff);
	block_end(crypt_info);
}

void			add_byte(t_crypt_info *crypt_info)
{
	char	*snew;
	char	*tmp;

	tmp = crypt_info->flags.password;
	crypt_info->flags.pass_len++;
	snew = ft_memalloc(crypt_info->flags.pass_len);
	crypt_info->flags.password = (char *)ft_memcpy(snew,
			crypt_info->flags.password, crypt_info->flags.pass_len - 1);
	free(tmp);
}

void		block_end(t_crypt_info *crypt_info)
{
	char				*tmp;
	char				*ctmp;
	unsigned long long	*max;

	max = ft_memalloc(8);
	*max = 8 * crypt_info->flags.temp_len;
	crypt_info->flags.pass_len += 8;
	tmp = crypt_info->flags.password;
	ctmp = ft_memalloc(crypt_info->flags.pass_len);
	crypt_info->flags.password = ft_memcpy(ctmp, crypt_info->flags.password,
			crypt_info->flags.pass_len - 8);
	ft_memcpy(&crypt_info->flags.password[crypt_info->flags.pass_len - 8], (void*)max, 8);
	free(tmp);
	free(max);
}

unsigned long long	*hash_pass(t_crypt_info *crypt_info)
{
	t_key_help		key_help;
	t_iter			iter;
	unsigned int	ctr;
	size_t			d;

	init_key_help(&key_help);
	init_iter(&iter, &key_help);
	ctr = 0;
	d = 0;
	while (d < crypt_info->flags.pass_len)
	{
		init_iter(&iter, &key_help);
		while (++iter.i < 64)
			whilesalt(&iter, crypt_info, ctr);
		ctr += 16;
		key_help.first += iter.first;
		key_help.second += iter.second;
		key_help.third += iter.third;
		key_help.fourth += iter.fourth;
		d += 64;
	}
	return (handle_pass(key_help));
}

void				init_key_help(t_key_help *key_help)
{
	key_help->first = 0x67452301;
	key_help->second = 0xefcdab89;
	key_help->third = 0x98badcfe;
	key_help->fourth = 0x10325476;
}

void				init_iter(t_iter *iter, t_key_help *key_help)
{
	iter->first = key_help->first;
	iter->second = key_help->second;
	iter->third = key_help->third;
	iter->fourth = key_help->fourth;
	iter->i = -1;
}

void				whilesalt(t_iter *z, t_crypt_info *crypt_info, size_t ctr)
{
	if (z->i <= 15)
	{
		z->fifth = (z->second & z->third) | ((~z->second) & z->fourth);
		z->g = z->i;
	}
	else if (z->i <= 31)
	{
		z->fifth = (z->fourth & z->second) | ((~z->fourth) & z->third);
		z->g = (5 * z->i + 1) % 16;
	}
	else if (z->i <= 47)
	{
		z->fifth = z->second ^ z->third ^ z->fourth;
		z->g = (3 * z->i + 5) % 16;
	}
	else if (z->i <= 63)
	{
		z->fifth = z->third ^ (z->second | (~z->fourth));
		z->g = (7 * z->i) % 16;
	}
	z->fifth = z->fifth + z->first + g_ks[z->i] + crypt_info->salt_help[z->g + ctr];
	z->first = z->fourth;
	z->fourth = z->third;
	z->third = z->second;
	z->second = z->second + ((z->fifth << g_s[z->i]) | (z->fifth >> (32 - g_s[z->i])));
}

unsigned long long	*handle_pass(t_key_help key_help)
{
	unsigned long long	*ret;

	ret = ft_memalloc(sizeof(unsigned long long) * 2);
	ret[0] = key_help.second;
	ret[0] <<= 32;
	ret[0] += key_help.first;
	ret[1] = key_help.fourth;
	ret[1] <<= 32;
	ret[1] += key_help.third;
	return (ret);
}

void		revert_eight_bytes(char *data, size_t len)
{
	size_t	i;

	i = 0;
	if (len % 8 != 0)
	{
		ft_printf("Incorrect byte amount\n");
		exit(0);
	}
	while (i < len)
	{
		revert_bytes(&data[i]);
		i += 8;
	}
}

void		revert_bytes(char *data)
{
	char	tmp[8];

	tmp[0] = data[0];
	tmp[1] = data[1];
	tmp[2] = data[2];
	tmp[3] = data[3];
	tmp[4] = data[4];
	tmp[5] = data[5];
	tmp[6] = data[6];
	tmp[7] = data[7];
	data[7] = tmp[0];
	data[6] = tmp[1];
	data[5] = tmp[2];
	data[4] = tmp[3];
	data[3] = tmp[4];
	data[2] = tmp[5];
	data[1] = tmp[6];
	data[0] = tmp[7];
}