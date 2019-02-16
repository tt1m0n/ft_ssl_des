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
	//revert_eight_bytes((char*)hold, 16);

	//need to free key
	crypt_info->flags.k = 1;
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
